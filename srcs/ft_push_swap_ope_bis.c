/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_ope_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 07:49:41 by guderram          #+#    #+#             */
/*   Updated: 2021/11/12 20:20:16 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_swap_ra(t_point *calc)
{
	long	swap;
	int		i;

	swap = calc->a[0];
	i = 0;
	while (calc->nbr > 1 && i < (calc->nbr - 1) && calc->a[i + 1] != 9999999999
		&& calc->a[i] != 9999999999)
	{
		calc->a[i] = calc->a[i + 1];
		i++;
	}
	calc->a[i] = swap;
}

void	ft_swap_rb(t_point *calc)
{
	long	swap;
	int		i;

	swap = calc->b[0];
	i = 0;
	while (calc->nbr > 1 && i < (calc->nbr - 1) && calc->b[i] != 9999999999
		&& calc->b[i + 1] != 9999999999)
	{
		calc->b[i] = calc->b[i + 1];
		i++;
	}
	calc->b[i] = swap;
}

void	ft_swap_rr(t_point *calc)
{
	ft_swap_ra(calc);
	ft_swap_rb(calc);
}
