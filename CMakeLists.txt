cmake_minimum_required(VERSION 3.1)

set(CXX_DISABLE_WERROR 1)
set(CMAKE_CXX_STANDARD 11)

set(PROJECT_NAME VelocityDamperTestController)
set(PROJECT_DESCRIPTION "VelocityDamperTestController")
set(PROJECT_URL "")

project(
  ${PROJECT_NAME}
  LANGUAGES CXX
  VERSION 1.0.0)
include(CTest)
enable_testing()

if(NOT TARGET mc_rtc::mc_control)
  find_package(mc_rtc REQUIRED)
endif()

add_subdirectory(src)

if(BUILD_TESTING)
  add_subdirectory(tests)
endif()

set(AROBASE "@")
configure_file(etc/VelocityDamperTestController.in.yaml
               "${CMAKE_CURRENT_BINARY_DIR}/etc/VelocityDamperTestController.yaml")
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/etc/VelocityDamperTestController.yaml"
        DESTINATION "${MC_CONTROLLER_RUNTIME_INSTALL_PREFIX}/etc")
