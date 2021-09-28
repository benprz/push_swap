/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:34:25 by bperez            #+#    #+#             */
/*   Updated: 2021/09/28 16:21:58 by bperez           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sb(t_stack *a)
{
	long	tmp;

	if (a->size > 1)
	{
		tmp = a->stack[a->size - 1];
		a->stack[a->size - 1] = a->stack[a->size - 2];
		a->stack[a->size - 2] = tmp;
	}
	ft_putendl("sb");
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size)
	{
		a->size--;
		b->stack[b->size] = a->stack[a->size];
		b->size++;
	}
	ft_putendl("pb");
}

void	rb(t_stack *a)
{
	int		i;
	long	tmp;
	long	tmp2;

	if (a->size > 1)
	{
		tmp = a->stack[0];
		a->stack[0] = a->stack[a->size - 1];
		i = 0;
		while (i++ < a->size - 1)
		{
			tmp2 = tmp;
			tmp = a->stack[i];
			a->stack[i] = tmp2;
		}
	}
	ft_putendl("rb");
}

void	rrb(t_stack *a)
{
	int		i;
	long	tmp;
	long	tmp2;

	if (a->size > 1)
	{
		tmp = a->stack[a->size - 1];
		a->stack[a->size - 1] = a->stack[0];
		i = a->size - 1;
		while (i > 0)
		{
			tmp2 = tmp;
			tmp = a->stack[i - 1];
			a->stack[i - 1] = tmp2;
			i--;
		}
	}
	ft_putendl("rrb");
}
