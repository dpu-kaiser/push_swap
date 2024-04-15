/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:31:30 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/15 17:27:04 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack *stack)
{
	int tmp;

	if (stack->size > 1)
	{
		tmp = stack->stack[0];
		stack->stack[0] = stack->stack[1];
		stack->stack[1] = tmp;
	}
}

void	stack_push(t_stack *dst_stack, t_stack *src_stack)
{
	int i;

	i = dst_stack->size - 1;
	while (i > 0)
	{
		dst_stack->stack[i] = dst_stack->stack[i-1];
		i--;
	}
	dst_stack->stack[0] = src_stack->stack[0];
	dst_stack->size++;
	i = 1;
	while (i < src_stack->size)
	{
		src_stack->stack[i-1] = src_stack->stack[i];
		i++;
	}
	src_stack->size--;
}

void	stack_rotate(t_stack *stack)
{
	int tmp;
	int i;

	tmp = stack->stack[0];
	i = 1;
	while (i < stack->size)
	{
		stack->stack[i-1] = stack->stack[i];
		i++;
	}
	stack->stack[i-1] = tmp;
}

void	stack_rrotate(t_stack *stack)
{
	int tmp;
	int i;

	i = stack->size - 1;
	tmp = stack->stack[i];
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i-1];
		i--;
	}
	stack->stack[0] = tmp;
}

void stack_print(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->size)
		ft_printf("%d ", stack->stack[i++]);
	ft_printf("\n");
}
