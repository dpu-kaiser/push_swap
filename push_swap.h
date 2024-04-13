/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:59:09 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/13 15:27:07 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>

enum	e_pscmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

t_list	*create_stack(int argc, char *argv[]);

void	stack_swap(t_list **stack);
void	stack_push(t_list **dst_stack, t_list **src_stack);
void	stack_rotate(t_list **stack);
void	stack_rrotate(t_list **stack);

void	run_command(t_list **stack_a, t_list **stack_b, t_list **cmds,
			enum e_pscmd cmd);
void	print_commands(t_list *cmds);

void	stack_optimize(t_list **stack);

void	stack_sort(t_list **stack_a, t_list **stack_b, t_list **cmds);

#endif // PUSH_SWAP_H
