/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 19:54:42 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 19:54:47 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_room_list(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

t_rooms		*create_room_list(char *str, t_lemin *lem, int flag)
{
	t_rooms	*temp;
	char	**arr;

	arr = ft_strsplit(str, ' ');
	temp = (t_rooms *)malloc(sizeof(t_rooms));
	temp->next = NULL;
	temp->r_name = ft_strdup(arr[0]);
	temp->id = 0;
	temp->x = ft_atoi(arr[1]);
	temp->y = ft_atoi(arr[2]);
	if (flag == 1)
		lem->start_id = 0;
	if (flag == 2)
		lem->end_id = 0;
	temp->ant_num = -1;
	free_room_list(arr);
	return (temp);
}
