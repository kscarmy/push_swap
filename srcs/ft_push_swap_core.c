/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_core.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 07:49:33 by guderram          #+#    #+#             */
/*   Updated: 2021/11/10 19:34:38 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_swap_trad_2(t_point *calc, int i)
{
	if (calc->algo[i] == 6)
		ft_putstr("ra\n");
	if (calc->algo[i] == 7)
		ft_putstr("rb\n");
	if (calc->algo[i] == 8)
		ft_putstr("rr\n");
	if (calc->algo[i] == 9)
		ft_putstr("rra\n");
	if (calc->algo[i] == 10)
		ft_putstr("rrb\n");
	if (calc->algo[i] == 11)
		ft_putstr("rrr\n");
}

void	ft_swap_tradrun_2(t_point *calc, int i)
{
	if (calc->algo[i] == 6)
		ft_swap_ra(calc);
	if (calc->algo[i] == 7)
		ft_swap_rb(calc);
	if (calc->algo[i] == 8)
		ft_swap_rr(calc);
	if (calc->algo[i] == 9)
		ft_swap_rra(calc);
	if (calc->algo[i] == 10)
		ft_swap_rrb(calc);
	if (calc->algo[i] == 11)
		ft_swap_rrr(calc);
}

int	ft_is_int(t_point *calc)
{
	int	i;

	i = 0;
	while (i < calc->nbr)
	{
		if (calc->stack[i] < -2147483648)
			return (0);
		if (calc->stack[i] > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

void	ft_swap_trad(t_point *calc)
{
	int	i;

	i = 0;
	while (calc->algo[i] != 9999999999 && i < (calc->nbr * 25))
	{
		if (calc->algo[i] == 1)
			ft_putstr("sa\n");
		if (calc->algo[i] == 2)
			ft_putstr("sb\n");
		if (calc->algo[i] == 3)
			ft_putstr("ss\n");
		if (calc->algo[i] == 4)
			ft_putstr("pa\n");
		if (calc->algo[i] == 5)
			ft_putstr("pb\n");
		ft_swap_trad_2(calc, i);
		i++;
	}
}

int	ft_swap_core(t_point *calc)
{
	int	ret;

	ret = ft_init_stacks(calc);
	if (ret == 1)
		ret = ft_is_int(calc);
	if (ret == 1)
		ret = ft_make_res(calc);
	if (ret == 1)
		ret = ft_is_a_good(calc);
	if (calc->nbr > 1 && calc->nbr < 6)
	{
		// printf("brute\n");
		ft_brute(calc);
	}
	if (ret == 1 && calc->nbr > 5)
	{
		// printf("the rong\n");
		ret = ft_the_rong(calc);
	}
	if (ret == 1 && calc->nbr > 1)
		ft_swap_trad(calc);
	ft_free_stacks(calc);
	return (ret);
}
