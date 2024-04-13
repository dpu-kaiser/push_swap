/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:04:19 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/13 19:29:05 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	radixsort_step(t_list **stack_a, t_list **stack_b, t_list **cmds,
		int bit)
{
	int	i;
	int	max;

	i = 0;
	max = ft_lstsize(*stack_a);
	while (i < max)
	{
		if (*stack_a && (*(int *)(*stack_a)->content >> bit) % 2 == 0)
			run_command(stack_a, stack_b, cmds, PB);
		else if ((*stack_a)->next)
			run_command(stack_a, stack_b, cmds, RA);
		i++;
	}
	while (*stack_b)
		run_command(stack_a, stack_b, cmds, PA);
}

static void	stack_radixsort(t_list **stack_a, t_list **stack_b, t_list **cmds)
{
	int	bit;
	int	max_bits;

	bit = 0;
	max_bits = 9;
	while (bit < max_bits)
	{
		radixsort_step(stack_a, stack_b, cmds, bit);
		bit++;
	}
}

void	stack_sort(t_list **stack_a, t_list **stack_b, t_list **cmds)
{
	stack_radixsort(stack_a, stack_b, cmds);
}
