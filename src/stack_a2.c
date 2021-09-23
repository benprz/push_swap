/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 19:34:25 by bperez            #+#    #+#             */
/*   Updated: 2021/09/22 18:32:05 by bperez           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sa(t_stack *a)
{
	long c;

	if (a->size > 1)
	{
		c = a->stack[a->size - 1];
		a->stack[a->size - 1] = a->stack[a->size - 2];
		a->stack[a->size - 2] = c;
	}
	//ft_putendl("sa");
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size)
	{
		b->size--;
		a->stack[a->size] = b->stack[b->size];
		a->size++;
	}
	//ft_putendl("pa");
}

void	ra(t_stack *a)
{
	int		i;
	long	tmp;
	long	c;

	if (a->size > 1)
	{
		tmp = a->stack[0];
		a->stack[0] = a->stack[a->size - 1];
		i = 0;
		while (i++ < a->size)
		{
			c = tmp;
			tmp = a->stack[i];
			a->stack[i] = c;
		}
	}
	//ft_putendl("ra");
}

void	rra(t_stack *a)
{
	int		i;
	long	tmp;
	long	c;

	if (a->size > 1)
	{
		tmp = a->stack[a->size - 1];
		a->stack[a->size - 1] = a->stack[0];
		i = a->size - 1;
		while (i-- > 0)
		{
			c = tmp;
			tmp = a->stack[i];
			a->stack[i] = c;
		}
	}
	//ft_putendl("rra");
}
