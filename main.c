/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:03:30 by dkaiser           #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2024/04/15 17:53:19 by dkaiser          ###   ########.fr       */
=======
/*   Updated: 2024/04/17 09:42:43 by dkaiser          ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*pscmds;

	stack_a = create_stack(argc, argv);
	if (!stack_a)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
<<<<<<< Updated upstream

	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
	{
		//free everything
	}
	stack_b->stack = malloc(sizeof(int) * (argc - 1));
	if (!stack_b->stack)
	{
		//free everything
	}
	stack_b->size = 0;
	stack_optimize(stack_a);
	pscmds = stack_sort(stack_a, stack_b);
	/* optimize_commands(&pscmds); */
	print_commands(pscmds);
	ft_printf("\nA: ");
	stack_print(stack_a);
	ft_printf("B: ");
	stack_print(stack_b);
=======
	stack_optimize(data->a);
	stack_sort(data);
	optimize_commands(data);
	print_commands(data->cmds);
	/* ft_printf("\nA: "); */
	/* stack_print(data->a); */
	/* ft_printf("B: "); */
	/* stack_print(data->b); */
>>>>>>> Stashed changes
	return (0);
}
