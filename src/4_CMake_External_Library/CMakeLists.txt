cmake_minimum_required(VERSION 3.21)

project(3ExternalLibs)

# generate main executable
add_executable(out main.cpp)


# add directory of external library
add_subdirectory(external/fastor)

# locate hpp files of external library
target_include_directories(out PUBLIC external/fastor)
# ASK franco
#  target_include_directories(Fastor INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}") does not work   

# link the external library to our executable
target_link_libraries(out Fastor)

