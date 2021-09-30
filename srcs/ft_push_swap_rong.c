#include "../includes/libft.h"

void	ft_init_rong(t_point *calc)
{
	ft_swap_pb(calc);
	calc->algo[calc->head] = 5;
	calc->head = calc->head + 1;
	ft_swap_pb(calc);
	calc->algo[calc->head] = 5;
	calc->head = calc->head + 1;
	if (calc->b[0] > calc->b[1])
	{
		calc->min = calc->b[1];
		calc->max = calc->b[0];
	}
	else
	{
		calc->min = calc->b[0];
		calc->max = calc->b[1];
		ft_swap_rb(calc);
		calc->algo[calc->head] = 7;
		calc->head = calc->head + 1;
	}
}

int	ft_the_rong(t_point *calc)
{
    int h;
	int mi;

    h = 0;
	calc->head = 0;
	ft_init_rong(calc);
    while (calc->a[0] != 9999999999 && h < calc->nbr)
    {

        // FONCTION QUI CHERCHE LE bon nombre ET LE MET DANS b
		ft_pre_set_a(calc);
		ft_a_to_b(calc);
        h++;
    }
    h = 0;
	// while (calc->b[0] != calc->res[calc->nbr - 1]) // perte de temps
	// {
	// 	ft_swap_rb(calc);
	// 	calc->algo[calc->head] = 7;
	// 	calc->head = calc->head + 1;
	// }
    while (calc->b[0] != 9999999999 && h < (calc->nbr))
    {
		ft_swap_pa(calc);
		calc->algo[calc->head] = 4;
		calc->head = calc->head + 1;
        // remettre tout b dans a
        h++;
    }
	mi = ft_a_found_min(calc);
	mi--; // A VERIFIER SI OPERANT H24 OU PAS !!!!!!!!!!
	while (mi != 0) // permet de remettre a dans l'ordre
	{
		if (mi > 0)
		{
			ft_swap_ra(calc);
			calc->algo[calc->head] = 6;
			calc->head = calc->head + 1;
			mi--;
		}
		else
		{
			ft_swap_rra(calc);
			calc->algo[calc->head] = 9;
			calc->head = calc->head + 1;
			mi++;
		}
	}
	// ft_putstr("fin ring\n");
	// printf("min : %ld max : %ld\n", calc->min, calc->max);
	return(1);
}

void	ft_init_b_min_max(t_point *calc)
{
	if(calc->b[0] < calc->b[1])
	{
		ft_swap_rb(calc);
		calc->algo[calc->head] = 7;
		calc->head = calc->head + 1;
	}
	calc->max = calc->b[0];
	calc->min = calc->b[1];
}



int ft_size_pile(t_point *calc, long *stack)
{
    int i;

    i = 0;
    while(stack[i] != 9999999999 && i < calc->nbr && stack[i] != '\0')
        i++;
    return(i);
}

long	ft_a_found_min(t_point *calc)
{
	int i;
	long ret;
	int sizeb;

	i = 0;
	sizeb = ft_size_pile(calc, calc->a);
	while(calc->a[i] != 9999999999 && i < sizeb) // le plus gros
	{
		if (calc->a[i] == calc->min)
			ret = i + 1;
		i++;
	}
	return(ft_rong_dir_up_down(calc, ret, calc->b));
}

long	ft_b_found_min(t_point *calc)
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
	calc->min = calc->a[0];
	return(ft_rong_dir_up_down(calc, ret, calc->b));
}

long	ft_b_found_max(t_point *calc)
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
	calc->max = calc->a[0];
	return(ft_rong_dir_up_down(calc, ret, calc->b));
}

long	ft_rong_dir_up_down(t_point *calc, long ret, long *stack)
{
	long	sizeb;

	sizeb = ft_size_pile(calc, stack);
	if (ret < (sizeb - ret))
	{
		// printf("up\n");
		return (ret);
	}
	else
	{
		// printf("down\n");
		return ((sizeb - ret) * -1);
	}
}


long	ft_rong_dir(t_point *calc, long val)
{
    int i;
	long i_ret;
	// int found_max;
	int sizeb;

    i = 0;
	i_ret = 0;
	// found_max = 0;
	sizeb = ft_size_pile(calc, calc->b);
	if (val < calc->min)
		return(ft_b_found_min(calc));// 
	if (val > calc->max)
		return(ft_b_found_max(calc));// 
	// printf("calc a : %ld\n", val);
	while(calc->b[i] != 9999999999 && i <= sizeb) // le plus gros
	{
		if (val > calc->b[i])
			i_ret = i;
		i++;
	}
	// printf("PRE calc b i_ret : %ld\n", calc->b[i_ret]);
	i = 0;
	while(calc->b[i] != 9999999999 && i <= sizeb) // le plus gros
	{
		// printf("calc bi : %ld\n", calc->b[i]);
		if (val > calc->b[i] && calc->b[i_ret] < calc->b[i])
		{
			// printf("rea\n");
			i_ret = i;
		}
		i++;
	}
	// printf("FIN calc b i_ret : %ld\n", calc->b[i_ret]);
	// if (i_ret < i && i_ret != 9999999999) // i_ret doit avoir une valeur
	// {
	// 	// printf("i_ret\n");
	// 	return (i_ret);
	// }
	return (ft_rong_dir_up_down(calc, i_ret, calc->b));
	// i = 0;
	// while(calc->b[i] != 9999999999 && i < sizeb)
	// {
	// 	if (calc->b[found_max] < calc->b[i])
	// 	{
	// 		// printf("fmax = %d\n", i);
	// 		found_max = i;
	// 	}
	// 	i++;
	// }
	// if (i_ret == 9999999999)
	// 	printf("ERROR i_ret\n\n");
	// printf("found_max\n");
	// return(found_max);
}

// int	ft_rong_dir(t_point *calc)
// {
// 	int i;
// 	int	dirmax;
// 	int sizeb;

// 	i = 0;
// 	dirmax = 0;
// 	sizeb = ft_size_pile(calc, calc->b);
// 	if (calc->a[0] > calc->b[0] && calc->a[0] )
// 	while (calc->b[i] != 9999999999 && i < calc->nbr)
// 	{
// 		if (calc->a[0] < calc->b[i] && calc->a[0] > calc->b[i + 1])
// 			dirmax = i;
// 		i++;
// 	}
// 	return (dirmax);
// }

// int	ft_rong_dir(t_point *calc) // ret la position de calc->a[0] dans calc->b
// {
// 	int i;
// 	int	dirmax;
// 	int sizeb;
// 	int mi;

// 	i = 0;
// 	mi = 0;
// 	sizeb = ft_size_pile(calc, calc->b);
// 	if (calc->a[0] > calc->b[0] && calc->a[0] < calc->b[ft_size_pile(calc, calc->b) - 1])
// 		return (0);
// 	while (calc->b[i] != 9999999999 && i < calc->nbr)
// 	{
// 		if (calc->b[i] == calc->min)
// 			mi = i;

// 		if (calc->a[0] > calc->b[i])
// 			dirmax = i;
// 		i++;
// 	}
// 	if (calc->a[0] < calc->min)
// 	{
// 		calc->min = calc->a[0];
// 		dirmax = mi;
// 	}
// 	if (calc->a[0] > calc->max)
// 		calc->max = calc->a[0];
// 	if (dirmax > (sizeb / 2))
// 		return((sizeb - dirmax) * -1);
// 	else
// 		return(dirmax);
// }

void	ft_a_to_b(t_point *calc)
{
	long dir;

	dir = ft_rong_dir(calc, calc->a[0]);
	// printf("calc a 0 %ld dir %d\n", calc->a[0], dir);
	// printf("dir %d\n", dir);
	while (dir > 0)
	{
		ft_swap_rb(calc);
		calc->algo[calc->head] = 7;
		calc->head = calc->head + 1;
		dir--;
	}
	while (dir < 0)
	{
		ft_swap_rrb(calc);
		calc->algo[calc->head] = 10;
		calc->head = calc->head + 1;
		dir++;
	}
	if (dir == 0)
	{
		ft_swap_pb(calc);
		calc->algo[calc->head] = 5;
		calc->head = calc->head + 1;
	}
	else
		ft_putstr("ERROR IN ring-ft_a_to_b\n");

}