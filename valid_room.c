/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 21:21:47 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 21:21:49 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		valid_room(char *str, t_rooms *a, t_lemin *lem)
{
	char	**arr;

	if (lem->is_link)
		ft_error();
	arr = ft_strsplit(str, ' ');
	if (count_char(str, ' ') == 2)
		if (is_alnum_str(arr[0]) && is_alnum_str(arr[1]))
			if (arr[0][0] != 'L' && arr[1][0] != 'L')
				if (is_digit_str(arr[1]) && is_digit_str(arr[2]))
					if (!find_room(arr[0], a))
					{
						free_split(arr);
						return (1);
					}
	ft_error();
	return (0);
}
