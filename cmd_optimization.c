/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_optimization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:42:34 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/16 10:32:28 by dkaiser          ###   ########.fr       */
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

void optimize_commands(t_psdata *data)
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
        optimize_commands(data);
}
