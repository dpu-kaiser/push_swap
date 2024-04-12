/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:03:30 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/12 18:55:38 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	print_content(void *content)
{
	ft_printf("%d\n", *(int *)content);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;

	stack_a = create_stack(argc, argv);
	if (!stack_a)
	{
		ft_putendl_fd("Error", 2);
		return 1;
	}

	ft_lstiter(stack_a, print_content);

	// TODO: Sort stack
	// TODO: Optimize commands
	// TODO: Print commands

	return 0;
}
