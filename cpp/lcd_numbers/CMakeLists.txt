cmake_minimum_required(VERSION 2.8.4)
project(lcd_numbers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(LOCAL_INCLUDE_DIR /usr/local/include)
set(LOCAL_LIBRARY_DIR /usr/local/lib)

find_package(Boost COMPONENTS regex REQUIRED)

include_directories(${LOCAL_INCLUDE_DIR})
link_directories(${LOCAL_LIBRARY_DIR})

set(SOURCE_FILES lcd_numbers.cpp)

add_executable(lcd ${SOURCE_FILES})

target_link_libraries( lcd ${Boost_LIBRARIES} gtest gtest_main )
