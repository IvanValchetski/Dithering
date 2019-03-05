cmake_minimum_required(VERSION 3.2)
#add_library(ditlib SHARED imagedithering.cpp)

list( APPEND CMAKE_MODULE_PATH
    ${PROJECT_SOURCE_DIR}/src/lib/extern
)

find_package( CImg REQUIRED )
list( APPEND PROJ_INCLUDE_DIRS
    ${CImg_INCLUDE_DIRS}
)
list( APPEND
    PROJ_LIBRARY_DIRS
    ${CImg_SYSTEM_LIBS_DIR})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CIMG_CFLAGS}")

link_directories(${CImg_SYSTEM_LIBS_DIR})
include_directories(${CImg_INCLUDE_DIRS})
include_directories(include)

add_library(ditlib SHARED include/pixel.h atkinson.cpp idither.cpp floyd_steinberg.cpp burkes.cpp sierra.cpp ${CImg_INCLUDE_DIRS})
add_library(median SHARED median_cut.cpp include/pixel.h atkinson.cpp idither.cpp floyd_steinberg.cpp burkes.cpp sierra.cpp ${CImg_INCLUDE_DIRS})

target_link_libraries(ditlib ${CImg_SYSTEM_LIBS})
target_link_libraries(median ${CImg_SYSTEM_LIBS})


#target_link_libraries(${PROJECT_NAME}
#	${CImg_SYSTEM_LIBS}
#)
#)

