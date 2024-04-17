/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:04:19 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/17 12:20:26 by dkaiser          ###   ########.fr       */
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

static int calculate_score(t_psdata *data, int pos)
{
    int moves_to_top;
    int moves_to_spot;
    int i;

    if (pos < (data->b->size + 1) / 2)
        moves_to_top = pos;
    else
        moves_to_top = data->b->size - pos;
    i = 0;
    while (i < data->a->size && data->a->stack[i] < data->b->stack[pos])
        i++;
    if (i < (data->a->size + 1) / 2)
        moves_to_spot = 2 * i + 1;
    else
        moves_to_spot = 2 * ((data->a->size - i) + 1);
    return moves_to_top + moves_to_spot;
}



static void move_to_top(t_psdata *data, int idx)
{
    if (idx < (data->b->size + 1) / 2)
    {
        while (idx--)
            run_command(data, RB);
    }
    else
    {
        idx = data->b->size - idx;
        while (idx--)
            run_command(data, RRB);
    }
}

static void move_to_spot(t_psdata *data)
{
    int pos;
    int i;

    pos = 0;
    while (pos < data->a->size && data->b->stack[0] < data->a->stack[pos])
        pos++;
    if (pos < (data->a->size + 1) / 2)
    {
        i = pos;
        while (i--)
            run_command(data, RA);
        run_command(data, PA);
        i = pos;
        while (i--)
            run_command(data, RRA);
    }
    else
    {
        i = data->a->size - pos;
        while (i--)
            run_command(data, RRA);
        run_command(data, PA);
        i = data->a->size - pos;
        while (i--)
            run_command(data, RA);
    }
}

static void scoresort(t_psdata *data)
{
    int *scores;
    int i;
    int min_score;

    scores = malloc(sizeof(int) * data->b->size);
    // Error if allocation fails
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
    move_to_top(data, min_score);
    move_to_spot(data);

    free(scores);
    if (data->b->size > 0)
        scoresort(data);
}

void stack_sort(t_psdata *data)
{
    presort(data);
    scoresort(data);
}
