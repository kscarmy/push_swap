#include "../includes/libft.h"

void	ft_swap_sa(w_point *calc)
{
	long swap;

	// printf("a0 : %ld\n", calc->a[0]);
	// printf("a1 : %ld\n", calc->a[1]);
	if (calc->nbr > 1 && calc->a[0] != 9999999999 && calc->a[1] != 9999999999)
	{
		swap = calc->a[0];
		calc->a[0] = calc->a[1];
		calc->a[1] = swap;
	}
	// printf("a0 : %ld\n", calc->a[0]);
	// printf("a1 : %ld\n", calc->a[1]);
	// return (1);
}

void	ft_swap_sb(w_point *calc)
{
	long swap;

	// printf("b0 : %ld\n", calc->b[0]);
	// printf("b1 : %ld\n", calc->b[1]);
	if (calc->nbr > 1 && calc->b[0] != 9999999999 && calc->b[1] != 9999999999)
	{
		swap = calc->b[0];
		calc->b[0] = calc->b[1];
		calc->b[1] = swap;
	}
	// printf("b0 : %ld\n", calc->b[0]);
	// printf("b1 : %ld\n", calc->b[1]);
	// return (1);
}

void	ft_swap_ss(w_point *calc)
{
	ft_swap_sa(calc);
	ft_swap_sb(calc);
	// return (1);
}

void	ft_swap_pa(w_point *calc) // A TESTER !!!
{
	int i;
	long swap;

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

void	ft_swap_pb(w_point *calc) // A TESTER !!!
{
	int i;
	long swap;

	i = 0;
	swap = calc->a[0];
	// printf("swap %ld ", swap);
	if (calc->a[0] != 9999999999 && i < calc->nbr)
	{
		while (calc->b[i] != 9999999999 && i < calc->nbr)
			i++;
		// printf("i1 %d ", i);
		while (i > 0)
		{
			calc->b[i] = calc->b[i - 1];
			i--;
		}
		// printf("i2 %d ", i);
		// printf("b %ld ", calc->b[0]);
		calc->b[0] = swap;
		// printf("b %ld ", calc->b[0]);
		while (calc->a[i] != 9999999999 && i < (calc->nbr - 1))
		{
			calc->a[i] = calc->a[i + 1];
			i++;
		}
		// printf("i3 %d ", i);
		// printf("a %ld ", calc->a[i]);
		calc->a[i] = 9999999999;
		// printf("a %ld\n\n", calc->a[i]);
	}
}