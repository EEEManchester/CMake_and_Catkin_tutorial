# first line of CMakeLists to indicate the cmake version requriement
cmake_minimum_required(VERSION 3.21.3)

# name the project
project(cmake_2multifiles)

# add a library
# static
#add_library(adder
#            function1.hpp
#            function1.cpp)   

# or dynamic
add_library(adder SHARED
            function1.hpp
            function1.cpp)  

# generate executable file with which cpp file
add_executable(out main.cpp)

# link our target to the adder library
target_link_libraries(out adder)

