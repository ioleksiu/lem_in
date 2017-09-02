/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 20:12:28 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 20:12:34 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_id(t_rooms *a, char *str)
{
	t_rooms	*temp;

	temp = a;
	if (!ft_strcmp(temp->r_name, str))
		return (temp->id);
	while (temp->next)
	{
		temp = temp->next;
		if (!ft_strcmp(temp->r_name, str))
			return (temp->id);
	}
	return (-1);
}
