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

#ifndef _ERROR_CODE_T_H_
#define _ERROR_CODE_T_H_

#include "cpp_logger_build_config_t.h"

namespace cpplogger
{

class ErrorCode_t
{
private:
  CPP_LOGGER_ERROR_CODE_TYPE errorCode;

public:
  ErrorCode_t();
  ErrorCode_t(const ErrorCode_t& val);
  ErrorCode_t(CPP_LOGGER_ERROR_CODE_TYPE val);

  void operator=(CPP_LOGGER_ERROR_CODE_TYPE val);
  void operator=(ErrorCode_t val);

  bool operator==(CPP_LOGGER_ERROR_CODE_TYPE val) const;
  bool operator==(ErrorCode_t val) const;

  bool IsBad(void) const;

  bool IsGood(void) const;

  void Value(CPP_LOGGER_ERROR_CODE_TYPE val);
  CPP_LOGGER_ERROR_CODE_TYPE Value(void) const;
};

} //cpplogger

#endif  //_ERROR_CODE_T_H_