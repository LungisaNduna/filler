/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 17:30:51 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/06 13:56:06 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	index;
	long	result;
	int		neg;

	index = 0;
	result = 0;
	neg = 1;
	while (ft_isspace(str[index]))
		index++;
	if (str[index] == '-')
		neg = -1;
	if (str[index] == '+' || str[index] == '-')
		index++;
	while (ft_isdigit(str[index]))
	{
		result = result * 10 + (long)(str[index] - 48);
		index++;
	}
	return (neg * (int)result);
}
