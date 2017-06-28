#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>//dell me
#include "get_next_line.h"
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
    int                 id;
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
    char    *del;

    get_next_line(1,del);
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

int main()
{
    char        *str;
    t_lemin     *a;
    t_rooms     *r;
    int         id = 0;

    a = malloc(sizeof(t_lemin));

    while (get_next_line(0,&str) && !isdigit(str[0]))
        if (!is_comment(str))
            ft_error();
    a->n_ants = atoi(str);
    printf("ants num:%s\n", str);
    //ANT DONE
    //DO ROOMS
    while (get_next_line(0,&str) && (is_room(str) || is_comment(str) || is_command(str)))



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
