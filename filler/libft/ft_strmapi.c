/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 17:42:52 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 12:26:01 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*newstring;

	index = 0;
	if (!s || !(newstring = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[index])
	{
		newstring[index] = f(index, s[index]);
		index++;
	}
	return (newstring);
}
