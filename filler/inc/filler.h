/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:51:14 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/08 11:30:07 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <stdio.h>

typedef	struct		s_input
{
	int				input_type;
	char			**input;
}					t_input;

typedef	struct		s_pos
{
	int				x;
	int				y;
	struct s_pos	*next;
}					t_pos;

typedef	struct		s_round
{
	char			**board;
	char			**token;
	t_pos			*trim_dim;
	size_t			rows;
	size_t			cols;
}					t_round;

typedef	struct		s_strat
{
	char			p_id;
	int				base;
}					t_strat;

t_round				*look_at_board(t_input *input);
int					find_my_starting_pos(t_round *turn, char player_id);
t_pos				*find_best_move(t_round *turn, t_pos *moves,
					t_strat *strat);
int					find_phase(char **board, char p_id, int base);
t_pos				*find_move(t_round *turn, t_strat *strat);
t_pos				*find_all_moves(t_round *turn, char p_id);
t_pos				*create_position(int x, int y);
t_strat				*create_strategy(char player_id, int start_quad);
void				free_pos_list(t_pos *pos);
int					end_game_real_early(t_input *input);
void				end_turn(t_pos *move);
int					last_move(void);

#endif
