/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:34:38 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/18 14:38:46 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*strptr_b;
	unsigned char	character;
	size_t			index;

	index = 0;
	strptr_b = (unsigned char *)(b);
	character = (unsigned char)(c);
	while (index < len)
	{
		strptr_b[index] = character;
		index++;
	}
	return (b);
}
