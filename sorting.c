/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:04:19 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/24 13:48:31 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "push_swap.h"

static void	presort(t_psdata *data)
{
	int	size;
	int	pivot;
	int	max;

	size = data->a->size;
	pivot = size / 2;
	max = data->a->stack[0];
	while (size--)
	{
		if (data->a->stack[0] < max)
		{
			run_command(data, PB);
			if (data->b->stack[0] < pivot)
				run_command(data, RB);
		}
		else
		{
			max = data->a->stack[0];
			run_command(data, RA);
		}
	}
}

static void	scoresort(t_psdata *data)
{
	int	*scores;
	int	i;
	int	min_score;

	scores = malloc(sizeof(int) * data->b->size);
	if (!scores)
		return ;
	i = 0;
	while (i < data->b->size)
	{
		scores[i] = calculate_score(data, i);
		i++;
	}
	i = 0;
	min_score = 0;
	while (i < data->b->size)
	{
		if (scores[i] < scores[min_score])
			min_score = i;
		i++;
	}
	move_to_spot(data, min_score);
	free(scores);
	if (data->b->size > 0)
		scoresort(data);
}

void	stack_sort(t_psdata *data)
{
	presort(data);
	scoresort(data);
}
