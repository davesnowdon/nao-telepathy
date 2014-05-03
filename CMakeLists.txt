cmake_minimum_required(VERSION 2.8)
project(nao-telepathy)

find_package(qibuild)
FIND_LIBRARY(ZMQ_LIB libzmq)

option(TELEPATHY_IS_REMOTE,
       "module is compiled as a remote module (ON or OFF)"
       ON)

set(_srcs
    telepathy.h
    telepathy.cpp
    main.cpp)

if (TELEPATHY_IS_REMOTE)
  add_definitions(" -DTELEPATHY_IS_REMOTE ")
  qi_create_bin(nao-telepathy ${_srcs})
else()
  qi_create_lib(nao-telepathy SHARED ${_srcs} SUBFOLDER naoqi)
endif()

# Add a simple test:
enable_testing()
qi_create_test(test_nao-telepathy "test.cpp")

include_directories(${XMQ_INCLUDE_DIRS})
target_link_libraries(nao-telepathy ${ZMQ_LIBRARIES})
qi_use_lib(nao-telepathy ALCOMMON ALPROXIES)
