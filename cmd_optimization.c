/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_optimization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:42:34 by dkaiser           #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2024/04/13 17:31:18 by dkaiser          ###   ########.fr       */
=======
/*   Updated: 2024/04/17 09:41:10 by dkaiser          ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

/* void	optimize_commands(t_list **cmds) */
/* { */
/* 	int		optimizations; */
/* 	t_list	*cur; */
/*     t_list *last; */

/* 	optimizations = 0; */
/* 	cur = *cmds; */
/*     last = NULL; */
/* 	while (cur->next) */
/* 	{ */
/* 		if ((*(enum e_pscmd *)cur->content == PA */
/* 				&& *(enum e_pscmd *)cur->next->content == PB) */
/* 			|| (*(enum e_pscmd *)cur->content == PA */
/* 				&& *(enum e_pscmd *)cur->next->content == PB)) */
/* 		{ */
/*             if (last) */
/*                 last->next = cur->next->next; */
/*             else */
/*                 (*cmds)->next = cur->next->next; */
/*             ft_lstdelone(cur->next, free); */
/*             ft_lstdelone(cur, free); */
/*             optimizations++; */
/*         } */
/*         if (!optimizations) */
/*         { */
/*             last = cur; */
/*             cur = cur->next; */
/*         } */
/*         else */
/*             break; */
/* 	} */
/* 	if (optimizations) */
/* 		optimize_commands(cmds); */
/* } */

static enum e_pscmd get_cmd(t_list *cmd)
{
    if (cmd)
        return (*(enum e_pscmd*)cmd->content);
    else
        return NO_CMD;
}

void optimize_commands(t_list **cmds)
{
    t_list *cur;
    t_list *last;
    int optimizations;

    cur = *cmds;
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
<<<<<<< Updated upstream
        optimize_commands(cmds);
=======
        optimize_redundant(data, cmd1, cmd2);
}

static void optimize_two_stack_ops(t_psdata *data, enum e_pscmd cmd1, enum e_pscmd cmd2, enum e_pscmd new_cmd)
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
            last->next = cur->next;
            *(enum e_pscmd*)cur->next->content = new_cmd;
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
        optimize_two_stack_ops(data, cmd1, cmd2, new_cmd);
}

void optimize_commands(t_psdata *data)
{
    optimize_redundant(data, PA, PB);
    optimize_redundant(data, RB, RRB);
    optimize_two_stack_ops(data, RA, RB, RR);
>>>>>>> Stashed changes
}
