/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:00:52 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 17:35:33 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlink;

	if (!(newlink = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(newlink->content = ft_memalloc(content_size)))
			return (NULL);
		newlink->content = ft_memcpy(newlink->content, content, content_size);
		newlink->content_size = content_size;
	}
	else
	{
		newlink->content_size = 0;
		newlink->content = NULL;
	}
	newlink->next = NULL;
	return (newlink);
}
