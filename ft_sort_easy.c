/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_easy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:38:22 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/10/25 12:38:23 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_sort_3(t_list	*stack)
{
	int		max;
	t_list	*tmp;

	max = ft_get_max(stack);
	tmp = stack;
	if (tmp->content == max)
		ra(&tmp);
	else if (tmp->next->content == max)
		rra(&tmp);
	if (tmp->content > tmp->next->content)
		sa(&tmp);
	return (tmp);
}

t_list	*ft_sort_5(t_list	*stack_a, t_list	*stack_b)
{
	stack_a = ft_min_value(stack_a);
	if (ft_is_sorted(stack_a))
		return (stack_a);
	pb(&stack_a, &stack_b);
	stack_a = ft_min_value(stack_a);
	pb(&stack_a, &stack_b);
	if (!ft_is_sorted(stack_a))
		stack_a = ft_sort_3(stack_a);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	return (stack_a);
}

t_list	*ft_sort_10(t_list *stack_a, t_list *stack_b, int s_len)
{
	int	i;

	i = 0;
	while (i < (s_len - 3))
	{
		stack_a = ft_min_value(stack_a);
		pb(&stack_a, &stack_b);
		i++;
	}
	if (!ft_is_sorted(stack_a))
		stack_a = ft_sort_3(stack_a);
	while (i > 0)
	{
		pa(&stack_a, &stack_b);
		--i;
	}
	return (stack_a);
}
