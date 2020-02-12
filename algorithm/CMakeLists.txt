cmake_minimum_required(VERSION 3.0)

project(algorithm)





set(BOOST_ROOT "D:\\package\\developer\\boost_1_69_0\\boost")
find_package(Boost)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(s boost_rtree.cpp)

# linking

target_link_libraries(s ${Boost_LIBRARIES})
