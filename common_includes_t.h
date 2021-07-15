#ifndef _COMMON_INCLUDES_T_H_
#define _COMMON_INCLUDES_T_H_

#include "smart_pointer_t.h"
#include "status_t.h"
#include "icpp_logger_t.h"
#include "logger_wrapper_t.h"
#include "cpp_logger_build_config_t.h"

//Returning macros

#ifndef RETURN_IF_BAD
#define RETURN_IF_BAD(status) \
        if(status.IsBad())  \
        { \
          CPP_LOG(cpplogger::ICppLogger_t::LOG_LEVEL_WARNING, status.Value());\
          return; \
        }
#endif  //RETURN_IF_BAD

#ifndef RETURN_IF_NULL
#define RETURN_IF_NULL(ptr) \
        if(ptr.IsNull())  \
        { \
          CPP_LOG(cpplogger::ICppLogger_t::LOG_LEVEL_WARNING, BAD_NULL_POINTER);\
          return; \
        }
#endif  //RETURN_IF_NULL

#ifndef RETURN_IF_BAD_OR_NULL
#define RETURN_IF_BAD_OR_NULL(ptr, status) \
        if(ptr.IsNull())  \
        { \
          CPP_LOG(cpplogger::ICppLogger_t::LOG_LEVEL_WARNING, BAD_NULL_POINTER);\
          return; \
        } \
        else if(status.IsBad())\
        { \
          CPP_LOG(cpplogger::ICppLogger_t::LOG_LEVEL_WARNING, status.Value());\
          return; \
        }
#endif  //RETURN_IF_BAD_OR_NULL

//Returning bad status macros

#ifndef RETURN_STATUS_IF_BAD
#define RETURN_STATUS_IF_BAD(status) \
        if(status.IsBad())  \
        { \
          CPP_LOG(cpplogger::ICppLogger_t::LOG_LEVEL_WARNING, status.Value());\
          return status; \
        }
#endif  //RETURN_STATUS_IF_BAD

#ifndef RETURN_STATUS_IF_NULL
#define RETURN_STATUS_IF_NULL(ptr, status) \
        if(ptr.IsNull())  \
        { \
          CPP_LOG(cpplogger::ICppLogger_t::LOG_LEVEL_WARNING, status);\
          return status; \
        }
#endif  //RETURN_STATUS_IF_BAD

#ifndef RETURN_STATUS_IF_BAD_OR_NULL
#define RETURN_STATUS_IF_BAD_OR_NULL(ptr, status) \
        if(ptr.IsNull() || status.IsBad())  \
        { \
          CPP_LOG(cpplogger::ICppLogger_t::LOG_LEVEL_WARNING, status.Value());\
          return status; \
        }
#endif  //RETURN_STATUS_ONLY_IF_BAD

#endif  //_COMMON_INCLUDES_T_H_