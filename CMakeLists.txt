# set the project name
project(test)

# add the executable
add_executable(test 
                test.cpp
                logger_wrapper_t.cpp
                error_codes_t.h
                icpp_logger_t.h
                utilities/smart_pointer_t.h
                utilities/status_t.h
                logger_wrapper_t.h)

target_include_directories(
  test
  PUBLIC
  utilities
)
