/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:38:47 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/16 09:27:41 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_cmd_to_queue(t_list **cmds, enum e_pscmd cmd)
{
	t_list			*new_elem;
	enum e_pscmd	*ptr_cmd;

	ptr_cmd = malloc(sizeof(enum e_pscmd));
	if (!ptr_cmd)
		return (1);
    *ptr_cmd = cmd;
	new_elem = ft_lstnew(ptr_cmd);
	if (!new_elem)
	{
		free(ptr_cmd);
		return (1);
	}
	ft_lstadd_back(cmds, new_elem);
	return (0);
}

static void	run_for_both(t_stack *stack_a, t_stack *stack_b,
		void (*f)(t_stack *))
{
	f(stack_a);
	f(stack_b);
}

void	run_command(t_psdata *data, enum e_pscmd cmd)
{
	if (cmd == SA)
		stack_swap(data->a);
	else if (cmd == SB)
		stack_swap(data->b);
	else if (cmd == SS)
		run_for_both(data->a, data->b, stack_swap);
	else if (cmd == PA)
		stack_push(data->a, data->b);
	else if (cmd == PB)
		stack_push(data->b, data->a);
	else if (cmd == RA)
		stack_rotate(data->a);
	else if (cmd == RB)
		stack_rotate(data->b);
	else if (cmd == RR)
		run_for_both(data->a, data->b, stack_rotate);
	else if (cmd == RRA)
		stack_rrotate(data->a);
	else if (cmd == RRB)
		stack_rrotate(data->b);
	else if (cmd == RRR)
		run_for_both(data->a, data->b, stack_rrotate);
	add_cmd_to_queue(&data->cmds, cmd);
}

static void	print_cmd(void *ptr_cmd)
{
	enum e_pscmd	cmd;

	cmd = *(enum e_pscmd *)ptr_cmd;
	if (cmd == SA)
		ft_putendl_fd("sa", 1);
	else if (cmd == SB)
		ft_putendl_fd("sb", 1);
	else if (cmd == SS)
		ft_putendl_fd("ss", 1);
	else if (cmd == PA)
		ft_putendl_fd("pa", 1);
	else if (cmd == PB)
		ft_putendl_fd("pb", 1);
	else if (cmd == RA)
		ft_putendl_fd("ra", 1);
	else if (cmd == RB)
		ft_putendl_fd("rb", 1);
	else if (cmd == RR)
		ft_putendl_fd("rr", 1);
	else if (cmd == RRA)
		ft_putendl_fd("rra", 1);
	else if (cmd == RRB)
		ft_putendl_fd("rrb", 1);
	else if (cmd == RRR)
		ft_putendl_fd("rrr", 1);
}

void	print_commands(t_list *cmds)
{
    ft_lstiter(cmds, print_cmd);
}
