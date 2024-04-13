/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:03:30 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/13 14:52:31 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_content(void *content)
{
	ft_printf("%d\n", *(int *)content);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list *stack_b;
	t_list *pscmds;

	stack_a = create_stack(argc, argv);
	if (!stack_a)
	{
		ft_putendl_fd("Error", 2);
		return 1;
	}
	stack_b = NULL;
	pscmds = NULL;

	// TODO: Optimize commands
	print_commands(pscmds);
	return 0;
}
