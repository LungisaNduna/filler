/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:15:41 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/25 16:12:25 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t len_s1;

	len_s1 = ft_strlen(s1);
	if (ft_strcpy(s1 + len_s1, s2) == NULL)
		return (NULL);
	return (s1);
}
