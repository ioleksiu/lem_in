#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>//dell me
#include "lem_in.h"

void            swap_start_end(t_rooms *rooms, t_lemin *lem);
int             count_char(char *str, char c);
int             is_digit_str(char *str);

size_t          arr_size(char **str)
{
    char    *p;

    p = *str;
    while(*p)
        p++;
    return (p - *str + 1);
    //returns 2 not 3
}
int is_comment(char *str)
{
    return  ((str[0] == '#' && str[1] != '#') || ft_strnequ(str, "###", 3));
}

int         valid_room(char *str, t_rooms *a, t_lemin *lem)
{
    char    **arr;

    /* IF COMMENT */
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
    if (!strcmp(temp->r_name, str))
        return temp->id;
    while (temp->next)
    {
        temp = temp->next;
        if (!strcmp(temp->r_name, str))
            return temp->id;
    }
    return (-1);
}

int is_link(char *str)
{
    if (strchr(str,'-'))
        return (1);
    return (0);
}

int         is_alnum_str(char *str)
{
    while(*str)
        if (!isalnum(*(str++)))
            return (0);
    return (1);
}


int             find_room(char *room , t_rooms *a)
{
    t_rooms     *temp;

    temp = a;
    if (temp == NULL)
        return (0);
    if (!strcmp(temp->r_name, room))
        return (1);
    while (temp->next)
    {
        temp = temp->next;
        if (!strcmp(temp->r_name, room))
            return (1);
    }
    return (0);//error
}
int         valid_link(char *str, t_rooms *a, t_lemin *lem)
{
    char    **link;

    if (lem->is_link == 0)
        swap_start_end(a, lem);
    lem->is_link = 1;
    link = ft_strsplit(str,'-');
    if (/*arr_size(link) == 2 && */count_char(str,'-') == 1)
        if (is_alnum_str(link[0]) && is_alnum_str(link[1]))
            if (find_room(link[0], a) && find_room(link[1], a) && lem->is_start != 0 && lem->is_end != 0)
                return (1);
    ft_error();
    return (0);//error
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
    a->link_num = NULL;
    a->start_dfs = 1;
    return (a);
}

int  is_digit_str(char *str)
{
    while (*str)
        if (!isdigit(*(str++)))
            return (0);
    return (1);
}

void        ants_number(t_lemin *lem)
{
    char    *str;

    while (get_next_line(0, &str) && !isdigit(str[0]))
    {
        if (!is_comment(str))
        {
            free(str);
            ft_error();
        }
    }
    if (is_digit_str(str))
    {
        lem->n_ants = atoi(str);
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
    if (strchr(str,' '))//valid room
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
    temp->x = atoi(arr[1]);
    temp->y = atoi(arr[2]);
    if (flag == 1)
        lem->start_id = 0;
    if (flag == 2)
        lem->end_id = 0;
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
        temp->next->x = atoi(arr[1]);
        temp->next->y = atoi(arr[2]);
        temp->next->id = id;
        temp->next->next = NULL;
        lem->start_id = (flag == 1) ? id : lem->start_id;
        lem->end_id = (flag == 2) ? id : lem->end_id;
        lem->room_num = id + 1;
        free(str);
    }
    return (rooms);
}

t_rooms        *add_start_room(t_rooms *rooms, t_lemin *lem)
{
    char    *str;

    while (get_next_line(0, &str) && is_comment(str))
    {
        if (!is_comment(str) && !is_room(str, rooms, lem))
            ft_error();
        free(str);
    }
    valid_room(str, rooms,lem);
    return (add_room(str, rooms, lem, 1));

}

t_rooms        *add_end_room(t_rooms *rooms, t_lemin *lem)
{
    char    *str;

    while (get_next_line(0, &str) && is_comment(str))
    {
        if (!is_comment(str) && !is_room(str, rooms, lem))
            ft_error();
        free(str);
    }
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

void         link_num(t_lemin *lem)
{
    int     i;

    i = -1;
    lem->link_num = malloc(lem->room_num * sizeof(int));
    while (++i < lem->n_ants)
        lem->link_num[i] = 0;

}

t_lemin     *add_link(t_lemin *lem, t_rooms *rooms, char *str)
{
    char     **link;
    int      id[2];

    valid_link(str, rooms, lem);
    if (lem->matrix == NULL)
        create_matrix(lem);
    if (lem->link_num == NULL)//
        link_num(lem);        //
    link = ft_strsplit(str,'-');
    id[0] = find_id(rooms, link[0]);
    id[1] = find_id(rooms, link[1]);
    lem->matrix[id[0]][id[1]] = 1;
    lem->matrix[id[1]][id[0]] = 1;
    lem->link_num[id[0]]++;
    lem->link_num[id[1]]++;
    print_matrix(lem);
    return (lem);
}
void            swap_rooms(t_rooms *a, t_rooms *b, int flag)
{
    t_rooms     *c;

    c = malloc(sizeof(t_rooms*));

  //      c->id = a->id;
    c->r_name = a->r_name;
    c->x = a->x;
    c->y = a->y;

  //      a->id = b->id;
    a->r_name = b->r_name;
    a->x = b->x;
    a->y = b->y;

   //     b->id  = c->id;
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
  //  ft_error();
    return (0);
}

void            print_link_num(t_lemin *lem)
{
    int         i;

    i = -1;
    printf("\n Link nums \n");
    while (++i < lem->room_num)
        printf("%d[%d] ",i, lem->link_num[i]);
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

//void        add_dis(t_lemin *lem, int *dis, int room)
//{
//
//}
//void        calc_distance(t_lemin *lem)
//{
//    int     *distance;
//    int     i;
//
//    i = -1;
//    distance = malloc(lem->n_ants * sizeof(int));
//    while (++i < lem->n_ants)
//        distance[i] = 0;
//    i = 0;
//    while(1)
//    {
//        if (lem->link_num[i] >= 2 || ((i == 0 || i == lem->room_num - 1) && ( lem->link_num[i] == 1)))
//
//        break;
//    }
//}


//void    del_rooms_with_one_link(t_lemin *lem)
//{
//
//}
void print_visited(t_lemin *lem, int *arr)
{
    int i;
    i = -1;

    printf("\n");
    while (++i <= lem->room_num - 1)
        printf("[%d]", arr[i]);
    printf("\n");
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

int         is_some_links(t_lemin *lem, int room, int link)
{
    while (link < lem->room_num)
        if (lem->matrix[room][link++] == 1)
            return (1);
    return (0);
}

void    print_w(t_lemin *lem)
{
    int i;

    i = 0;
    printf("\n");
    while (i < lem->room_num && lem->way[i] != -1)
        //if(lem->way[i] == -1)
        printf("[%d]",lem->way[i++]);
    printf("\n");
}
///////////////////////////////////////////////////////////
void        rm_room_link(t_lemin *lem, int room, int link)
{
    int     i;

    i = -1;
    while (++i < lem->room_num && lem->way[i - 1] != link)
        if (lem->way[i] == link)
            lem->way[i] = -1;
    while (i < lem->room_num)
        lem->way[i++] = -1;
}
void        add_cur_room(t_lemin *lem, int room)
{
    int     i;

    i = 0;
    while (lem->way[i] != -1 || lem->way[i] == room)
    {
        i++;
        if (lem->way[i] == room)
            break;
    }
    lem->way[i++] = room;
    while (i < lem->room_num)
        lem->way[i++] = -1;
}

void        add_new_step(t_lemin *lem, int room, int link)
{
    int i;

    i = 0;
    while (i < lem->room_num)
    {
        if (lem->way[i] == room) {
            lem->way[i + 1] = link;
            i += 2;
        }
        else
            i++;
    }
    while (i < lem->room_num)
        lem->way[i++] = -1;

}

void        print_wy(t_lemin *lem)
{
    int     i;

    i = 0;
    printf("\n");
    while (i < lem->room_num /*&& lem->way[i] != -1*/)
        printf("[%d]", lem->way[i++]);
    printf("\n");
}
///////////////////////////////////////////////////////////////
int         last_q(t_lemin *lem)
{
    int     i;

    i = lem->room_num * lem->room_num -1;
    while (lem->queue[i] == -1)
        i--;
    return (lem->queue[i]);
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

    i = lem->room_num - 1;
    while (lem->visited[i] == -1)
        i--;
    if (i >= 0)
        lem->visited[i] = -1;
}

void        del_last_queue(t_lemin *lem)
{
    int     i;

    i = lem->room_num * lem->room_num -1;
    while (lem->queue[i] == -1)
        i--;
    if (i >= 0)
        lem->queue[i] = -1;
}

void        add_visited(t_lemin *lem)
{
    int     i;

    i = 0;
    //find right q
    while (lem->visited[i] != -1)
        i++;
    lem->visited[i] = last_q(lem);
}

//////////////////////////////////////////////////////////////

void        add_q(t_lemin *lem, int q, int v)
{
    int     i;

    i = -1;
    while (++i < lem->room_num)
        if (lem->matrix[v][i] == 1)
            lem->queue[q++] = i;
}

void        add_queue(t_lemin *lem)
{
    int     i;

    i = 0;
    while (lem->queue[i] != -1)
        i++;
    if (i > 0)
        i--;
    add_q(lem, i, last_v(lem));
}

int         can_go(t_lemin *lem, int q, int v)
{
    return (lem->matrix[q][v] == 1);
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

int         is_end_in_queue(t_lemin *lem)
{
    int     i;

    i = -1;
    while (++i < lem->room_num)
        if (lem->queue[i] == lem->room_num - 1)
            return (1);
    return (0);
}

void        print_v(t_lemin *lem)
{
    int     i;

    i = 0;
    printf("\n VISITED: ");
    while (lem->visited[i] != -1)
        printf("[%d]", lem->visited[i++]);
    //printf("\n");
}

void        print_q(t_lemin *lem)
{
    int     i;

    i = 0;
    printf("\n QUEUE: ");
    while (lem->queue[i] != -1)
        printf("[%d]", lem->queue[i++]);
    //printf("\n");
}

int        is_dead_end(t_lemin *lem, int q, int v)
{
    int     i;

    i = -1;
    can_go(lem, last_q(lem), last_v(lem));
    while (++i < lem->room_num - 1)
        if (lem->matrix[q][i] == 1)
            if (!is_visited(lem, i))
                return (1);
    return (0);
    //only one way and it touches start
}

//////////////////////////////////////////////////////////
void         dfs(t_lemin *lem)
{
    int i;
    int ochered[lem->room_num];

    printf("\n\nWHERE AM I: %d\n", last_v(lem));
    add_queue(lem);//add queue
    print_q(lem);
    i = 0;
//    while (lem->queue[0] != -1)
//    {
//        if (is_end_in_queue(lem))
//        {
//            print_v(lem);
//            printf("[%d]", lem->room_num - 1);
//            del_last_queue(lem);
//            print_q(lem);
//          //  return;
//        }
//        if (!can_go(lem, last_q(lem), last_v(lem)))//cant go to Q from V
//        {
//            del_last_visited(lem);
//           // return;
//        }
//        if (is_visited(lem, last_q(lem)))
//        {
//            //del_last_queue(lem);//i we was in Q
//            if (is_end_in_queue(lem))
//            {
//                del_last_queue(lem);
//                dfs(lem);
//            }
//            del_last_queue(lem);
//           // return;
//        }
//        if(can_go(lem, last_q(lem), last_v(lem)) && !is_visited(lem, last_q(lem)))
//            add_visited(lem);
//        else
//        {
//            del_last_visited(lem);
//            del_last_queue(lem);
//        }
//        print_v(lem);
//        dfs(lem);
//    }
//    print_v(lem);
//    printf("\nDA\n");
//    return;
}

///////////////////////////////////////////////////////////

//int     dfs(t_lemin *lem, int room, int step , int link)
//{
//    if (!lem->start_dfs)
//        return (0);
//    if (room == 0 && link == lem->room_num - 1)
//    {
//        lem->start_dfs = 0;
//        return (0);
//    }
//    if (!is_some_links(lem, room, link + 1) && room != 0)
//    {
//        lem->is_visited[room] = 0;
//        dfs(lem, room - 1, step - 1, room);
//    }
//    while (++link <= lem->room_num - 1)
//        if (lem->matrix[room][link] == 1 && lem->is_visited[link] == 0)
//        {
//            lem->is_visited[room] = 1;
//            printf("\n Room [%d]", room);
//             add_cur_room(lem, room);
//         //   print_wy(lem); steps
//            if (link == lem->room_num - 1)
//            {
//                printf("\n Room [%d]", link);
//                lem->is_visited[room] = 0;
//                lem->is_visited[link] = 0;
//                add_new_step(lem, room, link);
//                print_wy(lem);
//                rm_room_link(lem, room, link);
//                dfs(lem, room - 1, step -1, room);
//            }
//            dfs(lem, link, step + 1, 0);
//        }
//    if (!is_some_links(lem, room, link) && room != 0)
//    {
//        lem->is_visited[room] = 0;
//        dfs(lem, room - 1, step - 1, room);
//    }
//    return (0);
//}

void        print_way(t_rooms *rooms, t_lemin *lem)
{
    int     i;

    i = -1;
    printf("[");
    while (lem->way[++i] != -1 && i < lem->room_num)

        printf("%s->", find_room_name(rooms, lem, lem->way[i]));
    printf("%s]\n", find_room_name(rooms, lem, lem->room_num - 1));
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
    dfs(lem);//
    //dfs(lem, 0, 0, 0);
//    print_visited(lem,lem->way);
}
int main()
{
    char        *str;
    t_lemin     *lem;
    t_rooms     *rooms;

    rooms = NULL;
    lem = struct_init();
    ants_number(lem);
    while (get_next_line(0,&str))
    {
        if (ft_strequ(str,"hui")) //DELL ME
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
    print_list(lem,rooms);
    print_matrix(lem);
    print_link_num(lem);
    recursion(lem);
   // print_way(rooms, lem);
    return (0);
}