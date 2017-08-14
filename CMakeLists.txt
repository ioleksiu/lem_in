cmake_minimum_required(VERSION 3.6)
project(LEM_IN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c get_next_line.c lem_in.h ft_bzero.c ft_strchr.c
        ft_strjoin.c ft_strncpy.c ft_strnew.c ft_strlen.c ft_strcat.c
        ft_strsplit.c ft_counts.c ft_countw.c error.c skip.c list.c print.c ft_strequ.c ft_strnequ.c ft_isalnum.c
        ft_isdigit.c ft_strdup.c)
add_executable(LEM_IN ${SOURCE_FILES})