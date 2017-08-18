/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleksiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:20:13 by ioleksiu          #+#    #+#             */
/*   Updated: 2017/05/08 15:44:43 by ioleksiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*ft_find_fd(t_list **head, int fd)
{
	t_list		*temp;

	if ((temp = *head))
	{
		while (temp)
		{
			if (fd == (int)temp->content_size)
				return (temp);
			temp = temp->next;
		}
	}
	temp = ft_lstnew("\0", 1);
	temp->content_size = fd;
	ft_lstadd(head, temp);
	return (temp);
}

char			*ft_join_rf(char *temp, char *buf, int len_rf)
{
	char	*del_temp;
	char	*str;

	del_temp = temp;
	str = ft_strnew(ft_strlen(temp) + len_rf);
	ft_strcpy(str, temp);
	ft_strncpy(str + ft_strlen(str), buf, len_rf);
	if (del_temp)
		free(del_temp);
	return (str);
}

int				get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*del_content;
	static t_list	*head = NULL;
	t_list			*item;
	int				rf;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	item = ft_find_fd(&head, fd);
	while (!ft_strchr(item->content, '\n') && (rf = read(fd, buf, BUFF_SIZE)))
		item->content = ft_join_rf(item->content, buf, rf);
	rf = 0;
	while (((char *)item->content)[rf] && ((char *)item->content)[rf] != '\n')
		rf++;
	del_content = item->content;
	*line = ft_strncpy(ft_strnew(rf), item->content, rf);
	if (((char *)item->content)[rf] == '\n')
		rf++;
	item->content = ft_strdup(item->content + rf);
	free(del_content);
	return (rf ? 1 : 0);
}

