#include "../includes/libft.h"

void	ft_pre_set_a(t_point *calc)
{
	long	min;

	min = ft_set_c(calc);

	// printf("pre set a : a0 %ld min %ld\n", calc->a[0], min);
	// min = 0;
	while (min != 0)
	{
		if (min > 0)
		{
			ft_swap_ra(calc);
			calc->algo[calc->head] = 6;
			calc->head = calc->head + 1;
			min--;
		}
		else
		{
			// printf("OUI\n");
			ft_swap_rra(calc);
			calc->algo[calc->head] = 9;
			calc->head = calc->head + 1;
			min++;
		}
	}
	// printf("a0 %ld\n", calc->a[0]);
}

long	ft_set_c(t_point *calc) // remplis c des valeurs calculees de a
{
	int	i;
	// int min;

	i = 0;
	if (calc->c[0] != 9999999999)
		ft_reset_c(calc);
	ft_pre_set_c(calc);
	while (calc->a[i] != 9999999999 && i < calc->nbr)
	{
		// printf("PRE a %ld, %ld, %ld | ", calc->a[i], ft_rong_dir_c(calc, calc->a[i]), calc->c[i]);
		if (ft_rong_dir_c(calc, calc->a[i]) < 0)
			calc->c[i] = calc->c[i] + (ft_rong_dir_c(calc, calc->a[i]) * -1);
		else
			calc->c[i] = calc->c[i] + ft_rong_dir_c(calc, calc->a[i]); // ERREUR : RONG DIR MODIFIE LES VALEUR MIN ET MAX !!!!!!
		// printf("a %ld, %ld, %ld | ", calc->a[i], ft_rong_dir_c(calc, calc->a[i]), calc->c[i]);
		// printf("%ld ", calc->c[i]);
		i++;
	}
	// printf("\n");
	// i = 0;
	// min = calc->c[0];
	// i = 0;
	// while (calc->c[i])
	// {
		// printf("c%ld, ", calc->c[i]);
	// 	i++;
	// }
	// printf("\n");
	return(ft_c_found_min(calc));
	// min = 0;
	// return (0);
}

long	ft_c_found_min(t_point *calc)
{
	int i;
	long ret;
	int size;
	long min;

	i = 0;
	ret = calc->c[0];
	min = 0;
	size = ft_size_pile(calc, calc->c);
	// printf("\n");
	// printf("size : %d\n", size);
	// printf("c7%d\n", calc->c[7]);
	while(calc->c[i] != 9999999999 && i < size) // le plus gros
	{
		if (calc->c[i] < ret)
		{

			ret = calc->c[i];
			min = i;
		}
		// printf("ci%d %ld | ", i, calc->c[i]);
		i++;
	}
	// printf("MIN in c found min : %ld", min);
	// printf("\n");
	// printf("\nfound min : a0 %ld, min %ld\n", calc->a[0], min);
	if (min < (size - min))
		return (min);
	else
		return((size - min) * -1);
	
	// return(ft_rong_dir_up_down(calc, ret, calc->c));
	// return (0);
}

void	ft_pre_set_c(t_point *calc)
{
	int	size;
	int	i;

	size = ft_size_pile(calc, calc->a);
	i = 0;
	while (i < ((size / 2) + 1))
	{
		calc->c[i] = i;
		calc->c[size - i] = i;
		i++;
	}
	i = 0;
	// printf("pre set c\n");
	while (i < size)
	{
		// printf("c%ld a%ld | ", calc->c[i], calc->a[i]);
		i++;
	}
	// printf("\n");
}

void	ft_reset_c(t_point *calc) // remplis c de 9999999999
{
	int	i;

	i = 0;
	while (i < calc->nbr)
	{
		calc->c[i] = 9999999999;
		i++;
	}
}





long	ft_rong_dir_c(t_point *calc, long val)
{
    int i;
	long i_ret;
	int sizeb;

    i = 0;
	i_ret = 0;
	sizeb = ft_size_pile(calc, calc->b);
	if (val < calc->min)
		return(ft_found_min_c(calc));
	if (val > calc->max)
		return(ft_found_max_c(calc));
	while(calc->b[i] != 9999999999 && i <= sizeb)
	{
		if (val > calc->b[i])
			i_ret = i;
		i++;
	}
	i = 0;
	while(calc->b[i] != 9999999999 && i <= sizeb)
	{
		if (val > calc->b[i] && calc->b[i_ret] < calc->b[i])
		{
			i_ret = i;
		}
		i++;
	}
	// calc->c[0] = 0;
	// sizeb = 0;
	// val++;
	// return (0);
	return (ft_rong_dir_up_down(calc, i_ret, calc->b)); // WTF
}

long	ft_found_min_c(t_point *calc)
{
	int i;
	long ret;
	int sizeb;

	i = 0;
	sizeb = ft_size_pile(calc, calc->b);
	while(calc->b[i] != 9999999999 && i < sizeb) // le plus gros
	{
		if (calc->b[i] == calc->min)
			ret = i + 1;
		i++;
	}
	// calc->min = calc->a[0];
	return(ft_rong_dir_up_down(calc, ret, calc->b));
}


long	ft_found_max_c(t_point *calc)
{
	int i;
	long ret;
	int sizeb;

	i = 0;
	sizeb = ft_size_pile(calc, calc->b);
	while(calc->b[i] != 9999999999 && i < sizeb) // le plus gros
	{
		if (calc->b[i] == calc->max)
			ret = i;
		i++;
	}
	// calc->max = calc->a[0];
	return(ft_rong_dir_up_down(calc, ret, calc->b));
}