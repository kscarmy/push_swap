#include "../includes/libft.h"

int ft_the_ring(t_point *calc) // algo pour nbr > 4
{
    int h;

    h = 0;
	calc->head = 0;
    while (calc->a[0] != 9999999999 && h < calc->nbr)
    {

        // FONCTION QUI CHERCHE LE bon nombre ET LE MET DANS b
		ft_a_to_b(calc);
        h++;
    }
    h = 0;
    // while (calc->b[0] != 9999999999 && h < (calc->nbr - 1))
    // {

    //     // remettre tout b dans a
    //     h++;
    // }
	// ft_putstr("fin ring\n");
	return(1);
}

int ft_size_pile(t_point *calc, long *stack)
{
    int i;

    i = 0;
    while(stack[i] != 9999999999 && i < calc->nbr)
        i++;
    return(i);
}

void	ft_a_to_b(t_point *calc)
{
	int	dir;

	dir = ft_ring_dir(calc);
	while (dir > 0)
	{
		ft_swap_ra(calc);
		calc->algo[calc->head] = 6;
		calc->head = calc->head + 1;
		dir--;
	}
	while (dir < 0)
	{
		ft_swap_rra(calc);
		calc->algo[calc->head] = 9;
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

int ft_ring_dir(t_point *calc) // ret le nombre de decale en partant de la ou on est
{
    int mi; // tete lecture
	int ma; // tete lecture
	int a; // valeur min de res a trouver
	int b; // valeur max de res a trouver

    mi = 0;
	ma = ft_size_pile(calc ,calc->a) - 1;
	a = calc->res[calc->min];
	b = calc->res[calc->max];
    while (((calc->a[mi] != a || calc->a[mi] != b) || (calc->a[ma] != a || calc->a[ma] != b)) && mi < ma)
    {
		mi++;
		ma--;
    }
	if (mi < ma)
		ft_putstr("ERROR : mi < ma in ring-ring_dir\n");
	if (mi <= (ft_size_pile(calc ,calc->a) - 1) - ma)
		return (mi);
	else
		return (-1 * ((ft_size_pile(calc ,calc->a) - 1) - ma));
}