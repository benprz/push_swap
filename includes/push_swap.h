/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:13:57 by bperez            #+#    #+#             */
/*   Updated: 2021/09/22 15:03:58 by bperez           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	long *stack;
	int size;
	int	block_size;
} t_stack;

void	push_swap(t_stack *a, t_stack *b);
int		checker(t_stack *a);
int		init_stacks(char **list, t_stack *a, t_stack *b, int size);
void	print_stacks(t_stack *a, t_stack *b);
int		checker(t_stack *a);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b, int ra_gap, int rra_gap);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);

#endif
