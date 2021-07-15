#include "../includes/libft.h"

void	ft_swap_trad(w_point *calc)
{
	int i;
	// ft_printf("|| ");
	i = 0;
	while (calc->algo[i] != 9999999999 && i < (calc->nbr * 4))
	{
		if (calc->algo[i] == 1)
			ft_printf("|sa| ");
			// ft_swap_sa(calc);
		if (calc->algo[i] == 2)
			ft_printf("|sb| ");
			// ft_swap_sb(calc);
		if (calc->algo[i] == 3)
			ft_printf("|ss| ");
			// ft_swap_ss(calc);
		if (calc->algo[i] == 4)
			ft_printf("|pa| ");
			// ft_swap_pa(calc);
		if (calc->algo[i] == 5)
			ft_printf("|pb| ");
			// ft_swap_pb(calc);
		if (calc->algo[i] == 6)
			ft_printf("|ra| ");
			// ft_swap_ra(calc);
		if (calc->algo[i] == 7)
			ft_printf("|rb| ");
			// ft_swap_rb(calc);
		if (calc->algo[i] == 8)
			ft_printf("|rr| ");
			// ft_swap_rr(calc);
		if (calc->algo[i] == 9)
			ft_printf("|rra| ");
			// ft_swap_rra(calc);
		if (calc->algo[i] == 10)
			ft_printf("|rrb| ");
			// ft_swap_rrb(calc);
		if (calc->algo[i] == 11)
			ft_printf("|rrr| ");
			// ft_swap_rrr(calc);
		i++;
	}
}

int	ft_swap_core(w_point *calc) // ret 0 si erreur, 1 sinon
{
	int ret;

	ret = ft_init_stacks(calc);
	if (ret == 1)
		ret = ft_make_res(calc);


	ft_printf("a 1 : ");
	ft_disp_long(calc->a, calc);
	ft_printf("b 1 : ");
	ft_disp_long(calc->b, calc);
	printf("ret 1 %d\n", ret);
	if (ret == 1 && calc->nbr > 1)
		ret = ft_swap_broke(calc);
	printf("ret 2 %d\n", ret);

	// ft_swap_sa(calc);

	// ft_swap_pb(calc);
	// ft_swap_pb(calc);
	// ft_swap_pb(calc);

	// // ft_printf("a 2 : ");
	// // ft_disp_long(calc->a, calc);
	// // ft_printf("b 2 : ");
	// // ft_disp_long(calc->b, calc);

	// ft_swap_rr(calc);

	// ft_printf("a 3 : ");
	// ft_disp_long(calc->a, calc);
	// ft_printf("b 3 : ");
	// ft_disp_long(calc->b, calc);

	// ft_swap_rrr(calc);

	// ft_printf("a 4 : ");
	// ft_disp_long(calc->a, calc);
	// ft_printf("b 4 : ");
	// ft_disp_long(calc->b, calc);

	// ft_swap_sa(calc);

	// ft_swap_pa(calc);
	// ft_swap_pa(calc);
	// ft_swap_pa(calc);


	ft_printf("a X : ");
	ft_disp_long(calc->a, calc);
	ft_printf("b X : ");
	ft_disp_long(calc->b, calc);

	if (ret == 1 && calc->nbr > 1)
		ft_swap_trad(calc);

	ft_free_stacks(calc);
	return (ret);
}