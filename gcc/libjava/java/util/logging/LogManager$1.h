
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_logging_LogManager$1__
#define __java_util_logging_LogManager$1__

#pragma interface

#include <java/lang/Object.h>

class java::util::logging::LogManager$1 : public ::java::lang::Object
{

public: // actually package-private
  LogManager$1();
public:
  virtual ::java::lang::String * getLoggerLevel(::java::lang::String *);
  virtual ::java::util::List * getLoggerNames();
  virtual ::java::lang::String * getParentLoggerName(::java::lang::String *);
  virtual void setLoggerLevel(::java::lang::String *, ::java::lang::String *);
  static ::java::lang::Class class$;
};

#endif // __java_util_logging_LogManager$1__