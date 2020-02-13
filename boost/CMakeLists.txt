cmake_minimum_required(VERSION 3.0)

project(boost)





set(BOOST_ROOT "D:\\package\\developer\\boost_1_69_0\\boost")
find_package(Boost)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(s boost_rtree.cpp)


add_executable(s2 boost_rtree_point.cpp)
target_link_libraries(s2 ${Boost_LIBRARIES})


add_executable(near_point near_point.cpp)
target_link_libraries(near_point ${Boost_LIBRARIES})
