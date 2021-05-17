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

void	push_swap(long *a, int *b)
{
	int i = 0;

	while (a[i])
	{
		printf("%d ", a[i]);
		i++;
	}
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
		stack_a = malloc(sizeof(int) * argc);
		if (stack_a)
		{
			if (init_list(argv, stack_a, argc - 1))
			{
				printf("init!\n#####################\n");
				push_swap(stack_a, NULL);
				return (1);
			}
		}
	}
	printf("Error\n");
	return (0);
}
