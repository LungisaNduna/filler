/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:17:36 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/07 14:06:02 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		valid_move(size_t col, size_t row, t_round *turn, char p_id)
{
	size_t t_r;
	size_t t_c;
	size_t crossover_count;

	t_r = 0;
	crossover_count = 0;
	while (turn->token[t_r])
	{
		t_c = 0;
		while (turn->token[t_r][t_c])
		{
			if (turn->token[t_r][t_c] == '*' &&
					(turn->board[t_r + row][t_c + col] == p_id ||
					turn->board[t_r + row][t_c + col] == p_id - 32))
				crossover_count++;
			else if (turn->token[t_r][t_c] == '*' &&
					turn->board[t_r + row][t_c + col] != '.')
				return (0);
			t_c++;
		}
		t_r++;
	}
	if (crossover_count != 1)
		return (0);
	return (1);
}

static t_pos	*finalize_move_list(t_pos *move_list)
{
	t_pos *final_move_list;

	final_move_list = move_list->next;
	free(move_list);
	return (final_move_list);
}

t_pos			*find_all_moves(t_round *turn, char p_id)
{
	size_t	ind_col;
	size_t	ind_row;
	t_pos	*start_of_moves;
	t_pos	*temp;

	start_of_moves = create_position(0, 0);
	temp = start_of_moves;
	ind_row = 0;
	while (turn->board[ind_row] && ind_row + ft_count_2dlines(turn->token)
			<= turn->rows)
	{
		ind_col = 0;
		while (ind_col + ft_strlen(turn->token[0]) <= ft_strlen(turn->board[0]))
		{
			if (valid_move(ind_col, ind_row, turn, p_id))
			{
				temp->next = create_position(ind_col, ind_row);
				temp = temp->next;
			}
			ind_col++;
		}
		ind_row++;
	}
	return (finalize_move_list(start_of_moves));
}
