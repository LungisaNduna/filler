/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:55:26 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/18 15:10:34 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			cop_position;
	unsigned char	*the_street;
	unsigned char	the_suspect;

	the_suspect = (unsigned char)(c);
	the_street = (unsigned char *)(s);
	cop_position = 0;
	while (cop_position < n)
	{
		if (the_street[cop_position] == the_suspect)
			return ((void *)(the_street + cop_position));
		cop_position++;
	}
	return (NULL);
}
