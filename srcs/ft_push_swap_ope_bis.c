#include "../includes/libft.h"

void	ft_swap_ra(w_point *calc) // A TESTER !!!
{
	long	swap;
	int i;

	swap = calc->a[0];
	i = 0;
	while (calc->nbr > 1 && i < (calc->nbr - 1) && calc->a[i + 1] != 9999999999 && calc->a[i] != 9999999999)
	{
		calc->a[i] = calc->a[i + 1];
		i++;
	}
	calc->a[i] = swap;
}

void	ft_swap_rb(w_point *calc) // A TESTER !!!
{
	long	swap;
	int i;

	swap = calc->b[0];
	i = 0;
	while (calc->nbr > 1 && i < (calc->nbr - 1) && calc->b[i] != 9999999999 && calc->b[i + 1] != 9999999999)
	{
		calc->b[i] = calc->b[i + 1];
		i++;
	}
	calc->b[i] = swap;
}

void	ft_swap_rr(w_point *calc) // A TESTER !!!
{
	ft_swap_ra(calc);
	ft_swap_rb(calc);
}

