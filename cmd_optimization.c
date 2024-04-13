/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_optimization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:42:34 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/13 17:31:18 by dkaiser          ###   ########.fr       */
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
        optimize_commands(cmds);
}
