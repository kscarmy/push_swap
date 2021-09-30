/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_rong_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 07:49:56 by guderram          #+#    #+#             */
/*   Updated: 2021/09/30 10:13:55 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_size_pile(t_point *calc, long *stack)
{
	int	i;

	i = 0;
	while (stack[i] != 9999999999 && i < calc->nbr)
		i++;
	return (i);
}

long	ft_a_found_min(t_point *calc)
{
	int		i;
	long	ret;
	int		sizeb;

	i = 0;
	sizeb = ft_size_pile(calc, calc->a);
	ret = 0;
	while (calc->a[i] != 9999999999 && i < sizeb)
	{
		if (calc->a[i] == calc->min)
			ret = i + 1;
		i++;
	}
	return (ft_rong_dir_up_down(calc, ret, calc->a));
}

long	ft_b_found_min(t_point *calc)
{
	int		i;
	long	ret;
	int		sizeb;

	i = 0;
	sizeb = ft_size_pile(calc, calc->b);
	ret = 0;
	while (calc->b[i] != 9999999999 && i < sizeb)
	{
		if (calc->b[i] == calc->min)
			ret = i + 1;
		i++;
	}
	calc->min = calc->a[0];
	return (ft_rong_dir_up_down(calc, ret, calc->b));
}
