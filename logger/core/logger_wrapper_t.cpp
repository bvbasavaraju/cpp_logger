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

#include "logger_wrapper_t.h"
#include "error_codes_t.h"
#include "status_t.h"
#include "common_includes_t.h"

namespace cpplogger
{
SmartPtr_t<ICppLogger_t> LoggerWrapper_t::logger;

LoggerWrapper_t::LoggerWrapper_t()
{}

LoggerWrapper_t::~LoggerWrapper_t()
{
  //As it is Static variable. It's life time is lifetime of the program.
  //So, resetting the of variable is important.
  if(!logger.IsNull())
  {
    logger.Reset();
  }
}

Status_t LoggerWrapper_t::Initialise(SmartPtr_t<ICppLogger_t> logger_)
{
  RETURN_STATUS_IF_NULL(logger_, BAD_INVALID_ARGUMENT);

  logger = logger_;
  return GOOD;
}

void LoggerWrapper_t::LogData(
  ICppLogger_t::LogLevel_t level, 
  ErrorCode_t errorCode,
  uint32_t lineNumber, 
  const char* function, 
  const char* filename,
  const char* logMessage)
{
  RETURN_IF_NULL(logger);

  if(logMessage != 0)
  {
    if(function != 0 && filename != 0)
    {
      logger->LogData(level, errorCode, lineNumber, function, filename, logMessage);
    }
    else if(filename != 0)
    {
      logger->LogData(level, errorCode, lineNumber, filename, logMessage);
    }
    else
    {
      logger->LogData(level, errorCode, logMessage);
    }
  }
  else if(filename != 0 && function != 0)
  {
    logger->LogData(level, errorCode, lineNumber, function, filename, 0);
  }
  else if(filename != 0)
  {
    logger->LogData(level, errorCode, lineNumber, filename);
  }
  else
  {
    logger->LogData(level, errorCode);
  }
}

void LoggerWrapper_t::LogData(
  ICppLogger_t::LogLevel_t level,
  uint32_t lineNumber, 
  const char* function, 
  const char* filename,
  const char* format,
  ...)
{
  RETURN_IF_NULL(logger);

  va_list args;
  va_start(args, format);

  logger->LogData(level, lineNumber, function, filename, format, args);
  va_end(args);
}

Status_t LoggerWrapper_t::Create(
  SmartPtr_t<ICppLogger_t> logger_,
  SmartPtr_t<LoggerWrapper_t>& logWrapper)
{
  RETURN_STATUS_IF_NULL(logger_, BAD_INVALID_ARGUMENT);

  SmartPtr_t<LoggerWrapper_t> logObj = new LoggerWrapper_t();
  RETURN_STATUS_IF_NULL(logObj, BAD_MEMORY_ALLOCATION_FAILED);

  Status_t status = logObj->Initialise(logger_);
  RETURN_STATUS_IF_BAD(status);

  logWrapper = logObj;
  return GOOD;
}

} //cpplogger