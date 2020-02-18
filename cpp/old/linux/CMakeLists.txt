cmake_minimum_required(VERSION 3.0)
project(main)
#add_compile_options(-std=c++11)
add_compile_options(-std=c++11)
add_compile_options(-fno-elide-constructors)
#add_executable(main mmap.cpp)
#add_executable(main ipc_pipe.cpp)
add_executable(main io_select.cpp)
#add_executable(main LRU.cpp)


