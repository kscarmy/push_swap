/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_rong_ana.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 07:50:08 by guderram          #+#    #+#             */
/*   Updated: 2021/10/08 04:48:07 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_pre_set_a(t_point *calc)
{
	long	min;

	min = ft_set_c(calc);
	while (min != 0)
	{
		if (min > 0)
		{
			ft_swap_ra(calc);
			calc->algo[calc->head] = 6;
			calc->head = calc->head + 1;
			min--;
		}
		else
		{
			ft_swap_rra(calc);
			calc->algo[calc->head] = 9;
			calc->head = calc->head + 1;
			min++;
		}
	}
}

long	ft_set_c(t_point *calc)
{
	int	i;

	i = 0;
	if (calc->c[0] != 9999999999)
		ft_reset_c(calc);
	ft_pre_set_c(calc);
	while (calc->a[i] != 9999999999 && i < calc->nbr)
	{
		if (ft_rong_dir_c(calc, calc->a[i]) < 0)
			calc->c[i] = calc->c[i] + (ft_rong_dir_c(calc, calc->a[i]) * -1);
		else
			calc->c[i] = calc->c[i] + ft_rong_dir_c(calc, calc->a[i]);
		i++;
	}
	return (ft_c_found_min(calc));
}

long	ft_c_found_min(t_point *calc)
{
	int		i;
	long	ret;
	int		size;
	long	min;

	i = 0;
	ret = calc->c[0];
	min = 0;
	size = ft_size_pile_end(calc, calc->c);
	while (calc->c[i] != 9999999999 && i < size)
	{
		if (calc->c[i] < ret)
		{
			ret = calc->c[i];
			min = i;
		}
		i++;
	}
	if (min < (size - min))
		return (min);
	else
		return ((size - min) * -1);
}

void	ft_pre_set_c(t_point *calc)
{
	int	size;
	int	i;

	size = ft_size_pile(calc, calc->a);
	i = 0;
	while (i < ((size / 2) + 1))
	{
		calc->c[i] = i;
		calc->c[size - i] = i;
		i++;
	}
}
