/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:07:43 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/20 16:33:46 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*newspace;

	if (!(newspace = (void *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(newspace, size);
	return (newspace);
}
