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

#ifndef _STATUS_T_H_
#define _STATUS_T_H_

#include "stdint.h"

namespace cpplogger
{
  class Status_t
  {
    private:
      int64_t errorCode;

    public:
      Status_t(void)
        : errorCode(0)
      {}

      Status_t(const Status_t& status)
        : errorCode(status.errorCode)
      {}

      Status_t(int64_t val)
        : errorCode(val)
      {}

      void operator=(Status_t status)
      {
        errorCode = status.errorCode;
      }

      void operator=(int64_t val)
      {
        errorCode = val;
      }

      bool operator==(Status_t status)
      {
        return (errorCode == status.errorCode);
      }

      bool operator==(int64_t val)
      {
        return (errorCode == val);
      }

      bool IsBad(void)
      {
        return (errorCode != 0);
      }

      bool IsGood(void)
      {
        return (errorCode == 0);
      }
  };
} //cpplogger

#endif  //_STATUS_T_H_