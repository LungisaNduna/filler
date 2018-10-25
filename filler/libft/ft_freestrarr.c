/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrarr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:07:52 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/08 12:00:18 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freestrarr(char **strarr)
{
	int index;

	if (strarr)
	{
		index = 0;
		while (strarr[index])
		{
			free(strarr[index]);
			index++;
		}
		free(strarr);
	}
	strarr = NULL;
}
