cmake_minimum_required(VERSION 3.22)

set (MY_DIRECTORY ${CMAKE_SOURCE_DIR}/include)

set(SOURCE
        main.cpp
        Dog.cpp
        shared_ptr_toy.cpp
        Toy.cpp
        )
set(INCLUDE
        ${MY_DIRECTORY}/shared_ptr_toy.h
        ${MY_DIRECTORY}/Toy.h
        ${MY_DIRECTORY}/Dog.h
        )


add_executable(shared_ptr_toy ${SOURCE} ${INCLUDE})
target_include_directories (shared_ptr_toy PUBLIC ${MY_DIRECTORY})