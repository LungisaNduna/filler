/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 17:13:48 by lnduna            #+#    #+#             */
/*   Updated: 2018/07/16 13:50:59 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		free_fd_link(t_store **stores, int fd)
{
	t_store *temp;
	t_store *previous;

	previous = *stores;
	if (previous->fd == fd)
	{
		*stores = previous->next;
		free(previous->content);
		free(previous);
	}
	else
	{
		temp = previous->next;
		while (temp != NULL && temp->fd != fd)
		{
			previous = temp;
			temp = temp->next;
		}
		previous->next = temp->next;
		free(temp->content);
		free(temp);
	}
	return (0);
}

static t_store	*newlink(int fd)
{
	t_store	*link;

	if (!(link = (t_store *)malloc(sizeof(t_store))))
		return (NULL);
	link->fd = fd;
	link->next = NULL;
	if (!(link->content = ft_strdup("")))
		return (NULL);
	return (link);
}

static char		**find_store(t_store **stores, int fd)
{
	t_store *temp;

	temp = *stores;
	while (temp->next != NULL && temp->fd != fd)
		temp = temp->next;
	if (temp->fd == fd)
		return (&temp->content);
	if (!(temp->next = newlink(fd)))
		return (NULL);
	temp = temp->next;
	return (&temp->content);
}

static int		read_lines(int const fd, char **nextline)
{
	char	*buff;
	char	*tempstorage;
	int		bytesread;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	bytesread = read(fd, buff, BUFF_SIZE);
	if (bytesread > 0)
	{
		buff[bytesread] = '\0';
		tempstorage = ft_strjoin(*nextline, buff);
		free(*nextline);
		*nextline = tempstorage;
	}
	free(buff);
	return (bytesread);
}

int				get_next_line(int const fd, char **line)
{
	static t_store	*store = NULL;
	char			**nxln;
	char			*endlinepoint;
	char			*trash;
	int				bytesread;

	if ((!store && !(store = newlink(fd))) || !line || fd < 0 ||
			BUFF_SIZE < 0 || !(nxln = find_store(&store, fd)))
		return (-1);
	while ((endlinepoint = ft_strchr(*nxln, '\n')) == NULL)
	{
		if ((bytesread = read_lines(fd, nxln)) == 0)
		{
			if (ft_strlen(*nxln) == 0)
				return (free_fd_link(&store, fd));
			*nxln = ft_strjoin(*nxln, "\n");
		}
		if (bytesread < 0)
			return (-1);
	}
	*line = ft_strsub(*nxln, 0, ft_strlen(*nxln) - ft_strlen(endlinepoint));
	trash = *nxln;
	*nxln = ft_strdup(endlinepoint + 1);
	free(trash);
	return (1);
}
