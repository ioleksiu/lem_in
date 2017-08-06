/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:13:13 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/07/10 15:13:15 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms         *ft_rlist_create(char *str, t_lemin *lem)
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
    if (lem->command == 1 || lem->command == 2)
        (lem->command == 1 ) ? (lem->start_id = 0) : (lem->end_id = 0);
    lem->command = 0;
    return (rooms);
}

void            ft_rlist_add(t_rooms *rooms, char *str, t_lemin *lem)
{
    t_rooms     *temp;
    char        **arr;
    int         id;


    id = 1;
    if (lem->command == 1 || lem->command == 2)//need to add error management
        get_next_line(0, &str);
    /*valid room*/
    arr = ft_strsplit(str, ' ');
    temp = rooms;
    while (temp->next)//there was Segfault
    {
        temp = temp->next;
        ++id;
    }
    temp->next = (t_rooms *)malloc(sizeof(t_rooms));
    temp->next->r_name = arr[0];
    temp->next->x = atoi(arr[1]);
    temp->next->y = atoi(arr[2]);
    temp->next->id = id;
    temp->next->next = NULL;
    if (lem->command == 1 || lem->command == 2)
        (lem->command == 1 ) ? (lem->start_id = id) : (lem->end_id = id);
    lem->room_num = id + 1;
    lem->command = 0;
}