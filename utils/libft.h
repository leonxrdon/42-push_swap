/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:03:17 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/07/27 17:03:20 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

int		ft_is_sign(int c);
int		ft_is_digit(int c);
int		ft_atoi(const char *str);
int		ft_lstsize(t_list *lst);
int		ft_strcmp(char *s1, char *s2);
void	ft_lstprint(t_list *head);
void	ft_putnbr_fd(int nb, int fd);
t_list	*ft_lstnew(int content);
t_list	*ft_get_prev_end(t_list *stack);
t_list	*ft_get_end(t_list *stack);

#endif
