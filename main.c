#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>//dell me
#include "filler.h"
/*
#comment
 a
#comment
3
2 5 0
##start
0 1 2
##end
1 9 2
3 5 4
0-2
0-3
2-1
3-1
2-3
 */
typedef struct          s_lemin
{
    int                 n_ants;
    int                 start_id;
    int                 end_id;
}                       t_lemin;

typedef struct          s_rooms
{
    char                *r_name;
    int                 id;
    int                 x;
    int                 y;
    struct s_rooms      *next;
}                       t_rooms;

void ft_error(void)
{
    write(1,"ERROR\n", 6);
    exit(777);
}

void skip()
{
    char    **del;

    get_next_line(1,&del);
    free(del);
}
int is_comment(char *str)
{
    if (str[0] == '#' && str[1] != '#')
        return 1;
    return 0;
}

//void add_new_room(t_rooms *a, t_lemin *l, char *str)
//{
//    t_rooms *d;
//
//    l->id++;
//    d = a;
//    while(d->next)
//        d = d->next;
//    d->r_name = add_name(str);
//    d->x = add_x(str);
//    d->y = add_y(str);
//    d->id = l->id++;
//}

int is_command(char *str)
{
    if (strstr(str,"##start"))
        return 1;
    if (strstr(str,"##end"))
        return 2;
    return 0;
}

t_rooms         *ft_rlist_create(char *str, t_lemin *lem, int com)
{
    t_rooms     *rooms;
    char        **arr ;

    arr = ft_strsplit(str, ' ');

    rooms = (t_rooms*)malloc(sizeof(t_rooms));
    rooms->id = 0;
    rooms->r_name = arr[0];
    rooms->x = atoi(arr[1]);
    rooms->y = atoi(arr[2]);
    rooms->next = NULL;
    if (com == 1 || com == 2)
        (com == 1 ) ? (lem->start_id = 0) : (lem->end_id = 0);
    return (rooms);
}

void            ft_rlist_add(t_rooms *rooms, char *str, t_lemin *lem, int com)
{
    t_rooms     *temp;
    t_rooms     *list;
    char        **arr;
    int         id;

    id = 0;
    if (com == 1 || com == 2)
        get_next_line(0, &str);
    arr = ft_strsplit(str, ' ');
    temp = rooms;
    while (temp->next)//there was Segfault
    {
        temp = temp->next;
        id++;
    }
    list = (t_rooms *)malloc(sizeof(t_rooms));
    temp->next = list;
    list->r_name = arr[0];
    list->x = atoi(arr[1]);
    list->y = atoi(arr[2]);
    list->id = id;
    if (com == 1 || com == 2)
        (com == 1 ) ? (lem->start_id = id) : (lem->end_id = id);


}

void print_list(t_lemin *a, t_rooms *b)
{
    printf("\n--------------------------------------\n");
    printf("start id:%d\n",a->start_id);
    printf("end id:%d\n",a->end_id);
    printf("ants num:%d",a->n_ants);
    printf("\n-----------------ROOMS----------------\n");

    t_rooms *temp;

    temp = b;
    printf("Room name:%s\n",temp->r_name);
    printf("id:%d\n",temp->id);
    printf("x[%d]y[%d]\n",temp->x, temp->y);
    while (temp->next)
    {
        temp = temp->next;
        printf("\n====\n");
        printf("Room name:%s\n",temp->r_name);
        printf("id:%d\n",temp->id);
        printf("x[%d]y[%d]\n",temp->x, temp->y);
    }

}

int valid_room(char *str)
{
    return 1;
}

int main()
{
    char        *str;
    t_lemin     *a;
    t_rooms     *rooms = NULL;
    int         id = 0;

    a = malloc(sizeof(t_lemin));

    while (get_next_line(0,&str) && !isdigit(str[0]))
        if (!is_comment(str))
            ft_error();
    a->n_ants = atoi(str);
  //  fd = open("test",O_RDONLY);
  //  printf("ants num:%s\n", str);
    //ANT DONE
    //DO ROOMS
    while (get_next_line(0,&str))
    {
        if (is_comment(str))
            skip();
        else if (is_command(str))
        {
            if (!rooms)
                rooms = ft_rlist_create(str, a, is_command(str));
            else
                ft_rlist_add(rooms, str, a, is_command(str));
        }
        else
        {
            valid_room(str);
            if (!rooms)
                rooms = ft_rlist_create(str, a, is_command(str));
            else {
                if (strstr(str, "finish"))
                    break ;
                ft_rlist_add(rooms, str, a, is_command(str));
            }
        }
        //print_list(a,rooms);
    }
    print_list(a,rooms);


//    while (get_next_line(0, &str) && (is_comment(str) || is_command(str)))
//        ;
    //scanf(a->n_ants);
  //  while (get_next_line(fd, &str))
  //  {
//        if (is_comment(str))
//            skip();//gnl
//        if (is_command(str) == 1)
//        {
//            add_new_room(r, a,str);
//            a->start_id = id;
//        }
//        if (is_command(str) == 2)
//            a->end_id = id;
//        if (is_command(str) == 3)
//            skip();//gnl
    //}
//   скіпаємо коментарі
//   скіпаємо команди
        //isalnum()
//   записуємо кількість мурашок
//   зчитуємо кімнати в ліст
//   рахуємо кількість кімнат в лісті
    return (0);
}
