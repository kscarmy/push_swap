#include "../includes/libft.h"

long		ft_found_min(long *str, w_point *calc)
{
	int i;
	long min;

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

long		ft_found_with_min(long *str, long min, w_point *calc)
{
	int i;
	int sup;

	i = 0;
	while (str[i] <= min && i < calc->nbr) // permet dobtenir le premier suppérieur à min
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

int		ft_is_doublon(w_point *calc) // ret 0 si erreur, 1 sinon
{
	int i;
	int u;

	i = 0;
	u = 0;
	while (i < calc->nbr)
	{
		while (u < calc->nbr)
		{
			
			if (calc->stack[u] == calc->stack[i] && i != u)
				return (0);
			u++;
		}
		u = 0;
		i++;
	}
	return (1);
}

int		ft_make_res(w_point *calc) // ret 0 si erreur, 1 sinon
{
	int i; // compte nombres traités
	long min; // min (dernier nbr)
	// int u; // tete de lecture qui compare 1 à 1

	i = 1;
	if (ft_is_doublon(calc) == 0)
	{
		ft_printf("DOUBLON\n");
		return (0);
	}
	min = ft_found_min(calc->stack, calc);
	// printf("min : %ld\n", min);
	calc->res[0] = min;
	while (i < calc->nbr)
	{
		calc->res[i] = ft_found_with_min(calc->stack, calc->res[i - 1], calc);
		i++;
	}
	return (1);

}
