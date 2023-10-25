/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:38:08 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/10/25 12:38:10 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_change_minmax(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	while (tmp_a != NULL)
	{
		tmp_a = ft_min_value(tmp_a);
		pb(&tmp_a, &tmp_b);
	}
	while (tmp_b != NULL)
	{
		tmp_b = ft_max_value(tmp_b);
		pa(&tmp_a, &tmp_b);
	}
	*stack_a = tmp_a;
	*stack_b = tmp_b;
}

t_list	*ft_sort_500(t_list *stack_a, t_list *stack_b, int s_len, t_list *s_ax)
{
	int		key_nbr;
	int		pos;
	int		size;
	int		i;
	t_list	*stack_sort;

	pos = s_len / 8;
	size = s_len / 8;
	i = 0;
	stack_sort = ft_merge_sort(&s_ax);
	while (pos < s_len - size + 1)
	{
		key_nbr = ft_key(stack_sort, pos);
		while (i < size)
		{
			stack_a = ft_key_nbr(stack_a, key_nbr, s_len);
			pb(&stack_a, &stack_b);
			i++;
		}
		i = 0;
		pos = pos + size;
	}
	ft_change_minmax(&stack_a, &stack_b);
	ft_free_stack(&s_ax);
	return (stack_a);
}
