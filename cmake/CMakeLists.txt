cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(WPTLib VERSION 0.2.1 LANGUAGES C CXX)

include_directories(../include) # add include dir

# set C++ flags 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# add sources
set( __SOURCES__ ../src/WPTool.cpp )
                 
# make lib 
add_library( FSTLib STATIC ${__SOURCES__})

# set name and prefix
set_target_properties(WPTLib PROPERTIES OUTPUT_NAME "WPTlib")
set_target_properties(WPTLib PROPERTIES PREFIX "")