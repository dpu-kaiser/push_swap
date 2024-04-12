/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaiser <dkaiser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:03:26 by dkaiser           #+#    #+#             */
/*   Updated: 2024/04/12 17:01:15 by dkaiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_elem)
{
	t_list	*current;

	if (!*lst)
	{
		*lst = new_elem;
		return ;
	}
	current = *lst;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new_elem;
}
