/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_rong.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 07:50:12 by guderram          #+#    #+#             */
/*   Updated: 2021/09/30 10:15:07 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_init_rong(t_point *calc)
{
	ft_swap_pb(calc);
	calc->algo[calc->head] = 5;
	calc->head = calc->head + 1;
	ft_swap_pb(calc);
	calc->algo[calc->head] = 5;
	calc->head = calc->head + 1;
	if (calc->b[0] > calc->b[1])
	{
		calc->min = calc->b[1];
		calc->max = calc->b[0];
	}
	else
	{
		calc->min = calc->b[0];
		calc->max = calc->b[1];
		ft_swap_rb(calc);
		calc->algo[calc->head] = 7;
		calc->head = calc->head + 1;
	}
}

int	ft_the_rong(t_point *calc)
{
	int	h;
	int	mi;

	h = 0;
	calc->head = 0;
	ft_init_rong(calc);
	while (calc->a[0] != 9999999999 && h < calc->nbr)
	{
		ft_pre_set_a(calc);
		ft_a_to_b(calc);
		h++;
	}
	h = 0;
	while (calc->b[0] != 9999999999 && h < (calc->nbr))
	{
		ft_swap_pa(calc);
		calc->algo[calc->head] = 4;
		calc->head = calc->head + 1;
		h++;
	}
	mi = ft_a_found_min(calc);
	mi--;
	return (ft_the_rong_1(calc, mi));
}

int	ft_the_rong_1(t_point *calc, int mi)
{
	while (mi != 0)
	{
		if (mi > 0)
		{
			ft_swap_ra(calc);
			calc->algo[calc->head] = 6;
			calc->head = calc->head + 1;
			mi--;
		}
		else
		{
			ft_swap_rra(calc);
			calc->algo[calc->head] = 9;
			calc->head = calc->head + 1;
			mi++;
		}
	}
	return (1);
}

void	ft_init_b_min_max(t_point *calc)
{
	if (calc->b[0] < calc->b[1])
	{
		ft_swap_rb(calc);
		calc->algo[calc->head] = 7;
		calc->head = calc->head + 1;
	}
	calc->max = calc->b[0];
	calc->min = calc->b[1];
}
