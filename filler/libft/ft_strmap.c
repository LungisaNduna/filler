/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:30:12 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 12:25:43 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstring;
	size_t	index;

	index = 0;
	if (!s || !(newstring = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[index])
	{
		newstring[index] = f(s[index]);
		index++;
	}
	return (newstring);
}
