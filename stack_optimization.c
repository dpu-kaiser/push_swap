/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:25:05 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/15 16:20:51 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int *copy_stack(int *stack, int size)
{
	int i;
	int *cpy;

	cpy = malloc(sizeof(int) * size);
	if (!cpy)
		return NULL;
	i = 0;
	while (i < size)
	{
		cpy[i] = stack[i];
		i++;
	}

	return cpy;
}

static void sort_stack(int *stack, int size)
{
	int i;
	int k;
	int tmp;

	i = 0;
	while (i < size - 1)
	{
		k = i + 1;
		while (k < size)
		{
			if (stack[i] > stack[k])
			{
				tmp = stack[i];
				stack[i] = stack[k];
				stack[k] = tmp;
			}
			k++;
		}
		i++;
	}
}

static void override_stack(int *stack, int *tmp_stack, int size)
{
	int i;
	int k;

	i = 0;
	while (i < size)
	{
		k = 0;
		while (stack[i] != tmp_stack[k])
			k++;
		stack[i] = k;
		i++;
	}
}

int	stack_optimize(t_stack *stack)
{
	int *tmp_stack;

	tmp_stack = copy_stack(stack->stack, stack->size);
	if (!tmp_stack)
		return 1;
	sort_stack(tmp_stack, stack->size);
	override_stack(stack->stack, tmp_stack, stack->size);
	free(tmp_stack);
	return 0;
}
