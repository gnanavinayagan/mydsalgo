cmake_minimum_required(VERSION 3.0)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++") # -std=c++1y probably isn't mandatory
set(CMAKE_CXX_STANDARD 11)

project(DataStructure)

add_executable(mylist_exe
mylist.h
mylist.cpp
config.h)