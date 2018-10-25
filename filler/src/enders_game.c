/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enders_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 15:38:36 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/08 11:53:03 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	end_turn(t_pos *move)
{
	int x;
	int y;

	x = move->x;
	y = move->y;
	free(move);
	move = NULL;
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

int		last_move(void)
{
	end_turn(create_position(0, 0));
	return (0);
}

int		end_game_real_early(t_input *input)
{
	last_move();
	if (input)
	{
		if (input->input)
			ft_freestrarr(input->input);
		free(input);
		input = NULL;
	}
	return (0);
}
