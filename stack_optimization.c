/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:25:05 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/15 12:03:44 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int size, int *tmp_array)
{
	int	i;
	int	k;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		k = i + 1;
		while (k < size)
		{
			if (tmp_array[i] > tmp_array[k])
			{
				tmp = tmp_array[i];
				tmp_array[i] = tmp_array[k];
				tmp_array[k] = tmp;
			}
			k++;
		}
		i++;
	}
}

static void	override_stack(t_list **stack, int *tmp_array)
{
	t_list	*cur;
	int		content;
	int		i;

	cur = *stack;
	while (cur)
	{
		i = 0;
		content = *(int *)cur->content;
		while (content != tmp_array[i])
			i++;
		*(int *)cur->content = i;
		cur = cur->next;
	}
}

int	stack_optimize(t_list **stack)
{
	int		size;
	int		*tmp_array;
	t_list	*cur;
	int		i;

	size = ft_lstsize(*stack);
	cur = *stack;
	tmp_array = malloc(size * sizeof(int));
	if (!tmp_array)
		return 1;
	i = 0;
	while (cur)
	{
		tmp_array[i++] = *(int *)cur->content;
		cur = cur->next;
	}
	if (i != size)
	{
		free(tmp_array);
		return 1;
	}
	sort_array(size, tmp_array);
	i = 0;
	override_stack(stack, tmp_array);
	return 0;
}
