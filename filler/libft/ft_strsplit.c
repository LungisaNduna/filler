/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:47:23 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/06 10:25:29 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countwords(const char *s, char c)
{
	size_t index;
	size_t counter;

	index = 0;
	counter = 0;
	if (s[index] != c && s[index])
		counter++;
	index++;
	while (s[index] != '\0')
	{
		if (s[index] != c && s[index - 1] == c)
			counter++;
		index++;
	}
	return (counter);
}

static char		*get_next_word(char const *s, size_t *index, char del)
{
	size_t word_len;
	size_t loc_index;

	word_len = 0;
	loc_index = *index;
	while (s[loc_index] == del)
		loc_index++;
	while (s[loc_index + word_len] != del && s[loc_index + word_len] != '\0')
		word_len++;
	*index = loc_index + word_len;
	return (ft_strsub(s, loc_index, word_len));
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array_strings;
	size_t	wordcount;
	size_t	index;
	size_t	array_index;

	if (!s)
		return (NULL);
	array_index = 0;
	index = 0;
	wordcount = countwords(s, c);
	if (!(array_strings = (char **)malloc(sizeof(char *) * (wordcount + 1))))
		return (NULL);
	while (array_index < wordcount)
	{
		array_strings[array_index] = get_next_word(s, &index, c);
		array_index++;
	}
	array_strings[array_index] = NULL;
	return (array_strings);
}
