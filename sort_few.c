/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:24:54 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/27 15:13:03 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_psdata *data)
{
	if (data->a->stack[1] > data->a->stack[0]
		&& data->a->stack[1] > data->a->stack[2])
		run_command(data, RRA);
	else if (data->a->stack[0] > data->a->stack[1]
		&& data->a->stack[0] > data->a->stack[2])
		run_command(data, RA);
	if (data->a->stack[0] > data->a->stack[1])
		run_command(data, SA);
}

static int	get_min_pos(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = 2147483647;
	while (i < stack->size)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	i = 0;
	while (stack->stack[i] != min)
		i++;
	return (i);
}

static void	rotate_a_n(t_psdata *data, int n)
{
	if (n < (data->a->size + 1) / 2)
	{
		while (n--)
			run_command(data, RA);
	}
	else
	{
		n = data->a->size - n;
		while (n--)
			run_command(data, RRA);
	}
}

static void	reinsert_nbrs(t_psdata *data)
{
	int	i;

	while (data->b->size > 0)
	{
		if (data->b->stack[0] >= data->a->size)
		{
			run_command(data, PA);
			run_command(data, RA);
		}
		else
		{
			i = 0;
			while (i < data->a->size && data->b->stack[0] > data->a->stack[i])
				i++;
			rotate_a_n(data, i);
			run_command(data, PA);
			if (data->a->stack[0] != data->b->stack[0] - 1)
				rotate_a_n(data, get_min_pos(data->a));
		}
	}
}

void	sort_few(t_psdata *data)
{
	if (data->a->stack[0] == data->a->size - 1)
		run_command(data, RA);
	while (data->a->size > 3)
		run_command(data, PB);
	if (data->b->stack[0] > data->b->stack[1])
		run_command(data, SB);
	sort_three(data);
	reinsert_nbrs(data);
}
