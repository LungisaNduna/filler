/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnduna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 13:39:33 by lnduna            #+#    #+#             */
/*   Updated: 2018/08/08 11:53:46 by lnduna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

static char		start_new_game(t_input *input)
{
	char	player_id;

	player_id = ' ';
	if (ft_strstr(input->input[0], "lnduna") &&
			ft_strstr(input->input[0], "p1"))
		player_id = 'o';
	else if (ft_strstr(input->input[0], "lnduna") &&
			ft_strstr(input->input[0], "p2"))
		player_id = 'x';
	ft_freestrarr(input->input);
	free(input);
	return (player_id);
}

static void		check_for_end(char *last_read, int *end_count)
{
	int	counter;

	counter = *end_count;
	if (ft_strstr(last_read, "Piece") && *end_count == -1)
		counter = ft_atoi(ft_strchr(last_read, ' ')) + 1;
	else if (ft_strstr(last_read, "$$$"))
		counter = 1;
	if (counter > 0)
		counter--;
	*end_count = counter;
}

static t_input	*get_input(void)
{
	t_input *input;
	char	*long_line;
	char	*joiner_line;
	int		gnl_ret;
	int		end;

	long_line = ft_strdup("");
	end = -1;
	while (end != 0)
	{
		if ((gnl_ret = get_next_line(0, &joiner_line)) == -1)
			return (NULL);
		long_line = ft_strjoin(long_line, joiner_line);
		check_for_end(joiner_line, &end);
		free(joiner_line);
		joiner_line = long_line;
		long_line = ft_strjoin(long_line, "\n");
		free(joiner_line);
	}
	input = (t_input *)malloc(sizeof(t_input));
	input->input_type = (ft_strstr(long_line, "$$$")) ? 1 : 2;
	input->input = ft_strsplit(long_line, '\n');
	free(long_line);
	return (input);
}

int				main(void)
{
	t_round	*turn;
	t_input	*input;
	t_pos	*move;
	char	player_id;
	int		base;

	base = 0;
	while (1)
	{
		if ((input = get_input()) == NULL)
			return (end_game_real_early(input));
		if (input->input_type == 1)
			player_id = start_new_game(input);
		else if (input->input_type == 2)
		{
			turn = look_at_board(input);
			if (base == 0)
				base = find_my_starting_pos(turn, player_id);
			if (!(move = find_move(turn, create_strategy(player_id, base))))
				return (last_move());
			end_turn(move);
		}
	}
	return (0);
}
