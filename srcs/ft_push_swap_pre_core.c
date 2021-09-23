#include "../includes/libft.h"

long	ft_found_min(long *str, t_point *calc)
{
	int		i;
	long	min;

	i = 0;
	min = str[i];
	while (i < calc->nbr)
	{
		if (str[i] < min)
			min = str[i];
		i++;
	}
	return (min);
}

long	ft_found_with_min(long *str, long min, t_point *calc)
{
	int	i;
	int	sup;

	i = 0;
	while (str[i] <= min && i < calc->nbr)
		i++;
	sup = str[i];
	i = 0;
	while (i < calc->nbr)
	{
		if (str[i] > min && str[i] < sup)
			sup = str[i];
		i++;
	}
	return (sup);
}

int	ft_is_doublon(t_point *calc)
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	// printf("nbr : %d\n", calc->nbr);
	// printf("S1'%ld' S2'%ld' S3'%ld'\n",calc->stack[0], calc->stack[1], calc->stack[2]);
	while (i < calc->nbr)
	{
		while (u < calc->nbr)
		{
			if (i != u && calc->stack[u] == calc->stack[i])
			{
				// printf("u : '%d' i : '%d'\n",u,i);
				// printf("Su : '%ld' Si : '%ld'\n",calc->stack[u], calc->stack[i]);
				// printf("is doublon false\n");
				return (0);
			}
			u++;
		}
		u = 0;
		i++;
	}
	// printf("is doublon true\n");
	return (1);
}

int	ft_make_res(t_point *calc)
{
	int		i;
	long	min;

	i = 1;
	if (ft_is_doublon(calc) == 0)
	{
		// printf("make res err\n");
		return (0);
	}
	// printf("make res A\n");
	min = ft_found_min(calc->stack, calc);
	calc->res[0] = min;
	while (i < calc->nbr)
	{
		calc->res[i] = ft_found_with_min(calc->stack, calc->res[i - 1], calc);
		i++;
	}
	// printf("make res B\n");
	return (1);
}
