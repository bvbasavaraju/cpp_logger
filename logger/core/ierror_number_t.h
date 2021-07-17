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

#ifndef _I_ERROR_NUMBER_T_H_
#define _I_ERROR_NUMBER_T_H_

#include "stdint.h"

namespace cpplogger
{

class IErrorNumber_t
{
public:
  virtual ~IErrorNumber_t() {}

  virtual bool IsBad(void) const = 0;

  virtual bool IsGood(void) const = 0;

  virtual void Value(int64_t val) = 0;
  virtual int64_t Value(void) const = 0;
};

} ////cpplogger

#endif  //_I_ERROR_NUMBER_T_H_