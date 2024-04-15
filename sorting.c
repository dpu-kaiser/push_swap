/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:04:19 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/15 23:39:57 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    int i;

    if (stack->size < 2)
        return 1;
    i = 1;
    while (i < stack->size)
    {
        if (stack->stack[i] < stack->stack[i-1])
            return 0;
        i++;
    }
    return 1;
}


t_list	*stack_sort(t_stack *stack_a, t_stack *stack_b)
{
    t_list *cmds = NULL;
    int pivot;

    int pivot_idx = stack_a->size - 1;
    while (stack_b->size || !is_sorted(stack_a))
    {
        pivot = stack_a->stack[pivot_idx];

        while (stack_a->size > 0 && stack_a->stack[0] != pivot)
        {
            if (stack_a->stack[0] > pivot)
                run_command(stack_a, stack_b, &cmds, RA);
            else
                run_command(stack_a, stack_b, &cmds, PB);
        }
        while (stack_b->size > 0)
            run_command(stack_a, stack_b, &cmds, PA);
        if (stack_a->stack[pivot_idx] == pivot)
            pivot_idx--;
        if (pivot_idx < 0)
            pivot_idx = stack_a->size - 1;
    }
    return cmds;
}
