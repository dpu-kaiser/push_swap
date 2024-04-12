/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:03:30 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/12 18:49:56 by dkaiser          ###   ########.fr       */
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
	ft_lstiter(stack_a, print_content);
	if (!stack_a)
		return 1; // TODO: Print error message

	// TODO: Sort stack
	// TODO: Optimize commands
	// TODO: Print commands
}
