# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 15:11:09 by ioleksiu          #+#    #+#              #
#    Updated: 2017/08/16 15:11:14 by ioleksiu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAG = -Wall -Wextra -Werror

DEL = rm -rf

HDR = lem_in.h

PATH = /bin/

SRC =	add_link.c \
		find_id.c \
		ft_remove_redundant_path.c \
		get_next_line.c \
		print_results.c \
		add_q_static.c \
		find_room.c \
		ft_room_in_path.c \
		get_room_by_ant_id.c \
		queue_visit_alloc.c \
		add_room.c \
		find_room_by_id.c \
		ft_room_position.c \
		is_alnum_str.c \
		sort_ways.c \
		add_visited_static.c \
		find_ways_and_push_ants.c \
		ft_strcat.c \
		is_comment.c \
		struct_int.c \
		add_way.c \
		ft_atoi.c \
		ft_strchr.c \
		is_digit_str.c \
		swap_nodes.c \
		ant_number.c \
		ft_bzero.c \
		ft_strcmp.c \
		is_end.c \
		swap_rooms.c \
		count_char.c \
		ft_strdup.c \
		is_link.c \
		swap_start_end.c \
		create_first_way.c  \
 		ft_strequ.c \
		is_room.c \
		valid_link.c \
		create_matrix.c \
		ft_delete_path.c \
		ft_strjoin.c \
		is_start.c \
		valid_room.c \
		create_room_list.c \
		ft_isalnum.c \
		ft_strlen.c \
		is_visited.c \
		visited_arr.c \
		del_last_visited.c \
		ft_isdigit.c \
		ft_strncpy.c \
		last_q_static.c \
		del_q_static.c \
		ft_putchar.c \
		ft_strnequ.c \
		last_v.c \
		dfs.c \
		ft_putnbr.c \
		ft_strnew.c \
		main.c \
		error.c \
		ft_putstr.c \
		ft_strsplit.c \
		muravei_idi.c \
		free.c \
		ft_lstadd.c \
		ft_lstnew.c \
		ft_memmove.c \
		ft_strcpy.c \
		ft_strncat.c \


OBJ =	add_link.o \
		find_id.o \
		ft_remove_redundant_path.o \
		get_next_line.o \
		print_results.o \
		add_q_static.o \
		find_room.o \
		ft_room_in_path.o \
		get_room_by_ant_id.o \
		queue_visit_alloc.o \
		add_room.o \
		find_room_by_id.o \
		ft_room_position.o \
		is_alnum_str.o \
		sort_ways.o \
		add_visited_static.o \
		find_ways_and_push_ants.o \
		ft_strcat.o \
		is_comment.o \
		struct_int.o \
		add_way.o \
		ft_atoi.o \
		ft_strchr.o \
		is_digit_str.o \
		swap_nodes.o \
		ant_number.o \
		ft_bzero.o \
		ft_strcmp.o \
		is_end.o \
		swap_rooms.o \
		count_char.o \
		ft_strdup.o \
		is_link.o \
		swap_start_end.o \
		create_first_way.o  \
		ft_strequ.o \
		is_room.o \
		valid_link.o \
		create_matrix.o \
		ft_delete_path.o \
		ft_strjoin.o \
		is_start.o \
		valid_room.o \
		create_room_list.o \
		ft_isalnum.o \
		ft_strlen.o \
		is_visited.o \
		visited_arr.o \
		del_last_visited.o \
		ft_isdigit.o \
		ft_strncpy.o \
		last_q_static.o \
		del_q_static.o \
		ft_putchar.o \
		ft_strnequ.o \
		last_v.o \
		dfs.o \
		ft_putnbr.o \
		ft_strnew.o \
		main.o \
		error.o \
		ft_putstr.o \
		ft_strsplit.o \
		muravei_idi.o \
		free.o \
		ft_lstadd.o \
		ft_lstnew.o \
		ft_memmove.o \
		ft_strcpy.o \
		ft_strncat.o \

all: $(NAME)

$(NAME) : $(OBJ)
		gcc $(FLAG) $(OBJ) -o $(NAME)

%.o: %.c
		gcc $(FLAG) -c $<

clean:
		$(DEL) $(OBJ)

fclean: clean
		$(DEL) $(NAME)

re: fclean all

rmsh:
		rm *~
		rm \#*
		rm *.out