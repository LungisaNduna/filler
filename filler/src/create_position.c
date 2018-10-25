/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:12:40 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/03 14:34:32 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_strat	*create_strategy(char player_id, int start_quad)
{
	t_strat *strat;

	strat = (t_strat *)malloc(sizeof(t_strat));
	strat->p_id = player_id;
	strat->base = start_quad;
	return (strat);
}

t_pos	*create_position(int x, int y)
{
	t_pos	*position;

	position = (t_pos *)malloc(sizeof(t_pos));
	position->next = NULL;
	position->x = x;
	position->y = y;
	return (position);
}

void	free_pos_list(t_pos *pos)
{
	t_pos	*temp;

	while (pos != NULL)
	{
		temp = pos;
		pos = pos->next;
		free(temp);
	}
}
