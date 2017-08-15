/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 19:35:51 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 19:37:48 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ants_number(t_lemin *lem)
{
	char	*s;

	while (get_next_line(0, &s) && join_input(lem, s) && !ft_isdigit(s[0]))
	{
		if (!is_comment(s))
		{
			free(s);
			ft_error();
		}
	}
	if (is_digit_str(s))
	{
		lem->n_ants = ft_atoi(s);
		free(s);
	}
	else
	{
		if (!ft_strequ(s, ""))
			free(s);
		ft_error();
	}
	if (lem->n_ants <= 0)
		ft_error();
}
