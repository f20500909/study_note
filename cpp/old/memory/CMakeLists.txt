cmake_minimum_required(VERSION 3.0)
project(main)
#add_compile_options(-std=c++11)
add_compile_options(-std=c++11)
add_compile_options(-fno-elide-constructors)
#add_executable(main MemPool2.cpp)
add_executable(main copy_on_write.cpp)


