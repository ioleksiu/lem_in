/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room_in_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 20:37:10 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 20:37:14 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_room_in_path(int size, int *way, int room)
{
	int	i;

	i = 1;
	while (i < size && way[i] != -1)
	{
		if (way[i] == room)
			return (1);
		i++;
	}
	return (0);
}
