cmake_minimum_required(VERSION 3.2)

project(MainTask)


#add_definitions(-O2 -L/usr/X11R6/lib -lm -lpthread -lX11)
add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(src/lib)
#add_subdirectory(include)

target_link_libraries(${PROJECT_NAME} ditlib)
target_link_libraries(${PROJECT_NAME} median)

#install(TARGETS ${PROJECT_NAME} DESTINATION build)
