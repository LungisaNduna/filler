# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnduna <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/18 14:10:37 by lnduna            #+#    #+#              #
#    Updated: 2018/08/08 11:58:37 by lnduna           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ./libft.h

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	 ft_memchr.c ft_memcmp.c \
	 ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	 ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	 ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	 ft_isascii.c ft_isprint.c ft_isalnum.c ft_isalpha.c ft_isupper.c \
	 ft_islower.c ft_isdigit.c ft_isspace.c ft_iswhitespace.c ft_atoi.c \
	 ft_memalloc.c ft_memdel.c \
	 ft_strnew.c ft_strdel.c ft_strclr.c \
	 ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	 ft_strnequ.c ft_strjoin.c ft_strsub.c ft_strtrim.c \
	 ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	 ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strsplit.c \
	 ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	 ft_lstnew.c ft_tolower.c ft_toupper.c \
	 get_next_line.c ft_freestrarr.c ft_strjoin_free_both.c ft_putstrarr.c \
	 ft_count_2dlines.c ft_sqrt.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
COMP = gcc $(FLAGS)

all: $(NAME)

$(NAME): $(HEADER)
	@$(COMP) -c $(SRC)
	@ar rc $(NAME) $(OBJ) $(HEADER)
	@echo "$(NAME) is ready to use"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) burnt to the ground"

re: fclean all
