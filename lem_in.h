/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:56:58 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/07/18 14:57:07 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define BUFF_SIZE 30
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_rooms
{
	char				*r_name;
	int					id;
	int					x;
	int					y;
	int					ant_num;
	struct s_rooms		*next;
}						t_rooms;

typedef struct			s_gnl
{
	char				*temp;
	int					fd;
	struct s_gnl		*next;
}						t_gnl;

typedef struct			s_ways
{
	int					*way;
	int					way_len;
	struct s_ways		*next;
}						t_ways;

typedef struct			s_lemin
{
	int					n_ants;
	int					start_id;
	int					end_id;
	int					**matrix;
	int					room_num;
	int					is_link;
	int					*is_visited;
	int					*way;
	int					is_start;
	int					is_end;
	int					command;
	int					way_num;
	int					*queue;
	int					*visited;
	t_ways				*ways;
	char				*input;
	int					*is_ant_finished;
	int					pos;
	int					i;
}						t_lemin;

int						get_next_line(const int fd, char **line);
void					ft_bzero(void *s, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strncpy(char *dest, const char *sorc, size_t len);
char					*ft_strnew(size_t size);
size_t					ft_strlen(const char *s);
char					**ft_strsplit(char const *s, char c);
void					ft_error();
int						is_alnum_str(char *str);
int						find_room(char *room, t_rooms *a);
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
int						ft_isalnum(int c);
int						ft_isdigit(int c);
int						ft_atoi(const char *str);
char					*ft_strdup(const char *s1);
int						ft_strcmp(const char *s1, const char *s2);
void					ft_putnbr(int n);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					swap_start_end(t_rooms *rooms, t_lemin *lem);
int						count_char(char *str, char c);
int						is_digit_str(char *str);
int						is_comment(char *str);
void					create_matrix(t_lemin *a);
int						find_id(t_rooms *a, char *str);
int						is_link(char *str);
int						is_alnum_str(char *str);
int						find_room(char *room, t_rooms *a);
int						valid_link(char *str, t_rooms *a, t_lemin *lem);
t_lemin					*struct_init();
int						is_digit_str(char *str);
int						join_input(t_lemin *lem, char *str);
void					ants_number(t_lemin *lem);
int						count_char(char *str, char c);
int						is_room(char *str, t_rooms *rooms, t_lemin *lem);
t_rooms					*create_room_list(char *str, t_lemin *lem, int flag);
t_rooms					*add_room(char *str, t_rooms *rooms, t_lemin *lem,
						int flag);
t_rooms					*add_start_room(t_rooms *rooms, t_lemin *lem);
t_rooms					*add_end_room(t_rooms *rooms, t_lemin *lem);
int						is_start(t_lemin *lem, char *str);
int						is_end(t_lemin *lem, char *str);
t_lemin					*add_link(t_lemin *lem, t_rooms *rooms, char *str);
void					swap_rooms(t_rooms *a, t_rooms *b);
t_rooms					*find_room_by_id(t_rooms *rooms, int id);
void					swap_start_end(t_rooms *rooms, t_lemin *lem);
void					visited_arr(t_lemin *lem);
int						last_v(t_lemin *lem);
void					del_last_visited(t_lemin *lem);
int						last_q_static(int *q);
void					add_visited_static(int *q, t_lemin *lem);
int						is_visited(t_lemin *lem, int q);
void					add_q_static(t_lemin *lem, int *ochered);
void					del_q_static(int *q, int size);
void					create_fist_way(t_lemin *lem);
void					add_way(t_lemin *lem);
void					dfs(t_lemin *lem);
void					queue_visit_alloc(t_lemin *lem);
void					find_ways_and_push_ants(t_lemin *lem, t_rooms *rooms);
void					swap_nodes(t_ways *a, t_ways *b);
void					sort_ways(t_lemin *lem);
void					print_input(t_lemin *lem);
void					ft_delete_path(t_ways **path, t_ways **current);
int						ft_room_in_path(int size, int *way, int room);
void					ft_remove_redundant_path(t_lemin *lem);
t_rooms					*get_room_by_ant_id(t_rooms *rooms, int id);
int						ft_room_position(int *way, int size, int room);
void					print_results(int d, char *s);
void					muravei_idi(t_lemin *lem, t_rooms *rooms);
int						valid_room(char *str, t_rooms *a, t_lemin *lem);
void					*ft_memmove(void *dst, const void *src, size_t len);
t_list					*ft_lstnew(void	const *content, size_t content_size);
void					ft_lstadd(t_list **alst, t_list *new);
char					*ft_strcpy(char *dst, const char *src);
void					free_all(t_lemin *lem, t_rooms *rooms);
void					free_split(char **arr);
char					*ft_strncat(char *s1, const char *s2, size_t n);
char					*ft_strcat(char *s1, const char *s2);
int						ft_strequ(char const *s1, char const *s2);

#endif
