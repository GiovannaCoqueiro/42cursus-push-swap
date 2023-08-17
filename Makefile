# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 08:58:42 by gcoqueir          #+#    #+#              #
#    Updated: 2023/08/17 14:17:25 by gcoqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = push_swap_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC)
RM = rm -f
INC = ./include
LIBFT = ./libft
SRCS = srcs/
BONUS_SRCS = bonus/
FILES = $(SRCS)push_swap.c $(SRCS)program_call_check.c $(SRCS)init_utils.c \
		$(SRCS)final_sort.c $(SRCS)simulate.c $(SRCS)swap_moves.c \
		$(SRCS)push_moves.c $(SRCS)rotate_moves.c $(SRCS)reverse_moves.c \
		$(SRCS)free_and_error.c
OBJS = $(FILES:.c=.o)
BONUS_FILES = $(BONUS_SRCS)push_swap_bonus.c
BONUS_OBJS = $(BONUS_FILES:.c=.o)
GREEN = \033[1;32m

all: $(NAME)
	@echo "$(GREEN)SUCCESS!!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT) --silent
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME)

bonus: $(BONUS_NAME)
	@echo "$(GREEN)SUCCESS!!"

$(BONUS_NAME): $(BONUS_OBJS)
	@make -C $(LIBFT) --silent
	@$(CC) $(BONUS_OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(BONUS_NAME)

clean:
	@make clean -C $(LIBFT) --silent
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make fclean -C $(LIBFT) --silent
	@$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus