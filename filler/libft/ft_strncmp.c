/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:31:56 by lnduna            #+#    #+#             */
/*   Updated: 2018/07/04 11:00:31 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t index;

	index = 0;
	if (!s1 && !s2)
		return (1);
	while (s1[index] == s2[index] && index < n - 1 && (s1[index] || s2[index]))
		index++;
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}
