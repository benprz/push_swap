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

/*
8
2
1
5
4
6
7
0
3
*/

block_size = 

ra_gap
rra_gap

void	push_swap(t_stack *a, t_stack *b)
{
	printf("size = %d block_size = %d\n", a->size,a->block_size);
//	while (a->stack[i] > a->block_size)
}
