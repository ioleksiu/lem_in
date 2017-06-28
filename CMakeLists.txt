cmake_minimum_required(VERSION 3.6)
project(LEM_IN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c get_next_line.c filler.h ft_bzero.c ft_strchr.c
        ft_strjoin.c ft_strncpy.c ft_strnew.c ft_strlen.c ft_strcat.c)
add_executable(LEM_IN ${SOURCE_FILES})