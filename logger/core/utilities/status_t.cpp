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

#include "status_t.h"
#include "error_codes_t.h"

namespace cpplogger
{

Status_t::Status_t(void)
  : errorNumber(GOOD)
{}

Status_t::Status_t(CPP_LOGGER_ERROR_CODE_TYPE val)
  : errorNumber(val)
{}

Status_t::Status_t(const Status_t& status)
  : errorNumber(status.Value())
{}

Status_t::Status_t(ErrorCode_t val)
  : errorNumber(val)
{}

Status_t::~Status_t()
{}

void Status_t::operator=(Status_t status)
{
  errorNumber = status.errorNumber;
}

void Status_t::operator=(ErrorCode_t val)
{
  errorNumber = val;
}

bool Status_t::operator==(Status_t status)
{
  return (errorNumber == status.Value());
}

bool Status_t::operator==(ErrorCode_t val)
{
  return (errorNumber == val);
}

bool Status_t::IsBad(void) const
{
  return !IsGood();
}

bool Status_t::IsGood(void) const
{
  return errorNumber.IsGood();
}

CPP_LOGGER_ERROR_CODE_TYPE Status_t::Value(void) const
{
  return errorNumber.Value();
}

} //cpplogger