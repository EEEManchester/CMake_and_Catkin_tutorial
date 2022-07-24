cmake_minimum_required(VERSION 3.21.3)

project(4InstallLibs_2)

#

# searching for our package
# define searching path for the PackNameConfig.cmake of the package
SET(CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}/lib/cmake")

# search the package
find_package(tutorial_function1 REQUIRED)

# display the searching result
if(tutorial_function1_FOUND)
    message(STATUS "library tutorial_function1 is found")
    message(STATUS "installed library include directory is ${tutorial_function1_INCLUDE_DIRS}")
    message(STATUS "installed library library directory is ${tutorial_function1_LIBRARY_DIRS}") # this is usally not used
    message(STATUS "installed library is ${tutorial_function1_LIBRARIES}")
else()
    message(STATUS "library tutorial_function1 is NOT found")
endif()



add_executable(out main.cpp)


target_link_libraries(out tutorial_function1)