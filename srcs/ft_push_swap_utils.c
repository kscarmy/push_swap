/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 07:50:19 by guderram          #+#    #+#             */
/*   Updated: 2021/09/30 07:50:20 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_long_atoi(const char *nptr)
{
	long	re;
	long	i;
	long	sig;

	i = 0;
	sig = 1;
	re = 0;
	while ((nptr[i] == '\n') || (nptr[i] == '\t') || (nptr[i] == '\v')
		|| (nptr[i] == '\f') || (nptr[i] == '\r') || (nptr[i] == ' '))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sig = -sig;
		i++;
	}
	while ((48 <= nptr[i]) && (nptr[i] <= 57))
	{
		re = (re * 10) + (nptr[i] - 48);
		i++;
	}
	return (re * sig);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_isdigit(int c)
{
	if ((48 <= c) && (c <= 57))
		return (1);
	else
		return (0);
}

void	ft_free_all(t_point *calc)
{
	free(calc->stack);
	calc->stack = NULL;
}

int	ft_exror_free(t_point *calc, int free)
{
	if (free == 1)
		ft_free_all(calc);
	ft_putstr("Error\n");
	return (-1);
}
