/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:31:49 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/13 14:58:42 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	are_numbers_unique(t_list *stack)
{
	t_list	*cmp_elem;

	while (stack->next)
	{
		cmp_elem = stack->next;
		while (cmp_elem)
		{
			if (*(int *)stack->content == *(int *)cmp_elem->content)
				return (0);
			cmp_elem = cmp_elem->next;
		}
		stack = stack->next;
	}
	return (1);
}

static t_list	*get_stack_from_input(int argc, char *argv[])
{
	t_list	*result;
	t_list	*cur;
	int		*content;

	result = NULL;
	while (argc-- > 1)
	{
		content = malloc(sizeof(int));
		if (content)
		{
			*content = ft_atoi(argv[argc]);
			cur = ft_lstnew(content);
			if (cur)
			{
				ft_lstadd_front(&result, cur);
				continue ;
			}
			free(content);
		}
		ft_lstclear(&result, free);
		return (NULL);
	}
	return (result);
}

t_list	*create_stack(int argc, char *argv[])
{
	t_list	*result;

	if (!is_input_only_nbrs(argc, argv))
		return (NULL);
	result = get_stack_from_input(argc, argv);
	if (!result)
		return (NULL);
	if (!are_numbers_unique(result))
		ft_lstclear(&result, free);
	return (result);
}
