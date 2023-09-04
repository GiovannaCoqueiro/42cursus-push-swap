# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 15:07:53 by gcoqueir          #+#    #+#              #
#    Updated: 2023/09/04 15:09:53 by gcoqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../include
RM = rm -f
FILES = ft_atol.c ft_strcmp.c ft_strlen.c ft_strjoin.c ft_strchr.c \
		get_next_line.c ft_printf.c print_char.c print_hex.c print_nbr.c \
		print_ptr.c print_str.c print_unint.c ft_putendl_fd.c get_line.c
OBJS = $(FILES:.c=.o)

all: $(NAME)
	@echo "libft is ready!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re