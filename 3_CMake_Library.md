# CMake locate libraries

This practice is to show
- how to write a CMakeLists to find the libraries created by us

## magage and use libaries in CMakeLists
### organise libraries
In the last tutorial, we showed how to build a library in the root folder and call it in our main function.

Well, in order to get a clean sturcture, we would like to the developed library, or the wheels, in different floders instead of in the root folder. 

For instance, we may put the librarcy in a folder called *function* looking like this

```
  root
    |
    |
    ----- CMakeLists.txt
    |
    |
    ----- main.cppp
    |
    |
    ----- function # to be made as a library
            |
            |
            ----- function1.cpp    
            |
            |
            ----- function1.hpp    
            |
            |
            ----- CMakeLists.txt                        
```  
### C++ linking and CMakeLists
In learning Cmake, we should not forget how a c++ program is complied and linked. 

For example, we have talked a lot of building libraries that are will be linked to our main function during **linking**. This is done by CMake command ```target_link_libraries()```.

Nevertheless, do we still rememeber how our *main.cpp* calls the library?

The answer is **\include "function1.hpp"**. Let us go back to the previous example where library files and main files are in the same folder. 

We know they are in the same folder, thus we call the library in the main.cpp as 
```cpp
#include "function1.hpp"
```

Now, libraries could be placed in different folders, different disks etc. Thus how can we **know the library's address**, or the hpp address, with respect to the *main.cpp*. 

**Solution**

Since we know the relative location of library w.r.t its CMakeLists, we can enable **linking** between library and main fucntion by linking the library CMakeLists and the main CMakeLists.

The linking logic goes in this way

```
lib hpp----->lib CMakeLists----->main CMakeLists----->main.
```

As a consequence, we are able to call this library, by tis hearder file, using this relative location information. 


## locate and use libraries by CMakeLists
Since we have two objectives locate and use libraries, two actions are introduced there:
1. make a **libary CMakeLists** for building the library and storing its address;
2. modify the **main CMakeLists** where to locate the library.


### CMakesLists for library and main
#### For library CMakeLists
We should write it using ```add_library``` as
```cmake
add_library(adder SHARED
            function1.hpp
            function1.cpp)  
```
Then, get the address of library into CMakeLists by
```cmake
target_include_directories(function_name PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
```
which adds the library location information to CMake and can be used by our main function CMakeLists.

#### For main CMakeLists
**main CMakeLists**
The main CMakeLists just needs to find the library CMakeLists. That is all, right?

we add the following command
```cmake
add_subdirectory(function)
```
NOTE: this command should be put before "linking" the library to the corresponding target.
**main.cpp**

```cpp
#include "function1.hpp"
```
shows the relative location of *function1.hpp* w.r.t the **library CMakeList**.

An interesting question: what if we put *function1.hpp* in a folder called include? :).


# Source
Youtuber **vector-of-bool**, How to CMake Good - 1c - Subdirectories and Target Interface Properties, [link](https://www.youtube.com/watch?v=SYgESCQeGJY&list=PLK6MXr8gasrGmIiSuVQXpfFuE1uPT615s&index=8&ab_channel=vector-of-bool).

