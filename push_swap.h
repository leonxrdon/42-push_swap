/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:54:06 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/07/27 16:54:09 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/libft.h"

int		ft_is_sorted(t_list *stack);
int		ft_check(char **argv);
int		ft_check_duplicate(char **argv);
void	ft_free_stack(t_list **stack);
int		ft_get_max(t_list *stack);
t_list	*ft_max_value(t_list *stack);
t_list	*ft_min_value(t_list *stack);
int		ft_key(t_list *stack, int pos);
t_list	*ft_dir(t_list *stack_a, int id_key, int i, int s_len);
t_list	*ft_key_nbr(t_list *stack_a, int key_nbr, int s_len);
void	ft_change_minmax(t_list **stack_a, t_list **stack_b);
t_list	*ft_sort_3(t_list *stack);
t_list	*ft_sort_5(t_list *stack_a, t_list *stack_b);
t_list	*ft_sort_10(t_list *stack_a, t_list *stack_b, int s_len);
t_list	*ft_sort_100(t_list *stack_a, t_list *stack_b, int s_len, t_list *s_ax);
t_list	*ft_sort_500(t_list *stack_a, t_list *stack_b, int s_len, t_list *s_ax);
t_list	*ft_sort(t_list *stack_a, t_list *stack_b, int len, t_list *s_aux);
t_list	*ft_merge_sort(t_list **sorted);
t_list	*ft_lstlast(t_list *head);

int		swap(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);

int		push(t_list **stack_to, t_list **stack_from);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);

int		rotate(t_list **stack);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);

int		rev_rotate(t_list **stack);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

#endif
