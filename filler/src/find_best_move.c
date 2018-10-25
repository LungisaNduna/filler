/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 14:59:45 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/07 14:45:53 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static double	distance(int x, int y)
{
	if (x == 0)
		return (y);
	else if (y == 0)
		return (x);
	else
		return (ft_sqrt(x * x + y * y));
}

static t_pos	*punch_weak_spot(t_pos *moves, int dir, size_t row, size_t col)
{
	t_pos	*closest;
	t_pos	*temp;

	temp = moves->next;
	closest = moves;
	while (temp)
	{
		if (dir == 1 && distance(temp->x, temp->y) <
				distance(closest->x, closest->y))
			closest = temp;
		else if (dir == 2 && distance(temp->y, col - temp->x) <
				distance(closest->y, col - closest->x))
			closest = temp;
		else if (dir == 3 && distance(row - temp->y, temp->x) <
				distance(row - closest->y, closest->x))
			closest = temp;
		else if (dir == 4 && distance(row - temp->y, col - temp->x) <
				distance(row - closest->y, col - closest->x))
			closest = temp;
		temp = temp->next;
	}
	return (create_position(closest->x, closest->y));
}

static int		get_direction(int phase, int base)
{
	int	direction;

	direction = 0;
	if ((phase == 2 && base == 3) || (phase == 1 && base == 4))
		direction = 1;
	else if ((phase == 1 && base == 3) || (phase == 2 && base == 4))
		direction = 2;
	else if ((phase == 2 && base == 1) || (phase == 1 && base == 2))
		direction = 3;
	else if ((phase == 1 && base == 1) || (phase == 2 && base == 2))
		direction = 4;
	return (direction);
}

static t_pos	*submission_hold(t_pos *moves, t_strat *strat)
{
	t_pos	*furthest;
	t_pos	*temp;

	furthest = moves;
	temp = furthest->next;
	while (temp != NULL)
	{
		if (strat->base < 3)
		{
			if (temp->y < furthest->y)
				furthest = temp;
		}
		else
		{
			if (temp->y > furthest->y)
				furthest = temp;
		}
		temp = temp->next;
	}
	return (create_position(furthest->x, furthest->y));
}

t_pos			*find_best_move(t_round *turn, t_pos *moves, t_strat *strat)
{
	t_pos	*best_move;
	int		phase;
	int		direction;

	phase = find_phase(turn->board, strat->p_id, strat->base);
	best_move = NULL;
	if (phase == 1 || phase == 2)
	{
		direction = get_direction(phase, strat->base);
		best_move = punch_weak_spot(moves, direction, turn->rows, turn->cols);
	}
	else if (phase == 3)
		best_move = submission_hold(moves, strat);
	return (best_move);
}
