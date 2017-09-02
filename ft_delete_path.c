/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 20:23:42 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 20:23:46 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_delete_path(t_ways **path, t_ways **current)
{
	t_ways	*prev;
	t_ways	*head;

	head = *path;
	if (head == *current)
	{
		if (head == NULL)
			return ;
		head->way = head->next->way;
		head->next = head->next->next;
		free((*current)->way);
		free((*current));
		return ;
	}
	prev = *path;
	while (prev->next && prev->next != *current)
		prev = prev->next;
	if (prev->next == NULL)
		return ;
	prev->next = prev->next->next;
	free((*current)->way);
	free((*current));
	return ;
}
