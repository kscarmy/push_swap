/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_brute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:17:24 by guderram          #+#    #+#             */
/*   Updated: 2021/11/10 20:03:12 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_swap_tradrun_1(t_point *calc, int i)
{
	if (calc->algo[i] == 1)
		ft_swap_sa(calc);
	if (calc->algo[i] == 2)
		ft_swap_sb(calc);
	if (calc->algo[i] == 3)
		ft_swap_ss(calc);
	if (calc->algo[i] == 4)
		ft_swap_pa(calc);
	if (calc->algo[i] == 5)
		ft_swap_pb(calc);
	ft_swap_tradrun_2(calc, i);
}

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
	// printf("ex res\n");
}

void	ft_incre_algo(t_point *calc)
{
	int	i;

	i = 0;
	while (i >= 0 && i < ((calc->nbr * 3) * 11) && calc->algo[i] != 9999999999)
	{

		if (calc->algo[i + 1] == 9999999999 && calc->algo[i] < 11)
		{
			calc->algo[i] = calc->algo[i] + 1;
			i = -10;
		}
		else if (calc->algo[i] >= 11 && calc->algo[i + 1] != 9999999999)
		{
			// calc->algo[i + 1] = calc->algo[i + 1] + 1;
			calc->algo[i] = 1;
		}
		else if (calc->algo[i] >= 11 && calc->algo[i + 1] == 9999999999)
		{
			calc->algo[i + 1] = 0;
			calc->algo[i] = 1;
		}
		else if (calc->algo[i] < 11)
		{
			calc->algo[i] = calc->algo[i] + 1;
			i = -10;
		}
		if (calc->algo[i] >= 11 &&  calc->algo[i + 1] != 9999999999) // reset les == 11
		{
			
			while (calc->algo[i] == 11)
			{
				calc->algo[i] = 1;
				i--;
			}
			i = -10;
		}
		i++;
		
	}
	i = 0;
	while (calc->algo[i] != 9999999999)
	{
		// printf("[%ld]", calc->algo[i]);
		i++;
	}
	// printf("\n");
}

void	ft_apply_brute(t_point *calc)
{
	int i;

	i = 0;
	while (i < ((calc->nbr * 3) * 11) && calc->algo[i] != 9999999999)
	{
		ft_swap_tradrun_1(calc, i);
		i++;
	}
}

void	ft_brute(t_point *calc)
{
	int i;

	i = 0;
	if (calc->algo[i] == 9999999999)
		calc->algo[i] = 1;
	ft_apply_brute(calc);
	// printf("A\n");
	if (ft_is_a_good(calc) == 1)
		ft_reset_a_b(calc);
	// printf("B\n");
	while (ft_is_a_good(calc) == 1) // supp i <
	{
		// printf("C\n");
		if (ft_is_a_good(calc) == 1)
		{
			ft_reset_a_b(calc);
			ft_incre_algo(calc);
		}
		ft_apply_brute(calc);
		i++;
		// printf("%d\n", i);
	}
	// printf("i : %d", i);
	// printf("algo %ld %ld %ld\n", calc->algo[0], calc->algo[1], calc->algo[2]);
}