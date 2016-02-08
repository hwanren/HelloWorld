#set(CMAKE_MAKE_PROGRAM "mingw32-make")
set(CMAKE_C_COMPILER "gcc")
project(HelloWorld C)

add_executable(HelloC hello.c)
