cmake_minimum_required(VERSION 2.8)
project(nao-telepathy)

find_package(qibuild)
find_package(zeromq)

option(IS_REMOTE
       "module is compiled as a remote module (ON or OFF)"
       ON)

set(_srcs
    telepathy.h
    telepathy.cpp
    main.cpp)

if (IS_REMOTE)
  qi_info("Building remote executable")
  add_definitions(" -DTELEPATHY_IS_REMOTE ")
  qi_create_bin(nao-telepathy ${_srcs})
else()
  qi_info("Build on-robot shared library")
  qi_create_lib(nao-telepathy SHARED ${_srcs} SUBFOLDER naoqi)
endif()

# Add a simple test:
enable_testing()
qi_create_test(test_nao-telepathy "test.cpp")

qi_use_lib(nao-telepathy ALCOMMON ALPROXIES zeromq)
