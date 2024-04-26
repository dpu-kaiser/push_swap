/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:04:19 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/26 13:54:26 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	int	i;

	if (stack->size < 2)
		return (1);
	i = 1;
	while (i < stack->size)
	{
		if (stack->stack[i] < stack->stack[i - 1])
			return (0);
		i++;
	}
	return (1);
}

static void	ps_radixsort(t_psdata *data, int bit)
{
	int	i;
	int	size;

	i = 0;
	size = data->a->size;
	while (i < size)
	{
		if (data->a->size && ((data->a->stack[0] >> bit) & 1) == 0)
			run_command(data, PB);
		else if (data->a->size > 1)
			run_command(data, RA);
		i++;
	}
	while (data->b->size > 0)
		run_command(data, PA);
	if (!is_sorted(data->a))
		ps_radixsort(data, bit + 1);
}

void	stack_sort(t_psdata *data)
{
	if (!is_sorted(data->a))
		ps_radixsort(data, 0);
}
