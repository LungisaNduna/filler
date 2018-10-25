/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:43:02 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 11:08:14 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*strptr_dst;
	char	*strptr_src;
	size_t	index;
	char	char_to_look_for;

	index = 0;
	strptr_dst = (char *)(dst);
	strptr_src = (char *)(src);
	char_to_look_for = (char)(c);
	while (index < n)
	{
		strptr_dst[index] = strptr_src[index];
		if (strptr_dst[index] == char_to_look_for)
			return (strptr_dst + index + 1);
		index++;
	}
	return (NULL);
}
