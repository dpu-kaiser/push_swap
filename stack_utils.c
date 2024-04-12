/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 20:31:30 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/12 20:50:17 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	stack_swap(t_list **stack)
{
	t_list	*first_elem;

	first_elem = *stack;
	*stack = (*stack)->next;
	first_elem->next = (*stack)->next;
	(*stack)->next = first_elem;
}

void	stack_push(t_list **dst_stack, t_list **src_stack)
{
	t_list	*elem;

	elem = *src_stack;
	*src_stack = elem->next;
	ft_lstadd_front(dst_stack, elem);
}

void	stack_rotate(t_list **stack)
{
	t_list	*first_elem;

	first_elem = *stack;
	*stack = (*stack)->next;
	first_elem->next = NULL;
	ft_lstlast(*stack)->next = first_elem;
}

void	stack_rrotate(t_list **stack)
{
    t_list *first_elem;

    first_elem = *stack;
    while((*stack)->next->next)
        *stack = (*stack)->next;
    (*stack)->next->next = first_elem;
    (*stack)->next = NULL;
}
