ENABLE_TESTING()

cmake_minimum_required(VERSION 3.4)

if(WIN32 AND NOT CYGWIN)
  set(CMAKE_MAKE_PROGRAM "mingw32-make")
endif()
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
project(HelloWorld)

add_executable(HelloC hello.c)
add_executable(HelloWorld HelloWorld.cpp)

add_executable(TestA TestA.cpp A.cpp)
target_link_libraries(TestA -lcppunit)
add_test(NAME "TestA" COMMAND ${MY_PROJECT_SOURCE_DIR}/TestA)
