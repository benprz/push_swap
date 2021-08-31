/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:51:15 by bperez            #+#    #+#             */
/*   Updated: 2021/06/25 20:02:21 by bperez           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	//for (int j = 0; j < a->size; j++)
		//printf("%d\n", a->stack[j]);
	int i;

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

//swap the first 2 elements at the top of a stack. Do nothing if there is only one or no elements)
void	sa(t_stack *a)
{
	if (a->size > 1)
		ft_swap(&a->stack[a->size - 1], &a->stack[a->size - 2]);
	ft_putendl("sa");
}
//swap the first 2 elements at the top of a stack. Do nothing if there is only one or no elements)
void	sb(t_stack *b)
{
	if (b->size > 1)
		ft_swap(&b->stack[b->size - 1], &b->stack[b->size - 2]);
	ft_putendl("sb");
}
// sa and sb at the same time.
void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
// push a - take the first element at the top of b and put it at the top of a. Do nothing if a is empty.
void	pa(t_stack *a, t_stack *b)
{
	if (b->size)
	{
		a->stack[a->size] = b->stack[--b->size];
		a->size++;
	}
	ft_putendl("pa");
}
// push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
void	pb(t_stack *a, t_stack *b)
{
	if (a->size)
	{
		b->stack[b->size] = a->stack[--a->size];
		b->size++;
	}
	ft_putendl("pb");
}
// rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
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
// rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
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
// ra and rb at the same time.
void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
// reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
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
// reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
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
// rra and rrb at the same time.
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

int	init_stack(char **list, long *tmp_stack, t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
	//	if (!ft_is_number(list[i]))
	//		return (0);
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
			a->block_size = a->size / 5;
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
	t_stack a;
	t_stack b;
	int		error;

	error = 1;
	if (argc-- >= 2)
	{
		if (!init_stacks(argv, &a, &b, argc))
		{
			print_stacks(&a, &b);
			push_swap(&a, &b);
			print_stacks(&a, &b);
			error = 0;
		}
	}
	if (error)
		printf("Error\n");
	return (0);
}
