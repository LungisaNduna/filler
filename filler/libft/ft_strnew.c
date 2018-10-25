/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:12:46 by lnduna            #+#    #+#             */
/*   Updated: 2018/06/26 13:23:34 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newstring;

	if (!(newstring = (char *)ft_memalloc(size + 1)))
		return (NULL);
	ft_bzero((void *)newstring, size + 1);
	return (newstring);
}
