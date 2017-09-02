/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 18:58:13 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 18:58:20 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rooms		*add_room(char *str, t_rooms *rooms, t_lemin *lem, int flag)
{
	t_rooms	*temp;
	char	**arr;
	int		id;

	if (rooms == NULL)
		return (create_room_list(str, lem, flag));
	id = 1;
	arr = ft_strsplit(str, ' ');
	temp = rooms;
	while (temp->next && id++)
		temp = temp->next;
	temp->next = (t_rooms *)malloc(sizeof(t_rooms));
	temp->next->r_name = ft_strdup(arr[0]);
	temp->next->x = ft_atoi(arr[1]);
	temp->next->y = ft_atoi(arr[2]);
	temp->next->id = id;
	temp->next->next = NULL;
	lem->start_id = (flag == 1) ? id : lem->start_id;
	lem->end_id = (flag == 2) ? id : lem->end_id;
	lem->room_num = id + 1;
	free(str);
	temp->ant_num = -1;
	return (rooms);
}

t_rooms		*add_start_room(t_rooms *rooms, t_lemin *lem)
{
	char	*str;

	while (get_next_line(0, &str) && is_comment(str) && join_input(lem, str))
	{
		if (!is_comment(str) && !is_room(str, rooms, lem))
			ft_error();
		free(str);
	}
	join_input(lem, str);
	valid_room(str, rooms, lem);
	return (add_room(str, rooms, lem, 1));
}

t_rooms		*add_end_room(t_rooms *rooms, t_lemin *lem)
{
	char	*str;

	while (get_next_line(0, &str) && is_comment(str) && join_input(lem, str))
	{
		if (!is_comment(str) && !is_room(str, rooms, lem))
			ft_error();
		free(str);
	}
	join_input(lem, str);
	valid_room(str, rooms, lem);
	return (add_room(str, rooms, lem, 2));
}
