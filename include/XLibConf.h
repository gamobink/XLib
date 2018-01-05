#ifndef _H_XLIB_CONF_H_
#define _H_XLIB_CONF_H_

#define USE_VCPKG	0

#define USE_SOCKET	1

#define USE_LOG4CXX	0
#if USE_LOG4CXX
#include<log4cxx/logger.h>
#include<log4cxx/propertyconfigurator.h>

#pragma comment(lib,"log4cxx.lib")
#endif//

#define USE_THREADPOOL 1

#define USE_FILE_EX	0


#endif//_H_XLIB_CONF_H_