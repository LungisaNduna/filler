/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:38:27 by lnduna            #+#    #+#             */
/*   Updated: 2018/07/20 16:40:21 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrarr(char **strarr)
{
	size_t index;

	index = 0;
	while (strarr[index])
	{
		ft_putendl(strarr[index]);
		index++;
	}
}
