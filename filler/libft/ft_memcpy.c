/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:39:00 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 17:33:06 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*strptr_dst;
	unsigned char	*strptr_src;
	size_t			index;

	index = 0;
	strptr_dst = (unsigned char *)(dst);
	strptr_src = (unsigned char *)(src);
	while (index < n)
	{
		strptr_dst[index] = strptr_src[index];
		index++;
	}
	return (dst);
}
