/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_rong_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 07:48:13 by guderram          #+#    #+#             */
/*   Updated: 2021/09/30 10:14:00 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_b_found_max(t_point *calc)
{
	int		i;
	long	ret;
	int		sizeb;

	i = 0;
	sizeb = ft_size_pile(calc, calc->b);
	while (calc->b[i] != 9999999999 && i < sizeb)
	{
		if (calc->b[i] == calc->max)
			ret = i;
		i++;
	}
	calc->max = calc->a[0];
	return (ft_rong_dir_up_down(calc, ret, calc->b));
}

long	ft_rong_dir_up_down(t_point *calc, long ret, long *stack)
{
	long	sizeb;

	sizeb = ft_size_pile(calc, stack);
	if (ret < (sizeb - ret))
	{
		return (ret);
	}
	else
	{
		return ((sizeb - ret) * -1);
	}
	return (0);
}

long	ft_rong_dir(t_point *calc, long val)
{
	int		i;
	long	i_ret;
	int		sizeb;

	i = 0;
	i_ret = 0;
	sizeb = ft_size_pile(calc, calc->b);
	if (val < calc->min)
		return (ft_b_found_min(calc));
	if (val > calc->max)
		return (ft_b_found_max(calc));
	while (calc->b[i] != 9999999999 && i <= sizeb)
	{
		if (val > calc->b[i])
			i_ret = i;
		i++;
	}
	i = 0;
	while (calc->b[i] != 9999999999 && i <= sizeb)
	{
		if (val > calc->b[i] && calc->b[i_ret] < calc->b[i])
			i_ret = i;
		i++;
	}
	return (ft_rong_dir_up_down(calc, i_ret, calc->b));
}

void	ft_a_to_b(t_point *calc)
{
	long	dir;

	dir = ft_rong_dir(calc, calc->a[0]);
	while (dir > 0)
	{
		ft_swap_rb(calc);
		calc->algo[calc->head] = 7;
		calc->head = calc->head + 1;
		dir--;
	}
	while (dir < 0)
	{
		ft_swap_rrb(calc);
		calc->algo[calc->head] = 10;
		calc->head = calc->head + 1;
		dir++;
	}
	if (dir == 0)
	{
		ft_swap_pb(calc);
		calc->algo[calc->head] = 5;
		calc->head = calc->head + 1;
	}
	else
		ft_putstr("ERROR IN ring-ft_a_to_b\n");
}
