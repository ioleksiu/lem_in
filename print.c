/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 14:25:48 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/07/10 14:25:49 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void print_matrix(t_lemin *a)
{
    int         i;
    int         j;

    i = -1;
    printf("\n");
    while(++i < a->room_num)
    {
        j = -1;
        while (++j < a->room_num)
            printf("%d ", a->matrix[i][j]);
        printf("\n");
    }
   // printf("room num: %d", a->room_num);
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