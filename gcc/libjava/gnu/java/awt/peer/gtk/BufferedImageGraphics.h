
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_peer_gtk_BufferedImageGraphics__
#define __gnu_java_awt_peer_gtk_BufferedImageGraphics__

#pragma interface

#include <gnu/java/awt/peer/gtk/CairoGraphics2D.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace awt
      {
        namespace peer
        {
          namespace gtk
          {
              class BufferedImageGraphics;
              class CairoSurface;
          }
        }
      }
    }
  }
  namespace java
  {
    namespace awt
    {
        class Color;
        class Graphics;
        class GraphicsConfiguration;
        class Image;
        class Shape;
      namespace font
      {
          class GlyphVector;
      }
      namespace geom
      {
          class AffineTransform;
          class Rectangle2D;
      }
      namespace image
      {
          class BufferedImage;
          class ColorModel;
          class ImageObserver;
          class RenderedImage;
      }
    }
  }
}

class gnu::java::awt::peer::gtk::BufferedImageGraphics : public ::gnu::java::awt::peer::gtk::CairoGraphics2D
{

public:
  BufferedImageGraphics(::java::awt::image::BufferedImage *);
public: // actually package-private
  BufferedImageGraphics(::gnu::java::awt::peer::gtk::BufferedImageGraphics *);
private:
  void updateBufferedImage(jint, jint, jint, jint);
public:
  virtual ::java::awt::Graphics * create();
  virtual ::java::awt::GraphicsConfiguration * getDeviceConfiguration();
public: // actually protected
  virtual ::java::awt::geom::Rectangle2D * getRealBounds();
public:
  virtual void copyAreaImpl(jint, jint, jint, jint, jint, jint);
  virtual void draw(::java::awt::Shape *);
  virtual void fill(::java::awt::Shape *);
  virtual void drawRenderedImage(::java::awt::image::RenderedImage *, ::java::awt::geom::AffineTransform *);
public: // actually protected
  virtual jboolean drawImage(::java::awt::Image *, ::java::awt::geom::AffineTransform *, ::java::awt::Color *, ::java::awt::image::ImageObserver *);
public:
  virtual void drawGlyphVector(::java::awt::font::GlyphVector *, jfloat, jfloat);
private:
  jboolean drawComposite(::java::awt::geom::Rectangle2D *, ::java::awt::image::ImageObserver *);
  void createBuffer();
public: // actually protected
  virtual ::java::awt::image::ColorModel * getNativeCM();
  virtual ::java::awt::image::ColorModel * getBufferCM();
private:
  ::java::awt::image::BufferedImage * __attribute__((aligned(__alignof__( ::gnu::java::awt::peer::gtk::CairoGraphics2D)))) image;
  ::java::awt::image::BufferedImage * buffer;
  jint imageWidth;
  jint imageHeight;
public: // actually package-private
  ::gnu::java::awt::peer::gtk::CairoSurface * surface;
  static ::java::util::WeakHashMap * bufferedImages;
private:
  jlong cairo_t;
  jboolean hasFastCM;
  jboolean hasAlpha;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_peer_gtk_BufferedImageGraphics__