/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:48:43 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 11:54:37 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t dstsize)
{
	size_t	index_s1;
	size_t	index_s2;

	index_s1 = 0;
	index_s2 = 0;
	while (s1[index_s1] && index_s1 < dstsize)
		index_s1++;
	while (s2[index_s2] && (index_s2 + index_s1 + 1) < dstsize)
	{
		s1[index_s1 + index_s2] = s2[index_s2];
		index_s2++;
	}
	if (index_s1 < dstsize)
		s1[index_s1 + index_s2] = '\0';
	return (index_s1 + ft_strlen(s2));
}
