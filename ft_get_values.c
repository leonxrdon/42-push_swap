/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:15:59 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/10/25 16:16:01 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_direction(t_list *stack, int max_i, int i)
{
	if (max_i > i / 2)
	{
		while (max_i < i)
		{
			rrb(&stack);
			max_i++;
		}
	}
	else
	{
		while (max_i > 0)
		{
			rb(&stack);
			max_i--;
		}
	}
	return (stack);
}

t_list	*ft_max_value(t_list *stack)
{
	int		maxval;
	t_list	*tmp;
	int		i;
	int		max_i;

	max_i = -1;
	i = 0;
	tmp = stack;
	maxval = INT_MIN;
	while (tmp != NULL)
	{
		if (tmp->content > maxval)
		{
			maxval = tmp->content;
			max_i = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (max_i == 0)
		return (stack);
	stack = ft_direction(stack, max_i, i);
	return (stack);
}

t_list	*dir(t_list *stack, int min_i, int i)
{
	if (min_i > i / 2)
	{
		while (min_i < i)
		{
			rra(&stack);
			min_i++;
		}
	}
	else
	{
		while (min_i > 0)
		{
			ra(&stack);
			min_i--;
		}
	}
	return (stack);
}

t_list	*ft_min_value(t_list *stack)
{
	int		minval;
	t_list	*tmp;
	int		i;
	int		min_i;

	min_i = -1;
	i = 0;
	tmp = stack;
	minval = INT_MAX;
	while (tmp != NULL)
	{
		if (tmp->content < minval)
		{
			minval = tmp->content;
			min_i = i;
		}
		tmp = tmp->next;
		i++;
	}
	if (min_i == 0)
		return (stack);
	stack = dir(stack, min_i, i);
	return (stack);
}

int	ft_get_max(t_list *stack)
{
	int		max;
	t_list	*tmp;

	max = stack->content;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}
