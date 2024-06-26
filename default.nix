let sources = import ./nix/sources.nix;
in { system ? builtins.currentSystem
   , nixpkgs ? sources.nixpkgs
   , multiversal_src ? if builtins.pathExists ./multiversal/make-multiverse.rb then
       ./multiversal
     else
       sources.multiversal
   , ...
   }:

let
  retroPlatforms = import nix/platforms.nix;

  lib = ((import nixpkgs) { inherit system; }).lib;

  # A Nixpkgs overlay.
  overlay = lib.composeManyExtensions [
    ((import nix/overlay.nix) { inherit multiversal_src; })
    (import nix/universal.nix)
    (import nix/samples.nix)
  ];

  overlaidPkgs = import nixpkgs {
    inherit system;
    overlays = [ overlay ];
  };

  crossPkgs = lib.mapAttrs
    (name: plat:
      import nixpkgs {
        inherit system;
        overlays = [ overlay ];
        crossSystem = plat;
        config = { allowUnsupportedSystem = true; };
      })
    retroPlatforms;
  targetPkgs = lib.mapAttrs (name: cross: cross.buildPackages) crossPkgs;

  shell = lib.mapAttrs
    (name: cross:
      cross.mkShell
        {
          nativeBuildInputs = with overlaidPkgs; [
            retro68.hfsutils
            retro68.tools
            cmake
            gnumake
          ];
          buildInputs = [ cross.retro68.console ];
        } // cross)
    crossPkgs;

in
builtins.trace
  "Warning: Retro68's default.nix is deprecated and will disappear soon. Please use the flake instead."
  (shell.m68k // shell // {
    inherit overlay;
    inherit (overlaidPkgs) retro68;
    targetPkg = targetPkgs;
  })
