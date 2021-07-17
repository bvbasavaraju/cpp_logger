cmake_minimum_required(VERSION 3.0)

if (CPPL_EXAMPLE_COSOLE_LOGGING)
  add_subdirectory(console_log)
endif()

##if (CPPL_EXAMPLE_FILE_LOGGING)
##  add_subdirectory(file_log)
##endif()

##if (CPPL_EXAMPLE_MQTT_LOGGING)
##  add_subdirectory(mqtt_log)
##endif()

##if (CPPL_EXAMPLE_UDP_LOGGING)
##  add_subdirectory(udp_log)
##endif()