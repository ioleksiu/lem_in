cmake_minimum_required(VERSION 3.6)
project(LEM_IN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
add_link.c                      create_first_way.c              find_id.c                       ft_delete_path.c                ft_room_in_path.c               ft_strjoin.c                    get_room_by_ant_id.c            is_start.c                      muravei_idi.c                   swap_nodes.c
add_q_static.c                  create_matrix.c                 find_room.c                     ft_isalnum.c                    ft_room_position.c              ft_strlen.c                     is_alnum_str.c                  is_visited.c                    swap_rooms.c
add_room.c                      create_room_list.c              find_room_by_id.c               ft_isdigit.c                    ft_strcat.c                     ft_strncpy.c                    is_comment.c                    last_q_static.c                 print_results.c                 swap_start_end.c
add_visited_static.c            del_last_visited.c              ft_atoi.c                       ft_putchar.c                    ft_strchr.c                     ft_strnequ.c                    is_digit_str.c                  last_v.c                        queue_visit_alloc.c             valid_link.c
add_way.c                       del_q_static.c                  ft_bzero.c                      ft_putnbr.c                     ft_strcmp.c                     ft_strnew.c                     is_end.c                                                 recursion.c                     valid_room.c
ant_number.c                    dfs.c                           ft_counts.c                     ft_putstr.c                     ft_strdup.c                     ft_strsplit.c                   is_link.c                       sort_ways.c                     visited_arr.c
count_char.c                    error.c                         ft_countw.c                     ft_remove_redundant_path.c      ft_strequ.c                     get_next_line.c                 is_room.c                       main.c                     struct_int.c
)
add_executable(LEM_IN ${SOURCE_FILES})