#include <stdio.h>
#include <stdlib.h>
#include "lem_in.h"

void            swap_start_end(t_rooms *rooms, t_lemin *lem);
int             count_char(char *str, char c);
int             is_digit_str(char *str);

int 	is_comment(char *str)
{
    return  ((str[0] == '#' && str[1] != '#') || ft_strnequ(str, "###", 3));
}

void		muravei_idi(t_lemin *lem, t_rooms *rooms);

int         valid_room(char *str, t_rooms *a, t_lemin *lem)
{
    char    **arr;

    if (lem->is_link)
        ft_error();
    arr = ft_strsplit(str, ' ');
    if (count_char(str, ' ') == 2)
        if (is_alnum_str(arr[0]) && is_alnum_str(arr[1]))
            if (arr[0][0] != 'L' && arr[1][0] != 'L')
                if(is_digit_str(arr[1]) && is_digit_str(arr[2]))
                    if (!find_room(arr[0], a))
                        return (1);
    ft_error();
    return (0);


}

void            create_matrix(t_lemin *a)
{
    int         i;
    int         j;

    i = -1;
    a->matrix = (int**)malloc(sizeof(int *) * a->room_num);
    while (++i < a->room_num)
        a->matrix[i] = (int*)malloc(sizeof(int) * a->room_num);
    i = -1;
    while(++i < a->room_num)
    {
        j = -1;
        while (++j < a->room_num)
            a->matrix[i][j] = 0;
    }
}

int             find_id(t_rooms *a, char *str) {
    t_rooms     *temp;

    temp = a;
    if (!ft_strcmp(temp->r_name, str))
        return temp->id;
    while (temp->next)
    {
        temp = temp->next;
        if (!ft_strcmp(temp->r_name, str))
            return temp->id;
    }
    return (-1);
}

int is_link(char *str)
{
    if (ft_strchr(str,'-'))
        return (1);
    return (0);
}

int         is_alnum_str(char *str)
{
    while(*str)
        if (!ft_isalnum(*str++))
            return (0);
    return (1);
}


int             find_room(char *room , t_rooms *a)
{
    t_rooms     *temp;

    temp = a;
    if (temp == NULL)
        return (0);
    if (!ft_strcmp(temp->r_name, room))
        return (1);
    while (temp->next)
    {
        temp = temp->next;
        if (!ft_strcmp(temp->r_name, room))
            return (1);
    }
    return (0);
}
int         valid_link(char *str, t_rooms *a, t_lemin *lem)
{
    char    **link;

    if (lem->is_link == 0)
        swap_start_end(a, lem);
    lem->is_link = 1;
    link = ft_strsplit(str,'-');
    if (count_char(str,'-') == 1)
        if (is_alnum_str(link[0]) && is_alnum_str(link[1]))
            if (find_room(link[0], a) && find_room(link[1], a) && lem->is_start != 0 && lem->is_end != 0)
                return (1);
    ft_error();
    return (0);
}

t_lemin    *struct_init()
{
    t_lemin *a;

    a = malloc(sizeof(t_lemin));
    a->end_id = -1;
    a->matrix = NULL;
    a->n_ants = 0;
    a->room_num = -1;
    a->start_id = -1;
    a->is_start = 0;
    a->is_end = 0;
    a->is_link = 0;
    a->command = 0;
    a->ways = NULL;
    a->input = NULL;
    a->way_num = 0;
    return (a);
}

int  is_digit_str(char *str)
{
    while (*str)
        if (!ft_isdigit(*(str++)))
            return (0);
    return (1);
}

void        ants_number(t_lemin *lem)
{
    char    *str;

	lem->input = ft_strnew(0);
    while (get_next_line(0, &str) && !ft_isdigit(str[0]))
    {
		lem->input = ft_strjoin(lem->input, str);
		lem->input = ft_strjoin(lem->input, "\n");
        if (!is_comment(str))
        {
            free(str);
            ft_error();
        }
    }
	lem->input = ft_strjoin(lem->input, str);
	lem->input = ft_strjoin(lem->input, "\n");
    if (is_digit_str(str))
    {
        lem->n_ants = ft_atoi(str);
        free(str);
    }
    else
    {
        if (!ft_strequ(str, ""))
            free(str);
        ft_error();
    }
    if (lem->n_ants <= 0)
        ft_error();
}

int     count_char(char *str, char c)
{
    int i;

    i = 0;
    while(*str)
        if (*str++ == c)
            i++;
    return (i);
}

int         is_room(char *str, t_rooms *rooms, t_lemin *lem)
{
    if (ft_strchr(str,' '))
    {
        valid_room(str, rooms, lem);
        return (1);
    }
    return (0);
}

t_rooms    *create_room_list(char *str, t_lemin *lem, int flag)
{
    t_rooms     *temp;
    char        **arr;

    arr = ft_strsplit(str,' ');

    temp = (t_rooms *)malloc(sizeof(t_rooms));
    temp->next = NULL;
    temp->r_name = arr[0];
    temp->id = 0;
    temp->x = ft_atoi(arr[1]);
    temp->y = ft_atoi(arr[2]);
    if (flag == 1)
        lem->start_id = 0;
    if (flag == 2)
        lem->end_id = 0;
    temp->ant_num = -1;
   return (temp);
}

t_rooms        *add_room(char *str, t_rooms *rooms, t_lemin *lem, int flag)
{
    t_rooms     *temp;
    char        **arr;
    int         id;

    if (rooms == NULL)
       rooms = create_room_list(str, lem, flag);
    else
    {
        id = 1;
        arr = ft_strsplit(str, ' ');
        temp = rooms;
        while (temp->next)
        {
            temp = temp->next;
            ++id;
        }
        temp->next = (t_rooms *) malloc(sizeof(t_rooms));
        temp->next->r_name = arr[0];
        temp->next->x = ft_atoi(arr[1]);
        temp->next->y = ft_atoi(arr[2]);
        temp->next->id = id;
        temp->next->next = NULL;
        lem->start_id = (flag == 1) ? id : lem->start_id;
        lem->end_id = (flag == 2) ? id : lem->end_id;
        lem->room_num = id + 1;
        free(str);
        temp->ant_num = -1;
    }
    return (rooms);
}

t_rooms        *add_start_room(t_rooms *rooms, t_lemin *lem)
{
    char    *str;

    while (get_next_line(0, &str) && is_comment(str))
    {
		lem->input = ft_strjoin(lem->input, str);
		lem->input = ft_strjoin(lem->input, "\n");
        if (!is_comment(str) && !is_room(str, rooms, lem))
            ft_error();
        free(str);
    }
	lem->input = ft_strjoin(lem->input, str);
	lem->input = ft_strjoin(lem->input, "\n");
    valid_room(str, rooms,lem);
    return (add_room(str, rooms, lem, 1));

}

t_rooms        *add_end_room(t_rooms *rooms, t_lemin *lem)
{
    char    *str;

    while (get_next_line(0, &str) && is_comment(str))
    {
		lem->input = ft_strjoin(lem->input, str);
		lem->input = ft_strjoin(lem->input, "\n");
        if (!is_comment(str) && !is_room(str, rooms, lem))
            ft_error();
        free(str);
    }
	lem->input = ft_strjoin(lem->input, str);
	lem->input = ft_strjoin(lem->input, "\n");
    valid_room(str, rooms,lem);
    return (add_room(str, rooms, lem, 2));
}

int is_start(t_lemin *lem, char *str)
{
    if (!ft_strequ(str,"##start"))
        return (0);
    lem->is_start = 1;
    free(str);
    return (1);
}

int is_end(t_lemin *lem, char *str)
{
    if (!ft_strequ(str,"##end"))
        return (0);
    lem->is_end = 1;
    free(str);
    return (1);
}

t_lemin     *add_link(t_lemin *lem, t_rooms *rooms, char *str)
{
    char     **link;
    int      id[2];

    valid_link(str, rooms, lem);
    if (lem->matrix == NULL)
        create_matrix(lem);
    link = ft_strsplit(str,'-');
    id[0] = find_id(rooms, link[0]);
    id[1] = find_id(rooms, link[1]);
    lem->matrix[id[0]][id[1]] = 1;
    lem->matrix[id[1]][id[0]] = 1;
    free(link);
    return (lem);
}
void            swap_rooms(t_rooms *a, t_rooms *b, int flag)
{
    t_rooms     *c;

    c = malloc(sizeof(t_rooms*));

    c->r_name = a->r_name;
    c->x = a->x;
    c->y = a->y;

    a->r_name = b->r_name;
    a->x = b->x;
    a->y = b->y;

    b->r_name = c->r_name;
    b->x = c->x;
    b->y = c->y;
}

t_rooms         *find_room_by_id(t_rooms *rooms, int id)
{
    t_rooms     *temp;

    temp = rooms;
    while (temp && temp->id != id)
        temp = temp->next;
    if (temp->id == id)
        return (temp);
    ft_error();
    return (0);
}

char            *find_room_name(t_rooms *rooms, t_lemin *lem, int id)
{
    t_rooms     *temp;

    temp = rooms;
    while (temp && temp->id != id)
        temp = temp->next;
    if (temp->id == id)
        return (temp->r_name);
     return (0);
}

void            swap_start_end(t_rooms *rooms, t_lemin *lem)
{
    t_rooms     *temp;

    temp = rooms;
    if (lem->is_end == 0)
        ft_error();
    swap_rooms(rooms, find_room_by_id(rooms, lem->start_id), 0);
    while (temp->next)
        temp = temp->next;
    swap_rooms(temp, find_room_by_id(rooms, lem->end_id), 1);
    lem->start_id = 0;
    lem->end_id = lem->room_num - 1;
}

void visited_arr(t_lemin *lem)
{
    int i;

    i = -1;
    lem->is_visited = malloc(sizeof(int) * lem->room_num);
    while (++i < lem->room_num)
        lem->is_visited[i] = 0;
    i = -1;
    lem->way = malloc(sizeof(int) * lem->room_num);
    while (++i < lem->room_num)
        lem->way[i] = -1;
}


int         last_v(t_lemin *lem)
{
    int     i;

    i = lem->room_num - 1;
    while (lem->visited[i] == -1)
        i--;
    return (lem->visited[i]);
}

void        del_last_visited(t_lemin *lem)
{
    int     i;

    i = 0;
    if (lem->visited[lem->room_num - 1] != -1)
    {
        lem->visited[lem->room_num - 1] = -1;
        return ;
    }
    while (i < lem->room_num - 1)
    {
        if (lem->visited[i + 1] == -1)
        {
            lem->visited[i] = -1;
            return ;
        }
        i++;
    }
}

int         last_q_static(int *q)
{
    int     i;

    i = -1;
    while (q[++i] != -1)
        ;
    return (q[i - 1]);
}

void        add_visited_static(int *q, t_lemin *lem)
{
    int     i;

    i = -1;
    while (++i < lem->room_num)
        if (lem->visited[i] == -1)
            break ;
    lem->visited[i] = last_q_static(q);
}

int         is_visited(t_lemin *lem, int q)
{
    int     i;

    i = -1;
    while (lem->visited[++i] != -1)
        if (lem->visited[i] == q)
            return (1);
    return (0);
}


void        add_q_static(t_lemin *lem, int  *ochered)
{
    int     v;
    int     i;
    int     count;

    v = last_v(lem);
    i = -1;
    count = -1;
    while (++i < lem->room_num)
        if (lem->matrix[v][i] == 1)
            ochered[++count] = i;
    while(count < lem->room_num)
        ochered[++count] = -1;
}

void        del_q_static(int *q, int size)
{
    int     i;

    i = 0;
    if (q[size - 1] != -1)
    {
        q[size - 1] = -1;
        return ;
    }
    while (i < size - 1)
    {
        if (q[i + 1] == -1)
        {
            q[i] = -1;
            return ;
        }
        i++;
    }
}

void            create_fist_way(t_lemin *lem)
{
    int         i;

    lem->ways = (t_ways*)malloc(sizeof(t_ways));
    lem->ways->way = (int*)malloc(sizeof(int) * lem->room_num);
    lem->ways->next = NULL;
    i = -1;
    lem->ways->way_len = 0;
    while (++i < lem->room_num)
    {
        lem->ways->way[i] = lem->visited[i];
        if (lem->visited[i] != -1)
            lem->ways->way_len++;
    }
}

void            add_way(t_lemin *lem)
{
    t_ways     *tmp;
    int         i;

    tmp = lem->ways;
    if (tmp == NULL)
        create_fist_way(lem);
    else
    {
        tmp = lem->ways;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = (t_ways *) malloc(sizeof(t_ways));
        tmp->next->way = (int *) malloc(sizeof(int) * lem->room_num);
        tmp->next->next = NULL;
        tmp->next->way_len = 0;
        i = -1;
        while (++i < lem->room_num)
        {
            tmp->next->way[i] = lem->visited[i];
            if (tmp->next->way[i] != -1)
                tmp->next->way_len++;
        }
	}
}

void            dfs(t_lemin *lem)
{
    int         ochered[lem->room_num + 1];

    if (last_v(lem) == lem->room_num - 1)
    {
        lem->way_num++;
        add_way(lem);
        del_last_visited(lem);
        del_q_static(ochered, lem->room_num);
        return;
    }
	if (lem->way_num > 2042)
		return;
    add_q_static(lem, ochered);
    while (ochered[0] != -1 && !(ochered[0] == 0 && ochered[1] == -1))
    {
            if (last_q_static(ochered) != -1 && !is_visited(lem, last_q_static(ochered)))
            {
                add_visited_static(ochered, lem);
                del_q_static(ochered, lem->room_num);
                dfs(lem);
            }
            if (is_visited(lem, last_q_static(ochered)))
                del_q_static(ochered, lem->room_num);
    }
    del_last_visited(lem);
}

void        queue_visit_alloc(t_lemin *lem)
{
    int     n;
    int     i;

    i = -1;
    n = lem->room_num * lem->room_num;
    lem->queue = (int *)malloc(sizeof(int) * n);
    while (++i < n)
        lem->queue[i] = -1;
    lem->visited = (int *)malloc(sizeof(int) * lem->room_num);
    lem->visited[0] = 0;
    i = 0;
    while (++i < lem->room_num)
        lem->visited[i] = -1;
}

void recursion(t_lemin *lem)
{
    visited_arr(lem);
    queue_visit_alloc(lem);
    dfs(lem);
}

void        swap_nodes(t_ways *a, t_ways *b)
{
    t_ways  *c;

    c->way_len = a->way_len;
    c->way = a->way;

    a->way_len = b->way_len;
    a->way = b->way;

    b->way_len = c->way_len;
    b->way = c->way;
}
void        sort_ways(t_lemin *lem)
{
    t_ways  *tmp;

    tmp = lem->ways;
    while (tmp->next)
    {
        if (tmp->way_len > tmp->next->way_len)
        {
            swap_nodes(tmp, tmp->next);
            tmp = lem->ways;
        }
        else
            tmp = tmp->next;
    }
}


void		ft_remove_redundant_path(t_lemin *lem, t_rooms *rooms);

int main()
{
    char        *str;
    t_lemin     *lem;
    t_rooms     *rooms;

    rooms = NULL;
    lem = struct_init();
    ants_number(lem);
    while (get_next_line(0, &str))
    {
		lem->input = ft_strjoin(lem->input, str);
		lem->input = ft_strjoin(lem->input, "\n");
        if (ft_strequ(str,"stop")) //DELL ME
            break;
        if (is_comment(str))
            free(str);
        else if (is_room(str, rooms, lem))
            rooms = add_room(str, rooms, lem, 0);
        else if (lem->is_start == 0 && is_start(lem, str))
            rooms = add_start_room(rooms, lem);
        else if (lem->is_end == 0 && is_end(lem, str))
            rooms = add_end_room(rooms, lem);
        else if (is_link(str))
            lem = add_link(lem, rooms, str);
        else
            ft_error();
    }
    if (!lem->is_end || !lem->is_start)
        ft_error();
	lem->rooms = rooms;
    recursion(lem);
	////
	ft_putstr(lem->input);
//	write(1, "\n", 1);
	////
	//printf("\n%s\n", lem->input);
    sort_ways(lem);
	ft_remove_redundant_path(lem, rooms);
	muravei_idi(lem, rooms);
    return (0);
}

void		ft_delete_path(t_ways **path, t_ways **current)
{
	t_ways *prev;
	t_ways *head;

	head = *path;
	if (head == *current)
	{
		if (head == NULL)
			return ;
		head->way = head->next->way;
		head->next = head->next->next;
		free((*current)->way);
		free((*current));
		return ;
	}
	prev = *path;
	while (prev->next && prev->next != *current)
		prev = prev->next;
	if (prev->next == NULL)
		return ;
	prev->next = prev->next->next;
	free((*current)->way);
	free((*current));
	return ;
}

int 		ft_room_in_path(int size, int *way, int room)
{
	int i;

	i = 1;
	while (i < size && way[i] != -1)
	{
		if (way[i] == room)
			return (1);
		i++;
	}
	return (0);
}

void		ft_remove_redundant_path(t_lemin *lem, t_rooms *rooms)
{
	t_ways	*start;
	t_ways	*next;
	int 	i;

	start = lem->ways;
	while (start)
	{
		i = 1;
		while (i < lem->room_num && start->way[i] != -1)
		{
			if (start->way[i] == lem->room_num - 1)
				break ;
			next = start->next;
			if (next == NULL)
				break ;
			while (next)
			{
				if (ft_room_in_path(lem->room_num, next->way, start->way[i]))
					ft_delete_path(&(lem->ways), &(next));
				next = next->next;
			}
			i++;
		}
		start = start->next;
	}

}

t_rooms		*get_room_by_ant_id(t_rooms *rooms, int id)
{
	t_rooms *tmp;

	tmp = rooms;
	while (tmp)
	{
		if (tmp->ant_num == id)
			return (tmp);
		tmp = tmp->next;
	}
	return (rooms);
}

int 		ft_room_position(int *way, int size, int room)
{
	int i;

	i = 0;
	while (i < size && way[i] != -1)
	{
		if (way[i] == room)
			return (i);
		i++;
	}
	return (-1);
}

void		print_results(int d, char *s)
{
	write(1, "L", 1);
	ft_putnbr(d);
	write(1, "-", 1);
	ft_putstr(s);
	write(1, " ", 1);
}

void			muravei_idi(t_lemin *lem, t_rooms *rooms)
{
	int 		ant_num;
	int 		*is_ant_finished;
	int 		i;
	int 		pos;
	t_rooms		*room;
	t_rooms 	*next_room;
	t_ways 		*ways;
	t_rooms 	*temp;

	temp = rooms;
	while (temp)
	{
		temp->ant_num = -1;
		temp = temp->next;
	}
	ant_num = lem->n_ants;
	is_ant_finished = (int*)malloc(sizeof(int) * lem->n_ants);
	i = -1;
	while (++i < lem->n_ants)
		is_ant_finished[i] = 1;
	while (lem->n_ants != 0)
	{
		i = -1;
		while (++i < ant_num)
			if (is_ant_finished[i] == 1)
			{
				ways = lem->ways;
				room = get_room_by_ant_id(rooms, i + 1);
				while (ways)
				{
					pos = ft_room_position(ways->way, lem->room_num, room->id);
					if (pos != -1)
					{
						next_room = find_room_by_id(rooms, ways->way[pos + 1]);
						if (next_room->ant_num == -1)
						{
							room->ant_num = -1;
							if (next_room->id == lem->room_num - 1)
							{
								lem->n_ants--;
								is_ant_finished[i] = 0;
							}
							else
								next_room->ant_num = i + 1;
							print_results(i+1, next_room->r_name);
							break ;
						}
					}
					ways = ways->next;
				}
			}
		write(1, "\n", 1);
	}
}
