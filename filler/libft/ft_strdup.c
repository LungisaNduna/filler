/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 11:41:25 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/25 15:48:14 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	index;
	char	*clone;

	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strnew(0));
	if (!(clone = (char *)malloc(sizeof(char) * (len + 1))) || len == 0)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		clone[index] = s1[index];
		index++;
	}
	clone[index] = '\0';
	return (clone);
}
