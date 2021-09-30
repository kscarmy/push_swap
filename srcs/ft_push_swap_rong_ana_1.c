/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_rong_ana_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 07:50:01 by guderram          #+#    #+#             */
/*   Updated: 2021/09/30 07:50:04 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_reset_c(t_point *calc)
{
	int	i;

	i = 0;
	while (i < calc->nbr)
	{
		calc->c[i] = 9999999999;
		i++;
	}
}

long	ft_rong_dir_c(t_point *calc, long val)
{
	int		i;
	long	i_ret;
	int		sizeb;

	i = 0;
	i_ret = 0;
	sizeb = ft_size_pile(calc, calc->b);
	if (val < calc->min)
		return (ft_found_min_c(calc));
	if (val > calc->max)
		return (ft_found_max_c(calc));
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

long	ft_found_min_c(t_point *calc)
{
	int		i;
	long	ret;
	int		sizeb;

	i = 0;
	sizeb = ft_size_pile(calc, calc->b);
	while (calc->b[i] != 9999999999 && i < sizeb)
	{
		if (calc->b[i] == calc->min)
			ret = i + 1;
		i++;
	}
	return (ft_rong_dir_up_down(calc, ret, calc->b));
}

long	ft_found_max_c(t_point *calc)
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
	return (ft_rong_dir_up_down(calc, ret, calc->b));
}
