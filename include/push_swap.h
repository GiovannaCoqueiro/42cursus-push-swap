/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoqueir <gcoqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 06:54:55 by gcoqueir          #+#    #+#             */
/*   Updated: 2023/08/16 19:29:27 by gcoqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define INTMAX 2147483647
# define INTMIN -2147483648
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		*copy;
	size_t	a_len;
	size_t	b_len;
	size_t	real_range;
}			t_stack;

void	check_params(int list, char **param);
int		*create_stack(int range, char **param, t_stack *stack);
void	insertion_sort(int *tab, int range);
void	put_index(int *tab, int *copy, int range);

int		swap_a(t_stack *stack);
int		swap_b(t_stack *stack);
int		swap_swap(t_stack *stack);
int		push_a(t_stack *stack);
int		push_b(t_stack *stack);
int		rol_a(t_stack *stack);
int		rol_b(t_stack *stack);
int		rol_rol(t_stack *stack);

void	free_for_finish(t_stack *stack);
void	error_check(int i, t_stack *stack);

#endif