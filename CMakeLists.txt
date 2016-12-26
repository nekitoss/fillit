cmake_minimum_required(VERSION 3.5)
project(fillit)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES src/main.c)
include_directories("libft/inc/" "inc/")
add_executable(fillit ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(fillit /nfs/2016/m/mvlad/ClionProjects/fillit/libft/libft.a)