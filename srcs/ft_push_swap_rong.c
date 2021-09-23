#include "../includes/libft.h"

int	ft_the_rong(t_point *calc)
{
    int h;

    h = 0;
	calc->min = 0;
	calc->max = calc->nbr - 1;
	calc->head = 0;

	ft_swap_pb(calc);
	calc->algo[calc->head] = 5;
	calc->head = calc->head + 1;
    while (calc->a[0] != 9999999999 && h < calc->nbr)
    {

        // FONCTION QUI CHERCHE LE bon nombre ET LE MET DANS b
		ft_a_to_b(calc);
        h++;
    }
    h = 0;
	while (calc->b[0] != calc->res[calc->nbr - 1])
	{
		ft_swap_rb(calc);
		calc->algo[calc->head] = 7;
		calc->head = calc->head + 1;
	}
    while (calc->b[0] != 9999999999 && h < (calc->nbr))
    {
		ft_swap_pa(calc);
		calc->algo[calc->head] = 4;
		calc->head = calc->head + 1;
        // remettre tout b dans a
        h++;
    }
	// ft_putstr("fin ring\n");
	return(1);
}

void	ft_b_min_max(t_point *calc)
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
    while(stack[i] != 9999999999 && i < calc->nbr)
        i++;
    return(i);
}

int	ft_rong_dir(t_point *calc)
{
	int i;

	i = 0;
	if (calc->a[0] > calc->b[0] && calc->a[0] < calc->b[ft_size_pile(calc, calc->b) - 1])
		return (0);
	while (calc->b[i] != 9999999999 && i < calc->nbr)
	{
		
	}
}

void	ft_a_to_b(t_point *calc)
{


}