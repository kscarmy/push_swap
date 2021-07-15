#include "../includes/libft.h"

void	ft_swap_rra(w_point *calc)
{
	int i;
	long swap;

	i = 0;
	while (calc->a[i + 1] != 9999999999 && calc->a[i] != 9999999999 && i < (calc->nbr - 1))
		i++;
	swap = calc->a[i];
	while (i > 0)
	{
		calc->a[i] = calc->a[i - 1];
		i--;
	}
	calc->a[0] = swap;
}

void	ft_swap_rrb(w_point *calc)
{
	int i;
	long swap;

	i = 0;
	while (calc->b[i + 1] != 9999999999 && calc->b[i] != 9999999999 && i < (calc->nbr - 1))
		i++;
	swap = calc->b[i];
	while (i > 0)
	{
		calc->b[i] = calc->b[i - 1];
		i--;
	}
	calc->b[0] = swap;
}

void	ft_swap_rrr(w_point *calc)
{
	ft_swap_rra(calc);
	ft_swap_rrb(calc);
}