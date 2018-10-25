/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:48:11 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 17:32:31 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*strptr_dst;
	unsigned char	*strptr_src;
	size_t			index;

	strptr_dst = (unsigned char *)(dst);
	strptr_src = (unsigned char *)(src);
	index = 0;
	if (dst < src)
	{
		while (index < len)
		{
			strptr_dst[index] = strptr_src[index];
			index++;
		}
	}
	else
	{
		while (len)
		{
			len--;
			strptr_dst[len] = strptr_src[len];
		}
	}
	return (dst);
}
