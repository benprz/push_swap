/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:51:15 by bperez            #+#    #+#             */
/*   Updated: 2021/09/07 19:17:00 by bperez           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size;
	printf("\n|------------------------------------------|\n");
	printf("| a -> ");
	while (i--)
		printf("%ld ", a->stack[i]);
	i = b->size;
	printf("\n| b -> ");
	while (i--)
		printf("%ld ", b->stack[i]);
	printf("\n|------------------------------------------|\n\n");
}

void	sa(t_stack *a)
{
	if (a->size > 1)
		ft_swap(&a->stack[a->size - 1], &a->stack[a->size - 2]);
	ft_putendl("sa");
}

void	sb(t_stack *b)
{
	if (b->size > 1)
		ft_swap(&b->stack[b->size - 1], &b->stack[b->size - 2]);
	ft_putendl("sb");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size)
	{
		a->stack[a->size] = b->stack[--b->size];
		a->size++;
	}
	ft_putendl("pa");
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

void	ra(t_stack *a)
{
	int		i;
	long	tmp;

	if (a->size > 1)
	{
		tmp = a->stack[0];
		a->stack[0] = a->stack[a->size - 1];
		i = 0;
		while (i++ < a->size)
			ft_swap(&tmp, &a->stack[i]);
	}
	ft_putendl("ra");
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

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	int		i;
	long	tmp;

	if (a->size > 1)
	{
		tmp = a->stack[a->size - 1];
		a->stack[a->size - 1] = a->stack[0];
		i = a->size - 1;
		while (i-- > 0)
			ft_swap(&tmp, &a->stack[i]);
	}
	ft_putendl("rra");
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

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

int	convert_stack(t_stack *a, long *tmp_stack)
{
	int		i;
	int		j;
	int		tmp;
	int		old_tmp;

	i = a->size;
	old_tmp = -1;
	while (i--)
	{
		j = a->size;
		tmp = -1;
		while (j--)
		{
			if (old_tmp == -1 || tmp_stack[j] < tmp_stack[old_tmp])
				if (tmp == -1 || tmp_stack[j] > tmp_stack[tmp])
					tmp = j;
		}
		if (tmp == -1)
			return (-1);
		a->stack[tmp] = i;
		old_tmp = tmp;
	}
	free(tmp_stack);
	return (0);
}

int	ft_is_number(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	init_stack(char **list, long *tmp_stack, t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (!ft_is_number(list[a->size - i]))
			return (-1);
		tmp_stack[i] = atol(list[a->size - i]);
		if (tmp_stack[i] < INT_MIN || tmp_stack[i] > INT_MAX)
			return (-1);
		i++;
	}
	return (0);
}

int	init_stacks(char **list, t_stack *a, t_stack *b, int size)
{
	long	*tmp_stack;

	ft_bzero(a, sizeof(t_stack));
	ft_bzero(b, sizeof(t_stack));
	a->stack = malloc(sizeof(long) * size);
	b->stack = malloc(sizeof(long) * size);
	if (a->stack && b->stack)
	{
		tmp_stack = malloc(sizeof(long) * size);
		if (tmp_stack)
		{
			a->size = size;
			a->block_size = a->size / 2;
			if (!init_stack(list, tmp_stack, a))
			{
				if (!convert_stack(a, tmp_stack))
					return (0);
			}
			free(tmp_stack);
		}
		free(a->stack);
		free(b->stack);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		error;

	error = 1;
	if (argc-- >= 2)
	{
		if (!init_stacks(argv, &a, &b, argc))
		{
			push_swap(&a, &b);
			error = 0;
		}
	}
	if (error)
		printf("Error\n");
	return (0);
}
