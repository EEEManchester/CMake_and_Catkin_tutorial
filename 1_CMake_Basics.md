# Bascis of Cmake
This practice is to show
- how to write a CMakeLists.txt for a C++ project
- how to use cmake to build a project
- how to "hide" the building files from our codes



**Table of Contents**
- [how to write a Cmake file](#how-to-write-a-cmake-file)
- [how to run cmake process](#how-to-run-cmake-process)
- [how to seperate building files](#how-to-seperate-building-files)


## how to write a Cmake file
We write CMakeLists.txt to control compilation and linking process
- what is the basic structure of CMakelists.txt
  - ```cmake_minimum_required()```
    - how to check our cmake version
  - ```project()```
  - ```add_execuable()```
    - *this command is to generate an executable file from a source file like .cpp*

## how to run cmake process
1. run 
   - ```cmake .``` if CMakeLists.txt is in the current dir
   - ```cmake .``` if CMakeLists.txt is in the parent dir 
2. ``` make ```
3. ```./name_executable```

## how to seperate building files
Cmake generate a lot of files during camke and make. 

It is not of our interest to see them at all. Therefore, what we can do is to make them be generated in other folders where we do not need to bother.

We can make organise our folder like this by adding a folder called build.
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
    ----- build
```    

**Solution** is Our purpose is to leave all these building files in the folder build.
1. we entre the buid folder
  - ```cd build```
2. we build the project with cmake
  - ``` cmake .. ``` 
  - this is to say the CMakeLists.txt is in the upper directory            
3. continue with building process
  - ``` make ```
4. run executable  
  - ``` ./out ```

