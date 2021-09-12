/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:04:16 by bperez            #+#    #+#             */
/*   Updated: 2021/09/12 20:07:43 by bperez           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_stack *a)
{
	int	i;

	i = a->size;
	while (--i)
	{
		if (a->stack[i] > a->stack[i - 1])
			return (-1);
	}
	return (0);
}

void	push_a(t_stack *a, t_stack *b)
{
	int	rb_gap;
	int	rrb_gap;
	int	i;
	int	j;

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
