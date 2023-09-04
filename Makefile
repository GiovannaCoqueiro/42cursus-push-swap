# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 08:58:42 by gcoqueir          #+#    #+#              #
#    Updated: 2023/09/04 14:57:14 by gcoqueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC)
RM = rm -f
INC = ./include
LIBFT = ./libft
SRCS = srcs/
INIT = $(SRCS)init/
SORT = $(SRCS)sorting/
MOVES = $(SRCS)moves/
END = $(SRCS)end/
BONUS_SRCS = bonus/
FILES = $(SRCS)push_swap.c $(INIT)program_call_check.c $(INIT)create_list.c \
		$(INIT)get_index.c $(SORT)sorting.c $(SORT)fill_b.c $(SORT)take_moves.c \
		$(SORT)simplify_moves.c $(SORT)fill_a.c $(MOVES)swap_moves.c \
		$(MOVES)push_moves.c $(MOVES)rotate_moves.c $(MOVES)reverse_moves.c \
		$(END)free_and_error.c
OBJS = $(FILES:.c=.o)
BONUS_FILES = $(BONUS_SRCS)checker_bonus.c $(BONUS_SRCS)checker_utils_bonus.c \
		$(INIT)program_call_check.c $(INIT)create_list.c $(INIT)get_index.c \
		$(SORT)sorting.c $(SORT)fill_b.c $(SORT)take_moves.c \
		$(SORT)simplify_moves.c $(SORT)fill_a.c $(MOVES)swap_moves.c \
		$(MOVES)push_moves.c $(MOVES)rotate_moves.c $(MOVES)reverse_moves.c \
		$(END)free_and_error.c
BONUS_OBJS = $(BONUS_FILES:.c=.o)
GREEN = \033[1;32m
NO_COLOR = \033[0m

all: $(NAME)
	@echo "$(GREEN)SUCCESS!!$(NO_COLOR)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT) --silent
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -o $(NAME)

bonus: $(BONUS_NAME)
	@echo "$(GREEN)SUCCESS!!$(NO_COLOR)"

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