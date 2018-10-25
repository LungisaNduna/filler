/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:00:45 by lnduna            #+#    #+#             */
/*   Updated: 2018/07/20 16:54:15 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return ((char *)s + index);
		index++;
	}
	if (c == '\0' && s[index] == '\0')
		return ((char *)(s + index));
	return (NULL);
}
