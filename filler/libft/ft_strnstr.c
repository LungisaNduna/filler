/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:11:52 by lnduna            #+#    #+#             */
/*   Updated: 2018/07/16 15:52:13 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *hay, const char *ndle, size_t len)
{
	size_t index;
	size_t len_needle;

	index = 0;
	len_needle = ft_strlen(ndle);
	if (len_needle == 0)
		return ((char *)hay);
	while (hay[index] && index < len)
	{
		if (hay[index] == ndle[0] && len - index >= len_needle)
		{
			if (ft_strncmp(hay + index, ndle, len_needle) == 0)
				return ((char *)hay + index);
		}
		index++;
	}
	return (NULL);
}
