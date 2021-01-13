cmake_minimum_required(VERSION 3.11)

project(supladevice)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_BUILD_TYPE Debug)

include_directories(../../src)
include_directories(doubles)

add_subdirectory(../../src/ build)

mark_as_advanced(
BUILD_GMOCK
BUILD_GTEST
)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
  )

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

file(GLOB TEST_SRC
  UptimeTests/*.cpp
  ChannelTests/*cpp
  IoTests/*.cpp
  )

file(GLOB DOUBLE_SRC doubles/*.cpp)

add_executable(supladevicetests ${TEST_SRC} ${DOUBLE_SRC})

target_link_libraries(supladevicetests
  gmock
  gtest
  gtest_main
  supladevicelib
  )

add_test(NAME supladevicetests
  COMMAND supladevicetests)