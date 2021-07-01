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
	int count;
	int i;
	int	ra_gap;
	int	rra_gap;

	count = 0;
	printf("block_size = %d\n", a->block_size);
	while (count < a->block_size)
	{
		ra_gap = -1;
		rra_gap = -1;
		i = a->size - 1;
		while (i > a->size / 2)
		{
			if (a->stack[i] < a->block_size)
			{
				printf("a\n");
				ra_gap = a->size - i + 1;
			}
			i--;
			printf("ra gap = %d\n", ra_gap);
		}
		i = 0;
		while (i < a->size / 2)
		{
			if (a->stack[i] < a->block_size)
			{
				printf("b\n");
				rra_gap = a->size - i - 1;
			}
			i++;
			printf("rra gap = %d\n", rra_gap);
		}
		if (ra_gap != 1 && (ra_gap >= rra_gap || rra_gap == -1))
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
		count++;
	}
}
