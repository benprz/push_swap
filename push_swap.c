/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.cc                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez <bperez@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:32:04 by bperez            #+#    #+#             */
/*   Updated: 2021/05/12 18:31:05 by bperez           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

void	print_stacks(long *a, long *b)
{
	int i = 0;

	printf("\n|------------------------------------------|\n");
	printf("| a -> ");
	if (a)
	{
		while (a[i])
		{
			printf("%d ", a[i]);
			i++;
		}
	}
	else
		printf("NULL");
	printf("\n| b -> ");
	if (b)
	{
		while (b[i])
		{
			printf("%d ", b[i]);
			i++;
		}
	}
	else
		printf("NULL");
	printf("\n|------------------------------------------|\n\n");
}

//swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements)
void	sa(long *a)
{
	ft_swap(&a[0], &a[1]);
}
// swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
void	sb(long *b)
{
	ft_swap(&b[0], &b[1]);
}
// sa and sb at the same time.
void	ss(long *a, long *b)
{
	sa(a);
	sb(b);
}
//  push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
void	pa(long *a; long *b)
{
	
}

void	push_swap(long *a, long *b)
{
	print_stacks(a, b);
	sa(a);
	print_stacks(a, b);
}

int	init_list(char **list, long *stack_a, int size)
{
	stack_a[size] = '\0';
	while (size--)
	{
	//	if (!ft_is_number(list[size + 1]))
	//		return (0);
		stack_a[size] = atol(list[size + 1]);
		if (stack_a[size] < INT_MIN || stack_a[size] > INT_MAX)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	long	*stack_a;

	if (argc >= 2)
	{
		argc--;
		stack_a = malloc(sizeof(int) * argc);
		if (stack_a)
		{
			if (init_list(argv, stack_a, argc))
			{
				printf("init!\n#####################\n");
				push_swap(stack_a, NULL);
				return (1);
			}
			free(a);
		}
	}
	printf("Error\n");
	return (0);
}
