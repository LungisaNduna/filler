/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_my_starting_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:05:07 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/06 12:17:55 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_quad(size_t rows, size_t cols, size_t y, size_t x)
{
	if (y <= (rows / 2) && x <= (cols / 2))
		return (1);
	else if (y <= (rows / 2) && x > (cols / 2))
		return (2);
	else if (y > (rows / 2) && x <= (cols / 2))
		return (3);
	else if (y > (rows / 2) && x > (cols / 2))
		return (4);
	else
		return (0);
}

int			find_my_starting_pos(t_round *turn, char player_id)
{
	size_t	rows;
	size_t	cols;

	rows = 0;
	while (turn->board[rows])
	{
		cols = 0;
		while (turn->board[rows][cols])
		{
			if (turn->board[rows][cols] == player_id ||
					turn->board[rows][cols] == player_id - 32)
				return (get_quad(turn->rows, turn->cols, rows, cols));
			cols++;
		}
		rows++;
	}
	return (0);
}
