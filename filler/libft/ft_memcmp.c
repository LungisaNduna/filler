/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 15:00:12 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 11:44:12 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*strptr_s1;
	unsigned char	*strptr_s2;
	size_t			index;

	index = 0;
	strptr_s1 = (unsigned char *)(s1);
	strptr_s2 = (unsigned char *)(s2);
	while (index < n)
	{
		if (strptr_s1[index] != strptr_s2[index])
			return (strptr_s1[index] - strptr_s2[index]);
		index++;
	}
	return (0);
}
