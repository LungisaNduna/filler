/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 16:33:03 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/08 11:59:05 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static size_t	count_empty_rightside_columns(char **original)
{
	size_t	furthest_star;
	size_t	star_length;
	size_t	row_index;

	furthest_star = 1;
	row_index = 0;
	while (original[row_index])
	{
		if (ft_strrchr(original[row_index], '*'))
			star_length = ft_strlen(original[0]) -
				ft_strlen(ft_strrchr(original[row_index], '*') + 1);
		if (star_length > furthest_star)
			furthest_star = star_length + 1;
		row_index++;
	}
	return (furthest_star);
}

static size_t	count_empty_bottomside_rows(char **original)
{
	size_t counter;
	size_t holder;

	counter = 0;
	while (original[counter] && ft_strchr(original[counter], '*') == NULL)
		counter++;
	holder = counter;
	while (original[counter] && ft_strchr(original[counter], '*') != NULL)
		counter++;
	return (counter);
}

static char		**cut_empty_lines(char **original)
{
	size_t	useful_rows;
	size_t	copy_index;
	size_t	useful_cols;
	char	**new_token;

	useful_rows = count_empty_bottomside_rows(original);
	useful_cols = count_empty_rightside_columns(original);
	if (!(new_token = (char **)malloc(sizeof(char *) * (useful_rows + 1))))
		return (NULL);
	copy_index = 0;
	while (copy_index < useful_rows)
	{
		new_token[copy_index] = ft_strsub(original[copy_index], 0, useful_cols);
		copy_index++;
	}
	new_token[copy_index] = NULL;
	ft_freestrarr(original);
	return (new_token);
}

static char		**fill_info(char **input, size_t *index)
{
	char	**grid;
	size_t	g_ind;
	size_t	rows;

	rows = ((size_t)(ft_atoi(ft_strchr(input[*index], ' '))));
	if ((grid = (char **)malloc(sizeof(char *) * (rows + 1))) == NULL)
		return (NULL);
	*index = (*index == 0) ? 2 : *index + 1;
	g_ind = 0;
	while (g_ind < rows)
	{
		if (ft_strchr(input[*index], ' '))
			grid[g_ind] = ft_strdup(ft_strstr(input[*index], " ") + 1);
		else
			grid[g_ind] = ft_strdup(input[*index]);
		if (grid[g_ind] == NULL)
			return (NULL);
		*index = *index + 1;
		g_ind++;
	}
	grid[g_ind] = NULL;
	return (grid);
}

t_round			*look_at_board(t_input *input)
{
	t_round *game;
	size_t	index;

	if ((game = (t_round *)malloc(sizeof(t_round))) == NULL)
		return (NULL);
	index = 0;
	if (!(game->board = fill_info(input->input, &index)) ||
			!(game->token = fill_info(input->input, &index)))
		return (NULL);
	if (!(game->token = cut_empty_lines(game->token)))
		return (NULL);
	game->rows = ft_count_2dlines(game->board);
	game->cols = ft_strlen(game->board[0]);
	ft_freestrarr(input->input);
	free(input);
	return (game);
}
