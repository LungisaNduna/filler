/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:39:26 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 11:19:23 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t index_dst;
	size_t index_src;

	index_dst = 0;
	index_src = 0;
	while (dst[index_dst])
		index_dst++;
	while (src[index_src] && index_src < n)
	{
		dst[index_dst + index_src] = src[index_src];
		index_src++;
	}
	dst[index_src + index_dst] = '\0';
	return (dst);
}
