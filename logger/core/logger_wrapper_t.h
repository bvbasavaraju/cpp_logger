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

#ifndef _LOGGER_WRAPPER_T_H_
#define _LOGGER_WRAPPER_T_H_

#include "smart_pointer_t.h"
#include "icpp_logger_t.h"

namespace cpplogger
{

/**
 * @brief LoggerWrapper_t class implementation
 * 
 */

class Status_t;
class LoggerWrapper_t
{
private:
  static SmartPtr_t<ICppLogger_t> logger;

  LoggerWrapper_t();

  Status_t Initialise(SmartPtr_t<ICppLogger_t> logger_);

public:
  ~LoggerWrapper_t();

  static void LogData(
    ICppLogger_t::LogLevel_t level, 
    ErrorCode_t errorCode,
    uint32_t lineNumber, 
    const char* function, 
    const char* filename,
    const char* logMessage);

  static void LogData(
    ICppLogger_t::LogLevel_t level,
    uint32_t lineNumber, 
    const char* function, 
    const char* filename,
    const char* format,
    ...);

  static Status_t Create(
    SmartPtr_t<ICppLogger_t> logger_,
    SmartPtr_t<LoggerWrapper_t>& logWrapper);
};
} //cpplogger


#if (CPP_LOGGER_LOG_WITH_FILE_FUNCTION_LINE_NUMBER > 0)

  //Logging with different levels
  #define CPP_LOG(logLevel, errorCode) \
            cpplogger::LoggerWrapper_t::LogData(logLevel, errorCode, __LINE__, __func__, __FILE__, 0);

  #define CPP_LOG_MSG(logLevel, logMessage) \
            cpplogger::LoggerWrapper_t::LogData(logLevel, 0, __LINE__, __func__, __FILE__, logMessage);

  #define CPP_LOG_CODE_AND_MSG(logLevel, errorCode, logMessage) \
            cpplogger::LoggerWrapper_t::LogData(logLevel, errorCode, __LINE__, __func__, __FILE__, logMessage);

  #define CPP_LOG_DATA(logLevel, format, ...) \
            cpplogger::LoggerWrapper_t::LogData(logLevel, __LINE__, __func__, __FILE__, format, __VA_ARGS__);

#elif (CPP_LOGGER_ENABLE_LOGGING > 0)

  //Logging with different levels
  #define CPP_LOG(logLevel, errorCode) \
            cpplogger::LoggerWrapper_t::LogData(logLevel, errorCode, 0, 0, 0, 0)

  #define CPP_LOG_MSG(logLevel, logMessage) \
            cpplogger::LoggerWrapper_t::LogData(logLevel, 0, 0, 0, 0, logMessage)

  #define CPP_LOG_CODE_AND_MSG(logLevel, errorCode, logMessage) \
            cpplogger::LoggerWrapper_t::LogData(logLevel, errorCode, 0, 0, 0, logMessage)

  #define CPP_LOG_DATA(logLevel, format, ...) \
            cpplogger::LoggerWrapper_t::LogData(logLevel, 0, 0, 0, format, __VA_ARGS__);

#else

  //Logging with different levels
  #define CPP_LOG(logLevel, errorCode) 

  #define CPP_LOG_MSG(logLevel, logMessage)

  #define CPP_LOG_CODE_AND_MSG(logLevel, errorCode, logMessage)

  #define CPP_LOG_DATA(logLevel, format, ...)

#endif

//Error logging macros
#define CPP_LOG_ERROR(errorCode) CPP_LOG(cpplogger::ICppLogger_t::LOG_LEVEL_ERROR, errorCode)

#define CPP_LOG_ERROR_MSG(logMessage) CPP_LOG_MSG(cpplogger::ICppLogger_t::LOG_LEVEL_ERROR, logMessage)

#define CPP_LOG_ERROR_CODE_AND_MSG(errorCode, logMessage) CPP_LOG_CODE_AND_MSG(cpplogger::ICppLogger_t::LOG_LEVEL_ERROR, errorCode, logMessage)

#define CPP_LOG_ERROR_DATA(format, ...) CPP_LOG_DATA(cpplogger::ICppLogger_t::LOG_LEVEL_ERROR, format, __VA_ARGS__)

#endif  //_LOGGER_WRAPPER_T_H_