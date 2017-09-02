/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 20:39:25 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 20:39:30 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_room_position(int *way, int size, int room)
{
	int	i;

	i = 0;
	while (i < size && way[i] != -1)
	{
		if (way[i] == room)
			return (i);
		i++;
	}
	return (-1);
}
