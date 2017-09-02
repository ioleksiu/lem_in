/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:59:21 by ioleksiu          #+#    #+#             */
/*   Updated: 2016/12/28 18:50:41 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!(s1 && s2))
		return (NULL);
	if ((p = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		ft_strcat(ft_strcat(p, s1), s2);
	return (p);
}
