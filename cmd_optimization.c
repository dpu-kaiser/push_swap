/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_optimization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:42:34 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/26 13:55:55 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

static enum e_pscmd	get_cmd(t_list *cmd)
{
	if (cmd)
		return (*(enum e_pscmd *)cmd->content);
	else
		return (NO_CMD);
}

static void	optimize_redundant(t_psdata *data, enum e_pscmd cmd1,
		enum e_pscmd cmd2)
{
	t_list	*cur;
	t_list	*last;
	int		optimizations;

	cur = data->cmds;
	last = cur;
	optimizations = 0;
	while (cur && cur->next)
	{
		if ((get_cmd(cur) == cmd1 && get_cmd(cur->next) == cmd2)
			|| (get_cmd(cur) == cmd2 && get_cmd(cur->next) == cmd1))
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

static void	optimize_two_stack_ops(t_psdata *data, enum e_pscmd cmd1,
		enum e_pscmd cmd2, enum e_pscmd new_cmd)
{
	t_list	*cur;
	t_list	*last;
	int		optimizations;

	cur = data->cmds;
	last = cur;
	optimizations = 0;
	while (cur && cur->next)
	{
		if ((get_cmd(cur) == cmd1 && get_cmd(cur->next) == cmd2)
			|| (get_cmd(cur) == cmd2 && get_cmd(cur->next) == cmd1))
		{
			last->next = cur->next;
			*(enum e_pscmd *)cur->next->content = new_cmd;
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

void	optimize_commands(t_psdata *data)
{
	optimize_redundant(data, PA, PB);
	optimize_redundant(data, RB, RRB);
	optimize_two_stack_ops(data, RA, RB, RR);
}
