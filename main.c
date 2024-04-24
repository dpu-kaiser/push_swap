/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:03:30 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/24 10:58:59 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "push_swap.h"

static void	free_data(t_psdata *data)
{
	if (data)
	{
		if (data->a)
		{
			if (data->a->stack)
				free(data->a->stack);
			free(data->a);
		}
		if (data->b)
		{
			if (data->b->stack)
				free(data->b->stack);
			free(data->b);
		}
		free(data);
	}
}

static t_psdata	*initialize_data(int argc, char *argv[])
{
	t_psdata	*result;

	result = malloc(sizeof(t_psdata));
	if (result)
	{
		result->a = create_stack(argc, argv);
		if (result->a)
		{
			result->b = malloc(sizeof(t_stack));
			if (result->b)
			{
				result->b->stack = malloc(sizeof(int) * (argc - 1));
				if (result->b->stack)
				{
					result->b->size = 0;
					return (result);
				}
			}
		}
	}
	free_data(result);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_psdata	*data;

	data = initialize_data(argc, argv);
	if (!data)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	stack_optimize(data->a);
	stack_sort(data);
	optimize_commands(data);
	print_commands(data->cmds);
	/* ft_printf("\nA: "); */
	/* stack_print(data->a); */
	/* ft_printf("B: "); */
	/* stack_print(data->b); */
	return (0);
}
