cmake_minimum_required(VERSION 3.11.0)
project(rs-test)

find_package( OpenCV REQUIRED )
find_package(realsense2 REQUIRED)

#get rid unused variable warning:
set(ignoreMe "${QT_QMAKE_EXECUTABLE}")

FILE(GLOB SRCS "./*.cpp" ".*.h")

include(CheckCXXCompilerFlag)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse3 -Wall -Wextra -Wlogical-op -Wuseless-cast -Wold-style-cast -Wdouble-promotion -Wshadow -Wformat=2  -Wno-missing-field-initializers")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} ${realsense2_LIBRARY})

