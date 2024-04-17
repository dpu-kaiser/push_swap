/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:04:19 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/17 09:30:37 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "push_swap.h"

static int is_sorted(t_stack *stack)
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

static void radixsort(t_psdata *data, int bit)
{
    int i;
    int size;
    int ctr;

    i = 0;
    ctr = 0;
    size = data->a->size;
    while (i < size)
    {
        if (data->a->size && ((data->a->stack[0] >> bit) & 1) == 0)
        {
            if (((data->a->stack[0] >> bit )& 2) == 0)
                run_command(data, PB);
            else
            {
                run_command(data, PB);
                run_command(data, RB);
                ctr++;
            }
        }
        else if (data->a->size > 1)
            run_command(data, RA);
        i++;
    }
    while (ctr--)
    {
        run_command(data, RRB);
        run_command(data, PA);
    }
    while (data->b->size > 0)
        run_command(data, PA);
    if (!is_sorted(data->a))
        radixsort(data, bit + 1);
}

void stack_sort(t_psdata *data)
{
    radixsort(data, 0);
}
