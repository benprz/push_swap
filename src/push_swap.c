/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:32:04 by bperez            #+#    #+#             */
/*   Updated: 2021/09/25 16:26:54 by bperez           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	if (checker(a) == -1)
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
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	ra_gap;
	int	rra_gap;
	int	i;

	i = 0;
	while (a->stack[i] != 0)
		i++;
	rra_gap = i + 1;
	i = 0;
	while (a->stack[a->size - i - 1] != 0)
		i++;
	ra_gap = i;
	push_b(a, b, ra_gap, rra_gap);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	ra_gap;
	int	rra_gap;
	int	i;

	i = 0;
	while (a->stack[i] != 0)
		i++;
	rra_gap = i + 1;
	i = 0;
	while (a->stack[a->size - i - 1] != 0)
		i++;
	ra_gap = i;
	push_b(a, b, ra_gap, rra_gap);
	i = 0;
	while (a->stack[i] != 1)
		i++;
	rra_gap = i + 1;
	i = 0;
	while (a->stack[a->size - i - 1] != 1)
		i++;
	ra_gap = i;
	push_b(a, b, ra_gap, rra_gap);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}

void	sort_more(t_stack *a, t_stack *b)
{
	int	ra_gap;
	int	rra_gap;
	int	i;
	int	j;
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
		if (a->size == 2)
			sa(a);
		else if (a->size == 3)
			sort_three(a);
		else if (a->size == 4)
			sort_four(a, b);
		else if (a->size == 5)
			sort_five(a, b);
		else
		{
			if (a->size < 20)
				a->block_size = 2;
			else if (a->size < 500)
				a->block_size = 20;
			else
				a->block_size = 35;
			sort_more(a, b);
		}
	}
}
