/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:51:15 by bperez            #+#    #+#             */
/*   Updated: 2021/09/25 16:26:04 by bperez           ###   ########lyon.fr   */
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

void	print_stacks_address(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size;
	printf("\n|------------------------------------------|\n");
	printf("| a %p -> ", &a->stack);
	while (i--)
		printf("%p ", &a->stack[i]);
	i = b->size;
	printf("\n| b %p -> ", &b->stack);
	while (i--)
		printf("%p ", &b->stack[i]);
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
/*
int convert_stack(t_stack *a, long *tmp_stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		tmp = 0;
		while (tmp_stack[tmp] == -1)
			tmp++;
		while (j < a->size)
		{
			if (tmp_stack[j] != -1 && tmp_stack[j] < tmp_stack[tmp])
				tmp = j;
			j++;
		}
		a->stack[tmp] = i;
		tmp_stack[tmp] = -1;
		i++;
	}
	return (0);
}
*/
/*
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
	ft_bzero(a->stack, sizeof(long) * size);
	ft_bzero(b->stack, sizeof(long) * size);
	if (a->stack && b->stack)
	{
		tmp_stack = malloc(sizeof(long) * size);
		ft_bzero(tmp_stack, sizeof(long) * size);
		if (tmp_stack)
		{
			a->size = size;
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
*/

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
	ft_bzero(a, sizeof(t_stack));
	ft_bzero(b, sizeof(t_stack));
	a->stack = malloc(sizeof(long) * size);
	b->stack = malloc(sizeof(long) * size);
	ft_bzero(a->stack, sizeof(long) * size);
	ft_bzero(b->stack, sizeof(long) * size);
	if (a->stack && b->stack)
	{
		a->size = size;
		if (!init_stack(list, b->stack, a))
		{
			if (!convert_stack(a, b->stack))
			{
				ft_bzero(b->stack, sizeof(long) * a->size);
				return (0);
			}
		}
		free(a->stack);
		free(b->stack);
	}
	return (-1);
}

/*
int	convert_stack(t_stack *a)
{
	int i;
	int j;
	int	current_index;

	i = 0;
	while (i < a->size)
	{
		j = 0;
		current_index = 0;
		while (j < a->size)
		{
			//if ((a->stack[j] < 0 || a->stack[j] >= i) && a->stack[j] < a->stack[current_index])
				//current_index = j;
			if ((a->stack[j] < 0 || a->stack[j] >= i) && a->stack[j] < a->stack[current_index])
				current_index = j;
			j++;
		}
		a->stack[current_index] = i;
		//printf("%ld %d\n", a->stack[current_index], current_index);
		i++;
	}
	return (0);
}
*/

void	debug_test(t_stack *a, t_stack *b, int argc)
{
	ft_bzero(a, sizeof(t_stack));
	ft_bzero(b, sizeof(t_stack));
	a->size = argc - 1;
	a->stack = malloc(sizeof(long) * a->size);
	b->stack = malloc(sizeof(long) * a->size);
	ft_bzero(a->stack, sizeof(long) * a->size);
	ft_bzero(a->stack, sizeof(long) * a->size);
	int i = a->size;
	while (i--)
		a->stack[i] = i;
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
			//debug_test(&a, &b, argc);
			//print_stacks_address(&a, &b);
			//print_stacks(&a, &b);
			push_swap(&a, &b);
			//print_stacks(&a, &b);
			//print_stacks_address(&a, &b);
			free(a.stack);
			free(b.stack);
			error = 0;
		}
	}
	//if (error)
		//printf("Error\n");
	return (0);
}
