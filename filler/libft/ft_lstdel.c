/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:36:06 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 16:10:51 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *temp2;

	temp = *alst;
	while (temp != NULL)
	{
		temp2 = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = temp2;
	}
	*alst = NULL;
}
