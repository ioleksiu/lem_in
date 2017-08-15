/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 20:46:43 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/08/15 20:46:45 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_digit_str(char *str)
{
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (0);
	return (1);
}
