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

#ifndef _I_CPP_LOGGER_T_H_
#define _I_CPP_LOGGER_T_H_

#include "stdarg.h"
#include "error_code_t.h"

namespace cpplogger
{
  class ICppLogger_t
  {
    public:
      typedef enum
      {
        LOG_LEVEL_INFO      = 0,
        LOG_LEVEL_WARNING   = 1,
        LOG_LEVEL_TRACE     = 2,
        LOG_LEVEL_ERROR     = 3,
        LOG_LEVEL_CRITICAL  = 4,
      }LogLevel_t;

    public:
      virtual ~ICppLogger_t() {}

      virtual void LogData(
        LogLevel_t level,
        ErrorCode_t errorCode) = 0;

      virtual void LogData(
        LogLevel_t level,
        ErrorCode_t errorCode,
        const char* errorMessage) = 0;

      virtual void LogData(
        LogLevel_t level, 
        ErrorCode_t errorCode,
        uint32_t lineNumber, 
        const char* filename) = 0;

      virtual void LogData(
        LogLevel_t level, 
        ErrorCode_t errorCode,
        uint32_t lineNumber, 
        const char* filename,
        const char* errorMessage) = 0;

      virtual void LogData(
        LogLevel_t level, 
        ErrorCode_t errorCode,
        uint32_t lineNumber, 
        const char* function, 
        const char* filename,
        const char* errorMessage) = 0;

      virtual void LogData(
        LogLevel_t level,
        uint32_t lineNumber,
        const char* function,
        const char* filename,
        const char* format,
        va_list& args) = 0;
  };
} //cpplogger

#endif  //_I_CPP_LOGGER_T_H_