/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_brute_bis.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:15:18 by guderram          #+#    #+#             */
/*   Updated: 2021/11/13 16:18:14 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_reset_a_b(t_point *calc)
{
	int	i;

	i = 0;
	while (i < (calc->nbr))
	{
		calc->a[i] = calc->stack[i];
		calc->b[i] = 9999999999;
		i++;
	}
	calc->a[i] = '\0';
	calc->b[i] = '\0';
}
