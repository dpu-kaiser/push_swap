/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_optimization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:42:34 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/16 13:15:34 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

static enum e_pscmd get_cmd(t_list *cmd)
{
    if (cmd)
        return (*(enum e_pscmd*)cmd->content);
    else
        return NO_CMD;
}

static void optimize_redundant_pushes(t_psdata *data)
{
    t_list *cur;
    t_list *last;
    int optimizations;

    cur = data->cmds;
    last = cur;
    optimizations = 0;

    while (cur->next)
    {
        if ((get_cmd(cur) == PA && get_cmd(cur->next) == PB) || (get_cmd(cur) == PB && get_cmd(cur->next) == PA))
        {
            last->next = cur->next->next;
            ft_lstdelone(cur->next, free);
            ft_lstdelone(cur, free);
            optimizations++;
        }
        last = last->next;
        cur = last->next;
    }
    if (optimizations)
        optimize_redundant_pushes(data);
}

static void fake_command(t_psdata *data, enum e_pscmd cmd)
{
    if (cmd == PA)
    {
        data->a->size++;
        data->b->size--;
    }
    else if (cmd == PB)
    {
        data->a->size--;
        data->b->size++;
    }
}

static void optimize_rotate(t_psdata *data)
{
    t_list *cur;
    t_list *last_before;
    t_list *first_after;
    enum e_pscmd *cmd;
    int i;

    cur = data->cmds;
    while(cur)
    {
        if (get_cmd(cur->next) == RA)
        {
            last_before = cur;
            cur = cur->next;
            i = 0;
            while (cur && get_cmd(cur) == RA)
            {
                i++;
                cur = cur->next;
            }
            first_after = cur;
            if (i >= (data->a->size - 1) / 2)
            {
                cmd = malloc(sizeof(enum e_pscmd));
                *cmd = RRA;
                cur = last_before->next;
                while (i < data->a->size)
                {
                    cur->next = ft_lstnew(cmd);
                    cur = cur->next;
                    i++;
                }
                cur->next = first_after;
                ft_printf("i: %d\n", i);
            }
        }
        fake_command(data, get_cmd(cur));
        cur = cur->next;
    }
}

void optimize_commands(t_psdata *data)
{
    optimize_redundant_pushes(data);
    optimize_rotate(data);
}
