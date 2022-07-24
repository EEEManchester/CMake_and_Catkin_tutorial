cmake_minimum_required(VERSION 3.21)

project(4InstallLibs)

# add lib directry
add_subdirectory(function1)

# build main target
add_executable(Tutorail_4InstallLibs 
               main.cpp)
               
# link libg
target_link_libraries(Tutorail_4InstallLibs tutorial_function1)             

# install main application
install(TARGETS Tutorail_4InstallLibs RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

# add CMakeLists for this new package
configure_file(tutorial_function1Config.cmake.in "${PROJECT_BINARY_DIR}/tutorial_function1Config.cmake" @ONLY)

install(FILES "${PROJECT_BINARY_DIR}/tutorial_function1Config.cmake" DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake")