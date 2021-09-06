/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:32:04 by bperez            #+#    #+#             */
/*   Updated: 2021/06/25 20:43:35 by bperez           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 3 2 1

int	checker(t_stack *a)
{
	int i;

	i = a->size;
	while (--i)
	{
		if (a->stack[i] > a->stack[i - 1])
			return (-1);
	}
	printf("\nSuccess !\n");
	return (0);
}

void	push_a(t_stack *a, t_stack *b)
{
	int	rb_gap;
	int	rrb_gap;
	int i;
	int j;

	j = b->size;
	while (j--)
	{
		i = 0;
		while (b->stack[i] != j)
			i++;
		rrb_gap = i + 1;
		i = 0;
		while (b->stack[b->size - 1 - i] != j)
			i++;
		rb_gap = i;
		if (rb_gap < rrb_gap)
			while (rb_gap--)
				rb(b);
		else
			while (rrb_gap--)
				rrb(b);
		pa(a, b);
	}
}

void	push_b(t_stack *a, t_stack *b, int ra_gap, int rra_gap)
{
	if (ra_gap < rra_gap)
	{
		while (ra_gap--)
			ra(a);
	}
	else
	{
		while (rra_gap--)
			rra(a);
	}
	pb(a, b);
}

/*
1 0 2
1 2 0
0 2 1
2 1 0
2 0 1
*/

void	sort_three(t_stack *a, t_stack *b)
{
	if (a->stack[1] < a->stack[2] && a->stack[0] > a->stack[2])
		sa(a);
	else if (a->stack[1] > a->stack[2] && a->stack[0] < a->stack[2])
		rra(a);
	else if (a->stack[1] > a->stack[2] && a->stack[1] > a->stack[2])
	{
		rra(a);
		sa(a);
	}
	else if (a->stack[2] > a->stack[1] && a->stack[0] < a->stack[1])
	{
		ra(a);
		sa(a);
	}
	else if (a->stack[2] > a->stack[0] && a->stack[1] < a->stack[0])
		ra(a);
}

void	sort_more(t_stack *a, t_stack *b)
{
	int ra_gap;
	int rra_gap;
	int i;
	int j;
	int	current_block;

	j = 0;
	current_block = a->block_size;
	while (j < a->size + b->size)
	{
		i = 0;
		while (a->stack[i] > current_block - 1)
			i++;
		rra_gap = i + 1;
		i = 0;
		while (a->stack[a->size - 1 - i] > current_block - 1)
			i++;
		ra_gap = i;
		push_b(a, b, ra_gap, rra_gap);
		j++;
		if (j % current_block == 0)
			current_block += a->block_size;
	}
	push_a(a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (checker(a) == -1)
	{
		if (a->size == 1)
			return ;
		else if (a->size == 2)
			ra(a);
		else if (a->size == 3)
			sort_three(a, b);
		else
			sort_more(a, b);
		checker(a);
	}
}
