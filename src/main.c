/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:51:15 by bperez            #+#    #+#             */
/*   Updated: 2021/09/28 16:20:27 by bperez           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks_address(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size + 1;
	printf("\n|------------------------------------------|\n");
	printf("| %p a -> ", a->stack);
	while (i--)
		printf("%d.%p ", i, &a->stack[i]);
	i = b->size;
	printf("\n| %p b -> ", b->stack);
	while (i--)
		printf("%p ", &b->stack[i]);
	printf("\n|------------------------------------------|\n\n");
}

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
	return (0);
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

int	init_stack2(char **list, long *tmp_stack, t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (!ft_is_number(list[a->size - i]))
			return (-1);
		a->stack[i] = atol(list[a->size - i]);
		if (a->stack[i] < INT_MIN || a->stack[i] > INT_MAX)
			return (-1);
		i++;
	}
	return (0);
}

int	init_stacks(char **list, t_stack *a, t_stack *b, int size)
{
	ft_bzero(a, sizeof(t_stack));
	ft_bzero(b, sizeof(t_stack));
	a->stack = malloc(sizeof(long) * size);
	b->stack = malloc(sizeof(long) * size);
	ft_bzero(a->stack, sizeof(long) * size);
	ft_bzero(b->stack, sizeof(long) * size);
	if (a->stack && b->stack)
	{
		a->size = size;
		//printf("a->size = %d\n\n", a->size);
		if (!init_stack(list, b->stack, a))
		{
			if (!convert_stack(a, b->stack))
			{
				ft_bzero(b->stack, sizeof(long) * a->size);
				return (0);
			}
			return (0);
		}
		free(a->stack);
		free(b->stack);
	}
	return (-1);
}

void	debug_tests(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	rb(b);
	pa(a, b);
	pa(a, b);
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
			//print_stacks(&a, &b);
			//print_stacks_address(&a, &b);
			//debug_tests(&a, &b);
			//print_stacks_address(&a, &b);
			push_swap(&a, &b);
			//print_stacks(&a, &b);
			free(a.stack);
			free(b.stack);
			error = 0;
		}
	}
	//if (error)
		//printf("Error\n");
	return (0);
}
