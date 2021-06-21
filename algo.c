/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:32:04 by bperez            #+#    #+#             */
/*   Updated: 2021/06/21 20:18:06 by bperez           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 3 2 1

int	checker_b(t_stack *a)
{
	int i;

	i = a->size;
	while (--i)
	{
		if (a->stack[i] < a->stack[i - 1])
		{
			//printf("\nFailed !\n");
			return (-1);
		}
	}
	//printf("\nSuccess !\n");
	return (0);
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 1)
		checker(a);
	else if (a->size == 2)
	{
		if (a->stack[a->size - 1] > a->stack[a->size - 2])
			sa(a);
		checker(a);
	}
	else if (a->size == 3)
	{
		while (checker(a))
		{
			rra(a);
			if (a->stack[a->size - 1] > a->stack[a->size - 2])
				sa(a);
		}
	}
	else if (a->size > 3)
	{
		while (checker(a))
		{
			pb(a, b);
			pb(a, b);
			pb(a, b);
			while (checker_b(b))
			{
				rrb(b);
				if (b->stack[b->size - 1] < b->stack[b->size - 2])
					sb(b);
			}
			pa(a, b);
			pa(a, b);
			pa(a, b);
			if (checker(a))
				rra(a);
		}
	}
}
