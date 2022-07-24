
#add_library(tutorial_function1 STATIC
#            function1.hpp
#            function1.cpp)

add_library(tutorial_function1 SHARED
            function1.hpp
            function1.cpp)


target_include_directories(tutorial_function1 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

# install library
#install(TARGETS tutorial_function1 ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

install(TARGETS tutorial_function1 LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)


install(FILES function1.hpp DESTINATION ${CMAKE_INSTALL_PREFIX}/include)