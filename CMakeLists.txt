PROJECT(video_cap)
CMAKE_MINIMUM_REQUIRED(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 14)
if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)


set(CMAKE_BUILD_TYPE "Release")
set(SRCS 
${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp  
${CMAKE_CURRENT_SOURCE_DIR}/src/include/config.cpp
${CMAKE_CURRENT_SOURCE_DIR}/src/include/config.h
${CMAKE_CURRENT_SOURCE_DIR}/src/include/functions.cpp  
${CMAKE_CURRENT_SOURCE_DIR}/src/include/functions.h
)


#opencv
find_package(OpenCV 4.1 REQUIRED)
message(STATUS ${OpenCV_LIBRARY_DIRS})
#include
include_directories(
      ${OpenCV_INCLUDE_DIRS}      
      ${CMAKE_CURRENT_SOURCE_DIR}/src/include
)


#exe
add_executable(video_cap ${SRCS})


target_link_libraries(video_cap  ${OpenCV_LIBS}  pthread)


