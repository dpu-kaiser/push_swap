/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:04:19 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/17 10:50:01 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void presort(t_psdata *data)
{
    int size;
    int pivot;
    int max;

    size = data->a->size;
    pivot = size / 2;
    max = data->a->stack[0];
    while (size--)
    {
        if (data->a->stack[0] < max)
        {
            run_command(data, PB);
            if (data->b->stack[0] > pivot)
                run_command(data, RB);
        }
        else
        {
            max = data->a->stack[0];
            run_command(data, RA);
        }
    }
}

void stack_sort(t_psdata *data)
{
    presort(data);
}
