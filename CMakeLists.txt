cmake_minimum_required(VERSION 3.1.0)
project( rs )

# Save the command line compile commands in the build output
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(REALSENSE realsense2) #supports D4** series

# directories

set (PROJECT_SRC_DIR ./)

# add packages
find_package(PkgConfig REQUIRED)
find_package( OpenCV REQUIRED )

# sources
FILE(GLOB MY_SRC_FILES "./*.cpp" "./*.h" )


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse3 -std=c++11 -pthread")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

IF(CMAKE_BUILD_TYPE STREQUAL Debug)
        set(DEBUG_FLAG 1)
        ADD_DEFINITIONS(-DDEBUG_FLAG=${DEBUG_FLAG})
        MESSAGE( STATUS "DEBUG MODE" )
ENDIF(CMAKE_BUILD_TYPE STREQUAL Debug)

# build program
add_executable( rs ${MY_SRC_FILES}  )

target_link_libraries( rs ${OpenCV_LIBS} ${REALSENSE})


