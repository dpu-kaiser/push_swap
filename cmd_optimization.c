/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_optimization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:42:34 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/16 17:33:54 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

static enum e_pscmd get_cmd(t_list *cmd)
{
    if (cmd)
        return (*(enum e_pscmd*)cmd->content);
    else
        return NO_CMD;
}

static void optimize_redundant(t_psdata *data, enum e_pscmd cmd1, enum e_pscmd cmd2)
{
    t_list *cur;
    t_list *last;
    int optimizations;

    cur = data->cmds;
    last = cur;
    optimizations = 0;

    if (!cur)
        return ;
    while (cur && cur->next)
    {
        if ((get_cmd(cur) == cmd1 && get_cmd(cur->next) == cmd2) || (get_cmd(cur) == cmd2 && get_cmd(cur->next) == cmd1))
        {
            last->next = cur->next->next;
            ft_lstdelone(cur->next, free);
            ft_lstdelone(cur, free);
            optimizations++;
        }
        last = last->next;
        if (last)
            cur = last->next;
        else
            cur = NULL;
    }
    if (optimizations)
        optimize_redundant(data, cmd1, cmd2);
}

static void lstinsert(t_list *list, t_list *elem)
{
    t_list *next;

    next = list->next;
    list->next = elem;
    elem->next = next;
}

static void fake_command(t_psdata *data, enum e_pscmd cmd)
{
    if (cmd == PA)
    {
        if (data->b->size > 0)
            stack_push(data->a, data->b);
    }
    else if (cmd == PB)
    {
        if (data->a->size > 0)
            stack_push(data->b, data->a);
    }
}

static void optimize_rotate(t_psdata *data)
{
    t_list *cmd;
    t_list *last_before;
    t_list *new_elem;
    enum e_pscmd *rra;
    int ras;
    int i;

    cmd = data->cmds;

    while (cmd)
    {
        ras = 0;
        if (get_cmd(cmd) != RA)
            last_before = cmd;
        while (get_cmd(cmd) == RA)
        {
            ras++;
            cmd = cmd->next;
        }
        if (ras > data->a->size / 2) {
            i = 0;
            while(i++ <= data->a->size)
            {
                rra = malloc(sizeof(enum e_pscmd));
                if (!rra)
                    ft_printf("ERROR!!!");
                *rra = RRA;
                new_elem = ft_lstnew(rra);
                if (!new_elem)
                    ft_printf("AAAAAAAAAAA");
                lstinsert(last_before, new_elem);
            }
        }
        fake_command(data, get_cmd(cmd));
        cmd = cmd->next;
    }
}

void optimize_commands(t_psdata *data)
{
    /* ft_printf("SIZE A: %d\n", data->a->size); */
    optimize_redundant(data, PA, PB);
    optimize_rotate(data);
    optimize_redundant(data, RA, RRA);
}
