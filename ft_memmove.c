/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:42:00 by ioleksiu          #+#    #+#             */
/*   Updated: 2016/12/07 19:05:07 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dstt;
	unsigned char *srcc;

	dstt = (unsigned char*)dst;
	srcc = (unsigned char*)src;
	if (dst > src)
		while (len--)
			dstt[len] = srcc[len];
	else
		while (len--)
			*(dstt++) = *(srcc++);
	return (dst);
}
