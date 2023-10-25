/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:03:02 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/07/27 17:03:04 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *head)
{
	t_list	*aux;

	if (!head)
		return (NULL);
	aux = head;
	while (aux -> next)
	{
		aux = aux -> next;
		if (aux->next == NULL)
			return (aux);
	}
	return (aux);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*p;
	int		i;

	i = 0;
	p = lst;
	while (p != NULL)
	{
		i++;
		p = p -> next;
	}
	return (i);
}

t_list	*ft_get_end(t_list *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_list	*ft_get_prev_end(t_list *stack)
{
	while (stack && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
