/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:03:12 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/19 15:33:05 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t index;

	index = ft_strlen(s);
	while (index != 0)
	{
		if (s[index] == (char)c)
			return ((char *)s + index);
		index--;
	}
	return (NULL);
}
