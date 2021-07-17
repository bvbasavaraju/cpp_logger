cmake_minimum_required(VERSION 3.0)

set(FILES_TO_BUILD
  console_log.cpp
  )

add_executable(console_log ${FILES_TO_BUILD})

target_link_libraries(console_log
  cppl
  )