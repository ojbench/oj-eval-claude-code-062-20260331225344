cmake_minimum_required(VERSION 3.10)
project(MemoryRiver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall")

# The OJ expects the executable to be named 'code'
# The OJ will provide a test file (main.cpp or code.cpp)
# MemoryRiver.hpp is a header-only library

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    add_executable(code main.cpp)
elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/code.cpp")
    add_executable(code code.cpp)
endif()
