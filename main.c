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

int				join_input(t_lemin *lem, char *s)
{
	lem->input = ft_strjoin(lem->input, s);
	lem->input = ft_strjoin(lem->input, "\n");
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
		if (ft_strequ(str, "stop"))
			break ;
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
	(!lem->is_end || !lem->is_start) ? ft_error() : print_input(lem);
	recursion(lem);
	sort_ways(lem);
	ft_remove_redundant_path(lem);
	muravei_idi(lem, rooms);
	return (0);
}
