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

#include "error_code_t.h"

namespace cpplogger
{

/**
 * @brief Status_t class
 * This class can be used as a return type to any member functions.
 * It stores the error code in error number object.
 * Member functions are available to check quality of the status
 */

class Status_t
{
private:
   ErrorCode_t errorNumber;

public:
  Status_t(void);
  Status_t(CPP_LOGGER_ERROR_CODE_TYPE val);
  Status_t(const Status_t& status);
  Status_t(ErrorCode_t val);

  ~Status_t();

  void operator=(Status_t status);

  void operator=(ErrorCode_t val);

  bool operator==(Status_t status);

  bool operator==(ErrorCode_t val);

  bool IsBad(void) const;

  bool IsGood(void) const;

  CPP_LOGGER_ERROR_CODE_TYPE Value(void) const;
};

} //cpplogger

#endif  //_STATUS_T_H_