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
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
#include <unistd.h>

typedef struct		s_get
{
    char			*rest;
    int				fd;
    struct s_get	*next;
}					t_get;

//typedef struct      s_ways
//{
//    int             *way;
//    struct t_ways   *next;
//}                   t_all_ways;

typedef struct          s_lemin

{
    int                 n_ants;
    int                 start_id;
    int                 end_id;
    int                 **matrix;
    int                 room_num;
    int                 is_link;
    int                 *is_visited;
    int                 *way;
    int                 is_start;
    int                 is_end;
    int                 command;
    int                 *link_num;
    int                 jope;
//    int                 start_dfs;
    int                 *queue;// n * n
    int                 *visited;//n
    //
}                       t_lemin;

typedef struct          s_rooms
{
    char                *r_name;
    int                 id;
    int                 x;
    int                 y;
    struct s_rooms      *next;
}                       t_rooms;

int					get_next_line(const int fd, char **line);
//GNL
void				ft_bzero(void *s, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncpy(char *dest, const char *sorc, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlen(const char *s);
char				**ft_strsplit(char const *s, char c);
int	                ft_countw(const char *s, char sp);
int                 ft_counts(const char *s, char sp);
//lem in
void                skip();
void                ft_error();
void                print_matrix(t_lemin *a);
void                print_list(t_lemin *a, t_rooms *b);
t_rooms             *ft_rlist_create(char *str, t_lemin *lem);
void                ft_rlist_add(t_rooms *rooms, char *str, t_lemin *lem);
int                 is_alnum_str(char *str);
int                 find_room(char *room , t_rooms *a);
int	                ft_strequ(char const *s1, char const *s2);
int                 ft_strnequ(char const *s1, char const *s2, size_t n);

#endif
