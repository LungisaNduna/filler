/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:19:50 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/08 11:59:24 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_pos	*find_trim_dimensions(char **token)
{
	size_t	index_row;
	size_t	count_row;
	char	*nearest_star;
	char	*current_star;

	nearest_star = ft_strchr(token[0], '\0');
	count_row = 0;
	while (token[count_row] && (ft_strchr(token[count_row], '*')) == NULL)
		count_row++;
	index_row = 0;
	while (index_row < ft_count_2dlines(token))
	{
		if ((current_star = ft_strchr(token[index_row], '*')))
		{
			if (ft_strlen(nearest_star) < ft_strlen(current_star))
				nearest_star = current_star;
		}
		index_row++;
	}
	return (create_position((int)(ft_strlen(token[0]) -
					ft_strlen(nearest_star)), (int)count_row));
}

static char		**trim_token(char **or, t_pos *d)
{
	char	**token;
	size_t	rows;

	rows = 0;
	while (or[rows])
		rows++;
	token = (char **)malloc(sizeof(char *) * (rows - d->y + 1));
	rows = 0;
	while (or[rows + d->y])
	{
		token[rows] = ft_strsub(or[rows + d->y], d->x,
				ft_strlen(&or[rows + d->y][d->x]));
		rows++;
	}
	token[rows] = NULL;
	ft_freestrarr(or);
	return (token);
}

static void		add_dimensions_to_moves(t_pos *moves, t_pos *dimensions)
{
	t_pos *temp;

	temp = moves;
	while (temp != NULL)
	{
		temp->x = temp->x - dimensions->x;
		temp->y = temp->y - dimensions->y;
		temp = temp->next;
	}
}

t_pos			*find_move(t_round *turn, t_strat *strat)
{
	t_pos	*moves;
	t_pos	*best_move;

	turn->trim_dim = find_trim_dimensions(turn->token);
	turn->token = trim_token(turn->token, turn->trim_dim);
	if (!(moves = find_all_moves(turn, strat->p_id)))
	{
		free(strat);
		return (NULL);
	}
	add_dimensions_to_moves(moves, turn->trim_dim);
	best_move = find_best_move(turn, moves, strat);
	free(strat);
	free_pos_list(moves);
	ft_freestrarr(turn->board);
	ft_freestrarr(turn->token);
	free_pos_list(turn->trim_dim);
	free(turn);
	return (best_move);
}
