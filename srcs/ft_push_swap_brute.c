#include "../includes/libft.h"

int	ft_swap_broke_i(t_point *calc, int i, int who)
{
	if (who == 0)
	{
		calc->algo[0] = 1;
		ft_swap_tradrun(calc);
	}
	if (who == 1 || who == 4)
	{
		calc->algo[i] = calc->algo[i] + 1;
		i--;
	}
	if (who == 2)
		calc->algo[i + 1] = 1;
	if (who == 3)
		calc->algo[i] = 1;
	while (who != 0 && i > 0)
	{
		calc->algo[i] = 1;
		i--;
	}
	if (who != 0)
		calc->algo[i] = 1;
	return (i);
}

int	ft_swap_broke(t_point *calc)
{
	int	i;

	i = 0;
	if (ft_swap_checker(calc) == 0)
		i = ft_swap_broke_i(calc, i, 0);
	while (i < (calc->nbr * 25) && ft_swap_checker(calc) == 0)
	{
		if (calc->algo[i] < 11 && i > 0)
			i = ft_swap_broke_i(calc, i, 1);
		else if (calc->algo[i] == 11 && calc->algo[i + 1] == 9999999999)
			i = ft_swap_broke_i(calc, i, 2);
		else if (calc->algo[i] == 11 && calc->algo[i + 1] != 9999999999)
		{
			while (calc->algo[i] == 11)
				i++;
			if (calc->algo[i] == 9999999999)
				i = ft_swap_broke_i(calc, i, 3);
			else
				i = ft_swap_broke_i(calc, i, 4);
		}
		else if (i == 0 && calc->algo[i] < 11)
			calc->algo[i] = calc->algo[i] + 1;
		ft_swap_tradrun(calc);
	}
	return (ft_swap_checker(calc));
}

int	ft_swap_checker(t_point *calc)
{
	int	i;

	i = 0;
	while (i < calc->nbr)
	{
		if (calc->b[i] != 9999999999)
			return (ft_swap_reset_ab(calc));
		i++;
	}
	i = 0;
	while (i < calc->nbr)
	{
		if (calc->a[i] != calc->res[i])
			return (ft_swap_reset_ab(calc));
		i++;
	}
	return (1);
}

int	ft_swap_reset_ab(t_point *calc)
{
	int	i;

	i = 0;
	while (i < calc->nbr)
	{
		calc->a[i] = calc->stack[i];
		calc->b[i] = 9999999999;
		i++;
	}
	return (0);
}

void	ft_swap_tradrun(t_point *calc)
{
	int	i;

	i = 0;
	while (calc->algo[i] != 9999999999 && i < (calc->nbr * 25))
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
		i++;
	}
}
