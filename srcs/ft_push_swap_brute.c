#include "../includes/libft.h"

int ft_wtf(w_point *calc)
{
	if (calc->algo[0] == 1 && calc->algo[1] == 5 && calc->algo[2] == 5 && 
	calc->algo[3] == 5 && calc->algo[4] == 8 && calc->algo[5] == 11 && calc->algo[6] == 1 && 
	calc->algo[7] == 4 && calc->algo[8] == 4 && calc->algo[9] == 4)
	{
		printf("TCHOUNG TA GROSSE MERE\n\n\n");
		return (1);
	}
	return (0);
}

int		ft_swap_broke(w_point *calc) //  A REVOIR 
{
	int i;

	i = 0;
	calc->algo[0] = 1;
	ft_swap_tradrun(calc);
	while (i < (calc->nbr * 4) && ft_swap_checker(calc) == 0)
	{
		if (calc->algo[i] < 11 && i > 0) // reset tout à chaque incrée
		{
			calc->algo[i] = calc->algo[i] + 1;
			i--;
			while (i > 0)
			{
				calc->algo[i] = 1;
				i--;
			}
			calc->algo[i] = 1;
		}
		else if (calc->algo[i] == 11 && calc->algo[i + 1] == 9999999999) // reset pour une nouvelle case
		{
			calc->algo[i + 1] = 1;
			while (i > 0)
			{
				calc->algo[i] = 1;
				i--;
			}
			calc->algo[i] = 1;
			// printf("\n");
		}
		else if (calc->algo[i] == 11 && calc->algo[i + 1] != 9999999999)
		{
			while (calc->algo[i] == 11)
				i++;
			if (calc->algo[i] == 9999999999)
			{
				calc->algo[i] = 1;
				while (i > 0)
				{
					calc->algo[i] = 1;
					i--;
				}
				calc->algo[i] = 1;
				// printf("\n");
			}
			else
			{
				calc->algo[i] = calc->algo[i] + 1;
				i--;
				while (i > 0)
				{
					calc->algo[i] = 1;
					i--;
				}
				calc->algo[i] = 1;
			}
			
		}
		else if (i == 0 && calc->algo[i] < 11)
			calc->algo[i] = calc->algo[i] + 1;
		// printf("%d",i);
		// printf("\n");
		// ft_printf("ALGO : ");
		// ft_disp_long_algo(calc->algo, calc);
		ft_swap_tradrun(calc);
	}
	// printf("\n");
	return (ft_swap_checker(calc));
}

// int		ft_swap_broke(w_point *calc) // ret 0 si erreur, 1 sinon
// {
// 	int i;

// 	i = 0;
// 	calc->algo[0] = 1;
// 	while (i < (calc->nbr * 4) && ft_swap_checker(calc) == 0 && i < 12 && ft_wtf(calc) == 0)
// 	{
// 		// if (calc->algo[9] == 4)
// 			// printf("BORDEL DE MERDE\n\n");
// 		// printf("algo %ld\n", calc->algo[1]);
// 		if (calc->algo[i + 1] == 9999999999 && calc->algo[i] == 11)
// 			{
// 				calc->algo[i + 1] = 1;
// 				// printf("ZEUBI");
// 				while (i > 0)
// 				{
// 					calc->algo[i] = 1;
// 					i--;
// 					// printf("ZEUBI");
// 				}
// 				calc->algo[i] = 1;
// 			}
// 		else if(calc->algo[i] == 11)
// 		{
// 			// printf("i up\n");
// 			i++;
// 			calc->algo[i] = calc->algo[i] + 1;
// 		}
// 		else if (calc->algo[i] < 11)
// 			calc->algo[i] = calc->algo[i] + 1;
// 		ft_swap_tradrun(calc);
// 	}
// 	printf("\n");
// 	ft_printf("ALGO : ");
// 	ft_disp_long_algo(calc->algo, calc);
// 	// return (1);
// 	return (ft_swap_checker(calc));
// }

int ft_swap_checker(w_point *calc) // ret 0 si erreur, 1 sinon
{
	int i;

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

int	ft_swap_reset_ab(w_point *calc) // call in checker for reset and ret 0 for error
{
	int i;

	i = 0;
	while (i < calc->nbr)
	{
		calc->a[i] = calc->stack[i];
		calc->b[i] = 9999999999;
		i++;
	}
	return (0);
}

void ft_swap_tradrun(w_point *calc)
{
	int i;

	i = 0;
	while (calc->algo[i] != 9999999999 && i < (calc->nbr * 4))
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
		if (calc->algo[i] == 6)
			ft_swap_ra(calc);
		if (calc->algo[i] == 7)
			ft_swap_rb(calc);
		if (calc->algo[i] == 8)
			ft_swap_rr(calc);
		if (calc->algo[i] == 9)
			ft_swap_rra(calc);
		if (calc->algo[i] == 10)
			ft_swap_rrb(calc);
		if (calc->algo[i] == 11)
			ft_swap_rrr(calc);
		i++;
	}
}