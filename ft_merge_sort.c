/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:39:21 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/10/25 12:39:26 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*merge(t_list *left, t_list *right)
{
	t_list	*result;

	result = NULL;
	if (left == NULL)
		return (right);
	else if (right == NULL)
		return (left);
	if (left->content <= right->content)
	{
		result = left;
		result->next = merge(left->next, right);
	}
	else
	{
		result = right;
		result->next = merge(left, right->next);
	}
	return (result);
}

void	split(t_list *head, t_list **left, t_list **right)
{
	t_list	*fast;
	t_list	*slow;

	slow = head;
	fast = head->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*left = head;
	*right = slow->next;
	slow->next = NULL;
}

t_list	*ft_merge_sort(t_list **sorted)
{
	t_list	*head;
	t_list	*left;
	t_list	*right;

	head = *sorted;
	if (head == NULL || head->next == NULL)
		return (head);
	split(head, &left, &right);
	ft_merge_sort(&left);
	ft_merge_sort(&right);
	*sorted = merge(left, right);
	return (*sorted);
}
