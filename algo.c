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
	int i;
	int j;

	i = 0;
	while (i < a->size / 2)
	{
		if (a->stack[i] 
}
