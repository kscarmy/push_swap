#include "../includes/libft.h"

void	ft_swap_sa(t_point *calc)
{
	long	swap;

	if (calc->nbr > 1 && calc->a[0] != 9999999999 && calc->a[1] != 9999999999)
	{
		swap = calc->a[0];
		calc->a[0] = calc->a[1];
		calc->a[1] = swap;
	}
}

void	ft_swap_sb(t_point *calc)
{
	long	swap;

	if (calc->nbr > 1 && calc->b[0] != 9999999999 && calc->b[1] != 9999999999)
	{
		swap = calc->b[0];
		calc->b[0] = calc->b[1];
		calc->b[1] = swap;
	}
}

void	ft_swap_ss(t_point *calc)
{
	ft_swap_sa(calc);
	ft_swap_sb(calc);
}

void	ft_swap_pa(t_point *calc)
{
	int		i;
	long	swap;

	i = 0;
	swap = calc->b[0];
	if (calc->b[0] != 9999999999 && i < calc->nbr)
	{
		while (calc->a[i] != 9999999999 && i < calc->nbr)
			i++;
		while (i > 0)
		{
			calc->a[i] = calc->a[i - 1];
			i--;
		}
		calc->a[0] = swap;
		while (calc->b[i] != 9999999999 && i < (calc->nbr - 1))
		{
			calc->b[i] = calc->b[i + 1];
			i++;
		}
		calc->b[i] = 9999999999;
	}
}

void	ft_swap_pb(t_point *calc)
{
	int		i;
	long	swap;

	i = 0;
	swap = calc->a[0];
	if (calc->a[0] != 9999999999 && i < calc->nbr)
	{
		while (calc->b[i] != 9999999999 && i < calc->nbr)
			i++;
		while (i > 0)
		{
			calc->b[i] = calc->b[i - 1];
			i--;
		}
		calc->b[0] = swap;
		while (calc->a[i] != 9999999999 && i < (calc->nbr - 1))
		{
			calc->a[i] = calc->a[i + 1];
			i++;
		}
		calc->a[i] = 9999999999;
	}
}
