/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countstrings_in_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 15:51:34 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/03 12:17:51 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_2dlines(char **strarr)
{
	size_t counter;

	if (!strarr)
		return (0);
	counter = 0;
	while (strarr[counter])
		counter++;
	return (counter);
}
