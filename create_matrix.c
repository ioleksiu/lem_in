/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 19:51:25 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 19:51:32 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		create_matrix(t_lemin *a)
{
	int	i;
	int	j;

	i = -1;
	a->matrix = (int**)malloc(sizeof(int *) * a->room_num);
	while (++i < a->room_num)
		a->matrix[i] = (int*)malloc(sizeof(int) * a->room_num);
	i = -1;
	while (++i < a->room_num)
	{
		j = -1;
		while (++j < a->room_num)
			a->matrix[i][j] = 0;
	}
}
