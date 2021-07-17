set(CPPL_CORE_HEADER_FILES
  core/utilities/smart_pointer_t.h
  core/utilities/status_t.h

  core/common_includes_t.h
  core/cpp_logger_build_config_t.h
  core/icpp_logger_t.h
  core/ierror_number_t.h
  core/logger_wrapper_t.h
  )

set(CPPL_CORE_SOURCE_FILES
  core/utilities/status_t.cpp
  core/logger_wrapper_t.cpp
  )

set(CPPL_EDITABLE_HEADER_FILES
  editable/error_codes_t.h
  editable/error_number_t.h
  )

set(CPPL_EDITABLE_SOURCE_FILES
  editable/error_number_t.cpp
  )

add_library(cppl
  STATIC
  ${CPPL_CORE_HEADER_FILES}
  ${CPPL_CORE_SOURCE_FILES}
  ${CPPL_EDITABLE_HEADER_FILES}
  ${CPPL_EDITABLE_SOURCE_FILES}
  )

#Add compiler options

#add build options
target_compile_definitions(cppl
  PUBLIC
  ${CPPL_BUILD_OPTIONS}
  )

#files includes paths
target_include_directories(cppl
  PUBLIC
  core
  core/utilities
  editable
  )

#library and headers installation
install(TARGETS cppl 
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib/static
  )

install(FILES
  ${CPPL_CORE_HEADER_FILES}
  ${CPPL_EDITABLE_HEADER_FILES}
  DESTINATION include
  )