/*
  Copyright 2021 Basavaraju B V

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef _COMMON_INCLUDES_T_H_
#define _COMMON_INCLUDES_T_H_

#include "status_t.h"
#include "logger_wrapper_t.h"
#include "cpp_logger_build_config_t.h"
#include "error_codes_t.h"

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

#ifndef RETURN_FALSE_IF_BAD
#define RETURN_FALSE_IF_BAD(status) \
        if(status.IsBad())  \
        { \
          CPP_LOG(cpplogger::ICppLogger_t::LOG_LEVEL_WARNING, status.Value());\
          return false; \
        }
#endif  //RETURN_FALSE_IF_BAD

#ifndef RETURN_FALSE_IF_NULL
#define RETURN_FALSE_IF_NULL(ptr) \
        if(ptr.IsNull())  \
        { \
          CPP_LOG(cpplogger::ICppLogger_t::LOG_LEVEL_WARNING, BAD_NULL_POINTER);\
          return false; \
        }
#endif  //RETURN_FALSE_IF_NULL

#ifndef RETURN_FALSE_IF_BAD_OR_NULL
#define RETURN_FALSE_IF_BAD_OR_NULL(ptr, status) \
        if(ptr.IsNull() || status.IsBad())  \
        { \
          CPP_LOG(cpplogger::ICppLogger_t::LOG_LEVEL_WARNING, status.Value());\
          return false; \
        }
#endif  //RETURN_FALSE_IF_BAD_OR_NULL

#endif  //_COMMON_INCLUDES_T_H_