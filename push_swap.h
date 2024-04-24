/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:59:09 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/24 10:59:05 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>

enum		e_pscmd
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
	RRR,
	NO_CMD
};

typedef struct s_stack
{
	int		*stack;
	int		size;
}			t_stack;

typedef struct s_psdata
{
	t_stack	*a;
	t_stack	*b;
	t_list	*cmds;
}			t_psdata;

t_stack		*create_stack(int argc, char *argv[]);

void		stack_swap(t_stack *stack);
void		stack_push(t_stack *dst_stack, t_stack *src_stack);
void		stack_rotate(t_stack *stack);
void		stack_rrotate(t_stack *stack);
void		stack_print(t_stack *stack);

void		run_command(t_psdata *data, enum e_pscmd cmd);
void		print_commands(t_list *cmds);

int			stack_optimize(t_stack *stack);
void		optimize_commands(t_psdata *data);

void		stack_sort(t_psdata *data);

#endif // PUSH_SWAP_H
