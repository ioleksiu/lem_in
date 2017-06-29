/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 11:09:08 by ioleksiu          #+#    #+#             */
/*   Updated: 2016/12/29 11:29:49 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_countw(const char *s, char sp)
{
	int	tf;
	int	i;

	tf = 0;
	i = 0;
	while (*s == sp)
		s++;
	while (*s != '\0')
	{
		if (*s != sp)
		{
			tf = 1;
			s++;
		}
		if (*s == sp)
		{
			i += tf;
			s++;
			tf = 0;
		}
	}
	if (*--s == sp)
		return (i);
	return (i + 1);
}
