/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:37:07 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/24 13:42:32 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_score(t_psdata *data, int pos)
{
	int	moves_to_top;
	int	moves_to_spot;
	int	i;

	if (pos < (data->b->size + 1) / 2)
		moves_to_top = pos;
	else
		moves_to_top = data->b->size - pos;
	i = 0;
	while (i < data->a->size && data->a->stack[i] > data->b->stack[pos])
		i++;
	if (i < (data->a->size + 1) / 2)
		moves_to_spot = 2 * i + 1;
	else
		moves_to_spot = 2 * ((data->a->size - i) + 1);
	return (moves_to_top + moves_to_spot);
}

void	move_to_top(t_psdata *data, int idx)
{
	if (idx < (data->b->size + 1) / 2)
	{
		while (--idx > 0)
			run_command(data, RB);
	}
	else
	{
		idx = data->b->size - idx;
		while (idx--)
			run_command(data, RRB);
	}
	run_command(data, PA);
}

static int	get_pos(t_psdata *data)
{
	int	pos;

	pos = 0;
	while (pos < data->a->size && data->b->stack[0] > data->a->stack[pos])
		pos++;
	return (pos);
}

void	move_to_spot(t_psdata *data, int idx)
{
	int	pos;
	int	i;

	pos = get_pos(data);
	if (pos < (data->a->size + 1) / 2)
	{
		i = pos;
		while (i--)
			run_command(data, RA);
		move_to_top(data, idx);
		i = pos;
		while (i--)
			run_command(data, RRA);
	}
	else
	{
		i = data->a->size - pos;
		while (i--)
			run_command(data, RRA);
		move_to_top(data, idx);
		i = data->a->size - pos;
		while (i--)
			run_command(data, RA);
	}
}
