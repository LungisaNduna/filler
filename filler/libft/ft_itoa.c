/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:50:48 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 13:24:11 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*num_as_str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(num_as_str = ft_strnew(1)))
		return (NULL);
	if (n < 0)
		return (ft_strjoin("-", ft_itoa(-n)));
	else if (n > 9)
		num_as_str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else
		num_as_str[0] = (char)(n + 48);
	return (num_as_str);
}
