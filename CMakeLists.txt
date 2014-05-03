cmake_minimum_required(VERSION 2.8)
project(nao-telepathy)

find_package(qibuild)

# Create a executable named nao-telepathy
# with the source file: main.cpp
qi_create_bin(nao-telepathy "main.cpp")

# Add a simple test:
enable_testing()
qi_create_test(test_nao-telepathy "test.cpp")
