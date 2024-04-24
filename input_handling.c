/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:31:49 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/24 10:59:24 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	is_nbr(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			str++;
		else
			return (0);
	}
	return (1);
}

static int	is_input_only_nbrs(int argc, char *argv[])
{
	while (argc-- > 1)
	{
		if (!is_nbr(argv[argc]))
			return (0);
	}
	return (1);
}

static int	are_numbers_unique(int *stack, int size)
{
	int	i;
	int	k;

	i = 0;
	while (i < size - 1)
	{
		k = i + 1;
		while (k < size)
		{
			if (stack[i] == stack[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

static int	*get_array_from_input(int argc, char *argv[])
{
	int	*stack;
	int	i;

	stack = malloc(sizeof(int) * (argc - 1));
	if (!stack)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stack);
}

t_stack	*create_stack(int argc, char *argv[])
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	if (!is_input_only_nbrs(argc, argv))
		return (free(result), NULL);
	result->stack = get_array_from_input(argc, argv);
	if (!result->stack)
		return (free(result), NULL);
	if (!are_numbers_unique(result->stack, argc - 1))
	{
		free(result->stack);
		free(result);
		return (NULL);
	}
	result->size = argc - 1;
	return (result);
}
