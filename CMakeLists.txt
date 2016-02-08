#set(CMAKE_MAKE_PROGRAM "mingw32-make")
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
#project(HelloWorld C)
project(HelloWorld)

add_executable(HelloC hello.c)
add_executable(HelloWorld HelloWorld.cpp)

#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules/")
#FIND_PACKAGE(CPPUNIT REQUIRED)
#add_executable(TestA TestA.cpp)
#target_link_libraries(TestA ${DEP_LIBRARIES} cppunit)
#add_test(NAME "TestA" COMMAND ${MY_PROJECT_SOURCE_DIR}/test/TestA)
