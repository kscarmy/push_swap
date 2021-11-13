/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_ope_bibis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 07:49:37 by guderram          #+#    #+#             */
/*   Updated: 2021/11/12 20:26:09 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_swap_rra(t_point *calc)
{
	int		i;
	long	swap;

	i = 0;
	while (calc->a[i + 1] != 9999999999 && calc->a[i] != 9999999999
		&& i < (calc->nbr - 1))
		i++;
	swap = calc->a[i];
	while (i > 0)
	{
		calc->a[i] = calc->a[i - 1];
		i--;
	}
	calc->a[0] = swap;
}

void	ft_swap_rrb(t_point *calc)
{
	int		i;
	long	swap;

	i = 0;
	while (calc->b[i + 1] != 9999999999 && calc->b[i] != 9999999999
		&& i < (calc->nbr - 1))
		i++;
	swap = calc->b[i];
	while (i > 0)
	{
		calc->b[i] = calc->b[i - 1];
		i--;
	}
	calc->b[0] = swap;
}

void	ft_swap_rrr(t_point *calc)
{
	ft_swap_rra(calc);
	ft_swap_rrb(calc);
}
