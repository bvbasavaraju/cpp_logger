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
#include "error_number_t.h"
#include "common_includes_t.h"

namespace cpplogger
{

Status_t::Status_t(void)
{
  errorNumber = new ErrorNumber_t();
}

Status_t::Status_t(const Status_t& status)
{
  errorNumber.Reset();
  errorNumber = new ErrorNumber_t(status.Value());
}

Status_t::Status_t(int64_t val)
{
  errorNumber.Reset();
  errorNumber = new ErrorNumber_t(val);
}

Status_t::~Status_t()
{
  errorNumber.Reset();
}

void Status_t::operator=(Status_t status)
{
  errorNumber = status.errorNumber;
}

void Status_t::operator=(int64_t val)
{
  RETURN_IF_NULL(errorNumber);

  errorNumber->Value(val);
}

bool Status_t::operator==(Status_t status)
{
  return errorNumber.IsNull() ? true : (errorNumber->Value() == status.Value());
}

bool Status_t::operator==(int64_t val)
{
  return errorNumber.IsNull() ? true : (errorNumber->Value() == val);
}

bool Status_t::IsBad(void) const
{
  return !IsGood();
}

bool Status_t::IsGood(void) const
{
  return errorNumber.IsNull() ? false : errorNumber->IsGood();
}

int64_t Status_t::Value(void) const
{
  return errorNumber.IsNull() ? -1 : errorNumber->Value();
}

} //cpplogger