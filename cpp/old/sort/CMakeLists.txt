cmake_minimum_required(VERSION 3.0)
project(main)


include_directories(./)
aux_source_directory(./ SOURCE)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -march=native -O3 -pthread -lpthread -Werror ")

find_package(Threads)
add_executable(server ${SOURCE})






add_executable(main shellSort.cpp)
#add_executable(main heapSort.cpp)
#add_executable(main mergeSort.cpp)
#add_executable(main countSort.cpp)
#add_executable(main insertSort.cpp)
#add_executable(main optimize_QSort.cpp)
#add_executable(main sort.cpp)
#add_executable(main quick_sort.cpp)
#add_executable(main mergeSort.cpp)

