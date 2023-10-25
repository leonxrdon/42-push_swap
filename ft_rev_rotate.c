/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:34:52 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/10/25 12:34:54 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rev_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*tail;
	t_list	*new_tail;

	tail = ft_get_end(*stack);
	new_tail = ft_get_prev_end(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	new_tail->next = NULL;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (rev_rotate(stack_a) == -1)
		return (0);
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (rev_rotate(stack_b) == -1)
		return (-1);
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (rev_rotate(stack_a) == -1 || rev_rotate(stack_b) == -1)
		return (-1);
	write(1, "rrr\n", 4);
	return (0);
}
