/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:34:57 by bperez            #+#    #+#             */
/*   Updated: 2021/09/28 01:12:39 by bperez           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sb(t_stack *b)
{
	if (b->size > 1)
		ft_swap(&b->stack[b->size - 1], &b->stack[b->size - 2]);
	ft_putendl("sb");
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size)
	{
		b->stack[b->size] = a->stack[--a->size];
		b->size++;
	}
	ft_putendl("pb");
}

void	rb(t_stack *b)
{
	int		i;
	long	tmp;

	if (b->size > 1)
	{
		tmp = b->stack[0];
		b->stack[0] = b->stack[b->size - 1];
		i = 0;
		while (i++ < b->size)
			ft_swap(&tmp, &b->stack[i]);
	}
	ft_putendl("rb");
}

void	rrb(t_stack *b)
{
	int		i;
	long	tmp;

	if (b->size > 1)
	{
		tmp = b->stack[b->size - 1];
		b->stack[b->size - 1] = b->stack[0];
		i = b->size - 1;
		while (i-- > 0)
			ft_swap(&tmp, &b->stack[i]);
	}
	ft_putendl("rrb");
}
