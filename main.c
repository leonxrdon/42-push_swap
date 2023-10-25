/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:29:28 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/10/25 12:36:12 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_init(int content, int index)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof (t_list));
	if (new == NULL)
		return (NULL);
	new->index = index;
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_charge_stack(int argc, char **argv)
{
	t_list	*head;
	t_list	*tail;
	int		n;
	int		i;

	head = NULL;
	n = 0;
	i = 1;
	while (i < argc)
	{
		n = ft_atoi(argv[i]);
		if (head == NULL)
			head = ft_init(n, i);
		else
		{
			tail = head;
			while (tail->next != NULL)
				tail = tail->next;
			tail->next = ft_init(n, i);
		}
		i++;
	}
	return (head);
}

t_list	*ft_sort(t_list *stack_a, t_list *stack_b, int s_len, t_list *s_aux)
{
	t_list	*stack;

	stack = NULL;
	if (s_len == 2 || s_len == 3)
		stack = ft_sort_3(stack_a);
	else if (s_len >= 4 && s_len <= 5)
		stack = ft_sort_5(stack_a, stack_b);
	else if (s_len > 5 && s_len <= 11)
		stack = ft_sort_10(stack_a, stack_b, s_len);
	else if (s_len > 11 && s_len <= 100)
		stack = ft_sort_100(stack_a, stack_b, s_len, s_aux);
	else if (s_len > 100 && s_len <= 500)
		stack = ft_sort_500(stack_a, stack_b, s_len, s_aux);
	else if (s_len > 500)
		ft_free_stack(&stack_a);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*s_aux;

	if (argc < 2)
		return (0);
	if (!(ft_check(argv) && ft_check_duplicate(argv)))
		return (0);
	stack_a = ft_charge_stack(argc, argv);
	stack_b = NULL;
	s_aux = NULL;
	if (ft_is_sorted(stack_a))
	{
		ft_free_stack(&stack_a);
		return (0);
	}
	if (ft_lstsize(stack_a) >= 10 && ft_lstsize(stack_a) <= 500)
		s_aux = ft_charge_stack(argc, argv);
	stack_a = ft_sort(stack_a, stack_b, ft_lstsize(stack_a), s_aux);
	if (stack_a != NULL || stack_b != NULL || ft_lstsize(stack_a) == 0)
		ft_free_stack(&stack_a);
	return (0);
}
