/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnarvaez <lnarvaez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:04:56 by lnarvaez          #+#    #+#             */
/*   Updated: 2023/10/25 13:04:59 by lnarvaez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_sign(int c)
{
	if (c == '-')
		return (1);
	else
		return (0);
}

int	ft_is_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	n;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		i++;
		if (str[i] == '-' || (!ft_is_digit(str[i])))
			exit(EXIT_FAILURE);
		sign *= -1;
	}
	while (ft_is_digit(str[i]))
	{
		n = (str[i++] - '0') + (n * 10);
		if (str[i] == '-')
			exit(EXIT_FAILURE);
	}
	if (n > INT_MAX || n < INT_MIN)
		exit(EXIT_FAILURE);
	return (n * sign);
}

void	ft_putnbr_fd(int nb, int fd)
{
	long	nbr;
	char	c;

	nbr = nb;
	if (nbr >= -2147483648 && nbr <= 2147483647)
	{
		if (nbr < 0)
		{
			write (fd, "-", 1);
			nbr = nbr * -1;
		}
		if (nbr >= 10)
		{
			ft_putnbr_fd(nbr / 10, fd);
			nbr = nbr % 10;
		}
		if (nbr < 10)
		{
			c = nbr + '0';
			write (fd, &c, 1);
		}
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
