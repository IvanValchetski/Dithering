cmake_minimum_required(VERSION 3.2)

<<<<<<< HEAD
project(MainTask)
=======
project(Dithering)
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5

#add_definitions(-O2 -L/usr/X11R6/lib -lm -lpthread -lX11)
add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(src/lib)
<<<<<<< HEAD
#add_subdirectory(include)

target_link_libraries(${PROJECT_NAME} ditlib)
target_link_libraries(${PROJECT_NAME} median)

#install(TARGETS ${PROJECT_NAME} DESTINATION build)
=======

target_link_libraries(${PROJECT_NAME} ditlib)

#install(TARGETS ${PROJECT_NAME} DESTINATION build)
>>>>>>> 9cc79f53eedfc5996ee1c6aa532a73b8a5967ab5
