# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnduna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/09 13:35:08 by lnduna            #+#    #+#              #
#    Updated: 2018/08/10 15:46:51 by lnduna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lnduna.filler

INC = ./inc/

COMP = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
	@make -C libft/
	@gcc -Wall -Wextra -Werror -o $(NAME) -I./inc/ src/* libft/libft.a
	@echo "$(NAME) is ready to use."

clean:
	@make fclean -C ./libft/
	@echo "the extra stuff has been removed"

fclean: clean
	@rm $(NAME)
	@echo "$(NAME) has been removed"

re: fclean all
