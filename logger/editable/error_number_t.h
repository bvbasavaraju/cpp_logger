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

#ifndef _ERROR_NUMBER_T_H_
#define _ERROR_NUMBER_T_H_

#include "ierror_number_t.h"
#include "smart_pointer_t.h"

namespace cpplogger
{

class ErrorNumber_t : public IErrorNumber_t
{

private:
  int64_t errorCode;

public:
  ErrorNumber_t();
  ErrorNumber_t(int64_t val);

  ~ErrorNumber_t();

  bool IsBad(void) const;

  bool IsGood(void) const;

  void Value(int64_t val);
  int64_t Value(void) const;
};  //ErrorNumber_t

} //cpplogger

#endif  //_ERROR_NUMBER_T_H_