/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:03:07 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 21:03:17 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <signal.h>

void			join(t_lemin *lem, char *str2)
{
	char	*res;
	char	*temp;
	int		sum;

	sum = (int)(2 + ft_strlen(lem->input) + ft_strlen(str2));
	temp = lem->input;
	res = (char *)malloc(sum * sizeof(char));
	ft_strcpy(res, lem->input);
	ft_strcat(res, str2);
	ft_strcat(res, "\n");
	free(temp);
	lem->input = res;
}

int				join_input(t_lemin *lem, char *s)
{
	join(lem, s);
	return (1);
}

void			print_input(t_lemin *lem)
{
	ft_putstr(lem->input);
	write(1, "\n", 1);
}

int				main(void)
{
	char		*str;
	t_lemin		*lem;
	t_rooms		*rooms;

	rooms = NULL;
	lem = struct_init();
	ants_number(lem);
	while (get_next_line(0, &str) && join_input(lem, str))
	{
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
	find_ways_and_push_ants(lem, rooms);
	return (0);
}
