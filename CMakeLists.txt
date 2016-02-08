#set(CMAKE_MAKE_PROGRAM "mingw32-make")
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
#project(HelloWorld C)

add_executable(HelloC hello.c)
add_executable(HelloWord HelloWorld.cpp)
