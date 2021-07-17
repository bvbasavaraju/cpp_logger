cmake_minimum_required(VERSION 3.0)

project(cpp_logger)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Build option selection
set(CPPL_BUILD_-_SELECTION "----------- Select the build option(s) -----------" CACHE STRING "Select build option(s)")
option(CPPL_ENABLE_LOGGING "enable the logging functionality" ON)
option(CPPL_LOG_WITH_FILE_FUNCTION_LINE_NUMBER "log with filename function name and line number" OFF)

#Select Example to build
set(CPPL_EXAMPLE_-_SELECTION "----------- Select the example(s) -----------" CACHE STRING "Select the example(s)")
option(EXAMPLE_COSOLE_LOGGING "Console logging example" OFF)
#option(EXAMPLE_FILE_LOGGING "File logging example" OFF)
#option(EXAMPLE_MQTT_LOGGING "MQTT logging example" OFF)
#option(EXAMPLE_UDP_LOGGING "UDP logging example" OFF)


include(CMakeToolsHelpers OPTIONAL)


if (CPPL_ENABLE_LOGGING)
  set(CPPL_BUILD_OPTIONS ${CPPL_BUILD_OPTIONS} "CPP_LOGGER_ENABLE_LOGGING=1")
else()
  set(CPPL_BUILD_OPTIONS ${CPPL_BUILD_OPTIONS} "CPP_LOGGER_ENABLE_LOGGING=0")
endif()

if (CPPL_LOG_WITH_FILE_FUNCTION_LINE_NUMBER)
  set(CPPL_BUILD_OPTIONS ${CPPL_BUILD_OPTIONS} "CPP_LOGGER_LOG_WITH_FILE_FUNCTION_LINE_NUMBER=1")
else()
  set(CPPL_BUILD_OPTIONS ${CPPL_BUILD_OPTIONS} "CPP_LOGGER_LOG_WITH_FILE_FUNCTION_LINE_NUMBER=0")
endif()


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_subdirectory(logger)
add_subdirectory(examples)