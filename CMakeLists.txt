cmake_minimum_required(VERSION 3.0)

project(cpp_logger)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Build option selection
set(CPPL_BUILD_MACRO_-_SELECTION "----------- Select the build option(s) -----------" CACHE STRING "Select build option(s)")
option(CPPL_BUILD_MACRO_ENABLE_LOGGING "enable the logging functionality" ON)
option(CPPL_BUILD_MACRO_LOG_WITH_FILE_FUNCTION_LINE_NUMBER "log with filename function name and line number" OFF)
set(CPPL_BUILD_MACRO_ERROR_CODE_TYPE "int64_t" CACHE STRING "Error code type")
set_property(CACHE CPPL_BUILD_MACRO_ERROR_CODE_TYPE PROPERTY STRINGS "int8_t;int16_t;int32_t;int64_t")

#Select Example to build
set(CPPL_EXAMPLE_-_SELECTION "----------- Select the example(s) -----------" CACHE STRING "Select the example(s)")
option(CPPL_EXAMPLE_COSOLE_LOGGING "Console logging example" OFF)
#option(CPPL_EXAMPLE_FILE_LOGGING "File logging example" OFF)
#option(CPPL_EXAMPLE_MQTT_LOGGING "MQTT logging example" OFF)
#option(CPPL_EXAMPLE_UDP_LOGGING "UDP logging example" OFF)


include(CMakeToolsHelpers OPTIONAL)

#Setting the project specific macros

set(CPPL_BUILD_OPTIONS ${CPPL_BUILD_OPTIONS} "CPP_LOGGER_ERROR_CODE_TYPE=${CPPL_BUILD_MACRO_ERROR_CODE_TYPE}")

if (CPPL_BUILD_MACRO_ENABLE_LOGGING)
  set(CPPL_BUILD_OPTIONS ${CPPL_BUILD_OPTIONS} "CPP_LOGGER_ENABLE_LOGGING=1")
else()
  set(CPPL_BUILD_OPTIONS ${CPPL_BUILD_OPTIONS} "CPP_LOGGER_ENABLE_LOGGING=0")
endif()

if (CPPL_BUILD_MACRO_LOG_WITH_FILE_FUNCTION_LINE_NUMBER)
  set(CPPL_BUILD_OPTIONS ${CPPL_BUILD_OPTIONS} "CPP_LOGGER_LOG_WITH_FILE_FUNCTION_LINE_NUMBER=1")
else()
  set(CPPL_BUILD_OPTIONS ${CPPL_BUILD_OPTIONS} "CPP_LOGGER_LOG_WITH_FILE_FUNCTION_LINE_NUMBER=0")
endif()

#Setting CMAKE Variables
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#Sub directories inclusion
add_subdirectory(logger)
add_subdirectory(examples)