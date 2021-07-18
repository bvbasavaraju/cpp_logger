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

#include "error_code_t.h"
#include "error_codes_t.h"

namespace cpplogger
{

ErrorCode_t::ErrorCode_t()
  : errorCode(GOOD)
{}

ErrorCode_t::ErrorCode_t(const ErrorCode_t& val)
  : errorCode(val.Value())
{}

ErrorCode_t::ErrorCode_t(CPP_LOGGER_ERROR_CODE_TYPE val)
  : errorCode(val)
{}

void ErrorCode_t::operator=(CPP_LOGGER_ERROR_CODE_TYPE val)
{
  errorCode = val;
}

void ErrorCode_t::operator=(ErrorCode_t val)
{
  errorCode = val.errorCode;
}

bool ErrorCode_t::operator==(CPP_LOGGER_ERROR_CODE_TYPE val) const
{
  return (errorCode == val);
}
bool ErrorCode_t::operator==(ErrorCode_t val) const
{
  return (errorCode == val.errorCode);
}

bool ErrorCode_t::IsBad(void) const
{
  return !IsGood();
}

bool ErrorCode_t::IsGood(void) const
{
  return (errorCode == GOOD);
}

void ErrorCode_t::Value(CPP_LOGGER_ERROR_CODE_TYPE val)
{
  errorCode = val;
}

CPP_LOGGER_ERROR_CODE_TYPE ErrorCode_t::Value(void) const
{
  return errorCode;
}

} //cpplogger