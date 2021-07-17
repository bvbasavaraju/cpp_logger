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

#include "error_number_t.h"

namespace cpplogger
{

  ErrorNumber_t::ErrorNumber_t()
    : errorCode(0)
  {}

  ErrorNumber_t::ErrorNumber_t(int64_t val)
    : errorCode(val)
  {}

  ErrorNumber_t::~ErrorNumber_t()
  {}

  bool ErrorNumber_t::IsBad(void) const
  {
    return (errorCode != 0);
  }

  bool ErrorNumber_t::IsGood(void) const
  {
    return (errorCode == 0);
  }

  void ErrorNumber_t::Value(int64_t val)
  {
    errorCode = val;
  }

  int64_t ErrorNumber_t::Value(void) const
  {
    return errorCode;
  }

} //cpplogger