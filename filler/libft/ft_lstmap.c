/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 12:50:30 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 16:11:35 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*tempnew;
	t_list	*newlist;

	if (!lst)
		return (NULL);
	temp = lst->next;
	newlist = f(lst);
	tempnew = newlist;
	while (temp != NULL)
	{
		tempnew->next = f(temp);
		tempnew = tempnew->next;
		temp = temp->next;
	}
	return (newlist);
}
