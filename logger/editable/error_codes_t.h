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

#ifndef _ERROR_CODES_T_H_
#define _ERROR_CODES_T_H_

/**
 * @brief Error codes
 * 
 * This file can be edited to add the macro for the error codes
 * As an example few error codes are added here!
 * 
 * Either the error code name or error number can be modified
 * New Error code can be added as well, based on the project requirement
 * 
 * tempate to add new error code is:
 * #define <MACRO FOR ERROR CODE> <CPP_LOGGER_ERROR_CODE_TYPE VALUE OF THE ERROR CODE>
 */

//Error codes can be added here!
#define GOOD                           0
#define BAD                           -1
#define BAD_INVALID_ARGUMENT          -2
#define BAD_NOTHING_TO_DO             -3
#define BAD_MEMORY_ALLOCATION_FAILED  -4
#define BAD_NULL_POINTER              -5

#endif  //_ERROR_CODES_T_H_