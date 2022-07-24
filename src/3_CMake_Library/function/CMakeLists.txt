# or dynamic
add_library(adder SHARED
            function1.hpp
            function1.cpp)  

# 
target_include_directories(adder PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")