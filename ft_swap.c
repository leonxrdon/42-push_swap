/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:34:21 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/10/25 12:34:23 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_content;
	int		tmp_index;

	if (ft_lstsize(*stack) <= 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		exit(EXIT_FAILURE);
	tmp_content = head->content;
	tmp_index = head->index;
	head->content = next->content;
	head->index = next->index;
	next->content = tmp_content;
	next->index = tmp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) == -1)
		return (-1);
	write (1, "sa\n", 3);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (swap(stack_b) == -1)
		return (-1);
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write (1, "ss\n", 3);
	return (0);
}
