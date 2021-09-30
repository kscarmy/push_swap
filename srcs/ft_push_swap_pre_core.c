/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_pre_core.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 07:49:48 by guderram          #+#    #+#             */
/*   Updated: 2021/09/30 10:15:32 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_found_min(long *str, t_point *calc)
{
	int		i;
	long	min;

	i = 0;
	min = str[i];
	while (i < calc->nbr)
	{
		if (str[i] < min)
			min = str[i];
		i++;
	}
	return (min);
}

long	ft_found_with_min(long *str, long min, t_point *calc)
{
	int	i;
	int	sup;

	i = 0;
	while (str[i] <= min && i < calc->nbr)
		i++;
	sup = str[i];
	i = 0;
	while (i < calc->nbr)
	{
		if (str[i] > min && str[i] < sup)
			sup = str[i];
		i++;
	}
	return (sup);
}

int	ft_is_doublon(t_point *calc)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (i < calc->nbr)
	{
		while (u < calc->nbr)
		{
			if (i != u && calc->stack[u] == calc->stack[i])
			{
				return (0);
			}
			u++;
		}
		u = 0;
		i++;
	}
	return (1);
}

int	ft_make_res(t_point *calc)
{
	int		i;
	long	min;

	i = 1;
	if (ft_is_doublon(calc) == 0)
	{
		return (0);
	}
	min = ft_found_min(calc->stack, calc);
	calc->res[0] = min;
	while (i < calc->nbr)
	{
		calc->res[i] = ft_found_with_min(calc->stack, calc->res[i - 1], calc);
		i++;
	}
	return (1);
}

int	ft_is_a_good(t_point *calc)
{
	int	i;

	i = 0;
	while (calc->a[i] == calc->res[i] && i < calc->nbr)
		i++;
	if (i == calc->nbr)
		return (2);
	return (1);
}
