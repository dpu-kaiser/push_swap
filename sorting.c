/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:04:19 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/16 11:20:43 by dkaiser          ###   ########.fr       */
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


void stack_sort(t_psdata *data)
{
    int pivot;
    int pivot_idx;
    
    data->cmds = NULL;
    pivot_idx = data->a->size - 1;
    while (data->b->size || !is_sorted(data->a))
    {
        pivot = data->a->stack[pivot_idx];

        while (data->a->size > 0 && data->a->stack[0] != pivot)
        {
            if (data->a->size > 1 && data->a->stack[0] > pivot)
                run_command(data, RA);
            else if (data->a->size > 0)
                run_command(data, PB);
        }
        while (data->b->size > 0)
            run_command(data, PA);
        if (data->a->stack[pivot_idx] == pivot)
            pivot_idx--;
        if (pivot_idx < 0)
            pivot_idx = data->a->size - 1;
    }
}
