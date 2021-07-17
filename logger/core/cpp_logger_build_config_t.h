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

#ifndef _CPP_LOGGER_BUILD_CONFIG_T_H_
#define _CPP_LOGGER_BUILD_CONFIG_T_H_

#include "stdint.h"

#ifndef CPP_LOGGER_ERROR_CODE_TYPE
#define CPP_LOGGER_ERROR_CODE_TYPE int64_t
#endif  //CPP_LOGGER_ERROR_CODE_TYPE

#ifndef CPP_LOGGER_ENABLE_LOGGING
#define CPP_LOGGER_ENABLE_LOGGING 1
#endif //CPP_LOGGER_ENABLE_LOGGING

#ifndef CPP_LOGGER_LOG_WITH_FILE_FUNCTION_LINE_NUMBER
#define CPP_LOGGER_LOG_WITH_FILE_FUNCTION_LINE_NUMBER 0
#endif //CPP_LOGGER_LOG_WITH_FILE_FUNCTION_LINE_NUMBER

#endif  //_CPP_LOGGER_BUILD_CONFIG_T_H_