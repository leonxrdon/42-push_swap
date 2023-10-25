/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:37:55 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/10/25 12:37:57 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_key(t_list *stack, int pos)
{
	t_list	*findk;
	int		i;
	int		key_nbr;

	key_nbr = 0;
	findk = stack;
	i = 1;
	while (i < pos)
	{
		findk = findk->next;
		i++;
	}
	key_nbr = findk->content;
	return (key_nbr);
}

t_list	*ft_dir(t_list *stack_a, int id_key, int i, int s_len)
{
	if (id_key > s_len / 2)
	{
		while (id_key < i)
		{
			rra(&stack_a);
			id_key++;
		}
	}
	else
	{
		while (id_key > 0)
		{
			ra(&stack_a);
			id_key--;
		}
	}
	return (stack_a);
}

t_list	*ft_key_nbr(t_list *stack_a, int key_nbr, int s_len)
{
	int		id_key;
	t_list	*search_a;
	int		i;

	id_key = 0;
	i = 0;
	search_a = stack_a;
	while (search_a != NULL)
	{
		i++;
		if (search_a->content <= key_nbr)
			break ;
		id_key++;
		search_a = search_a->next;
	}
	if (id_key == 0)
		return (stack_a);
	stack_a = ft_dir(stack_a, id_key, i, s_len);
	return (stack_a);
}

t_list	*ft_sort_100(t_list *stack_a, t_list *stack_b, int s_len, t_list *s_ax)
{
	t_list	*stack_sort;
	int		keynbr;
	int		pos;
	int		size;
	int		i;

	pos = s_len / 4;
	size = s_len / 4;
	i = 0;
	stack_sort = ft_merge_sort(&s_ax);
	while (pos < s_len - size + 1)
	{
		keynbr = ft_key(stack_sort, pos);
		while (i < size)
		{
			stack_a = ft_key_nbr(stack_a, keynbr, s_len);
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
