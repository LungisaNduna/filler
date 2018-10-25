/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:15:23 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 15:38:03 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	end_point;
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (ft_iswhitespace(*str) == 1)
		str++;
	if (*str == '\0')
		return (ft_strdup(""));
	end_point = ft_strlen(str) - 1;
	while (ft_iswhitespace(str[end_point]) == 1)
		end_point--;
	return (ft_strsub(str, 0, end_point + 1));
}
