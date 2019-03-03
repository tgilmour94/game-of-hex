#CMakeLists.txt

cmake_minimum_required (VERSION 2.8)
project (Test)
include_directories("${PROJECT_SOURCE_DIR}")


add_library(Game 
src/UnionFind.cpp 
src/HexGameBoard.cpp 
src/HumanPlayer.cpp
src/MCPlayer.cpp
src/HexGame.cpp )



add_executable(Hex src/main.cpp)
target_link_libraries(Hex Game)

find_package(Threads REQUIRED)
if(THREADS_HAVE_PTHREAD_ARG)
  set_property(TARGET Hex PROPERTY COMPILE_OPTIONS "-pthread")
  set_property(TARGET Hex PROPERTY INTERFACE_COMPILE_OPTIONS "-pthread")
endif()
if(CMAKE_THREAD_LIBS_INIT)
  target_link_libraries(Hex "${CMAKE_THREAD_LIBS_INIT}")
endif()