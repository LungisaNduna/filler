/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_phase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 15:35:44 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/07 14:30:40 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	find_phase_base_1(char **board, char player_id, int *danger)
{
	int			row;
	int			col;

	row = 0;
	col = ft_strlen(board[0]);
	while (board[row] && board[row][col] != player_id)
		row++;
	while (col >= 0 && board[0][col] != player_id)
		col--;
	if (col > -1 && row < (int)ft_count_2dlines(board) && *danger != 1)
		return (1);
	row = 0;
	while (board[row] && board[row][0] != player_id)
		row++;
	if (row >= (int)ft_count_2dlines(board) && *danger == 1)
		*danger = 2;
	if (row == -1)
		return (2);
	else
		return (3);
}

static int	find_phase_base_2(char **board, char player_id, int *danger)
{
	int			row;
	int			col;

	row = ft_count_2dlines(board) - 1;
	col = ft_strlen(board[0]) - 1;
	while (col >= 0 && board[row][col] != player_id)
		col--;
	while (row >= 0 && board[row][0] != player_id)
		row--;
	if (row > -1 && col > -1 && *danger != 1)
		return (1);
	row = ft_count_2dlines(board) - 1;
	col = ft_strlen(board[row]) - 1;
	while (row >= 0 && board[row][col] != player_id)
		row--;
	if (row != -1 && *danger == 1)
		*danger = 2;
	if (row == -1)
		return (2);
	else
		return (3);
}

static int	find_phase_base_3(char **board, char player_id, int *danger)
{
	int			row;
	int			col;

	row = ft_count_2dlines(board) - 1;
	col = ft_strlen(board[0]);
	while (row >= 0 && board[row][col] != player_id)
		row--;
	col = ft_strlen(board[0]);
	while (col >= 0 && board[0][col] != player_id)
		col--;
	if (col == -1 && row == -1 && *danger != 1)
		return (1);
	row = 0;
	while (board[row] && board[row][0] != player_id)
		row++;
	if (row < (int)ft_count_2dlines(board) && *danger == 1)
		*danger = 2;
	if (row >= (int)ft_count_2dlines(board))
		return (2);
	else
		return (3);
}

static int	find_phase_base_4(char **board, char player_id, int *danger)
{
	int			row;
	int			col;

	row = ft_count_2dlines(board) - 1;
	col = 0;
	while (row >= 0 && board[row][col] != player_id)
		row--;
	while (board[0][col] && board[0][col] != player_id)
		col++;
	if (col < (int)(ft_strlen(board[0])) && row != -1 && *danger != 1)
		return (1);
	row = 0;
	col = ft_strlen(board[0]);
	while (board[row] && board[row][col] != player_id)
		row++;
	if (row < (int)ft_count_2dlines(board) && *danger == 1)
		*danger = 2;
	if (row >= (int)ft_count_2dlines(board))
		return (2);
	else
		return (3);
}

int			find_phase(char **board, char p_id, int base)
{
	static int	danger = 0;
	size_t		col;
	size_t		row;

	if (danger == 0)
	{
		col = 0;
		row = (ft_count_2dlines(board) / 2);
		while (board[row][col] != '\0' && (board[row][col] == '.' ||
					board[row][col] == p_id || board[row][col] == p_id - 32))
			col++;
		if (col < ft_strlen(board[row]))
			danger = 1;
	}
	if (base == 1)
		return (find_phase_base_1(board, p_id, &danger));
	if (base == 2)
		return (find_phase_base_2(board, p_id, &danger));
	if (base == 3)
		return (find_phase_base_3(board, p_id, &danger));
	else
		return (find_phase_base_4(board, p_id, &danger));
	return (1);
}
