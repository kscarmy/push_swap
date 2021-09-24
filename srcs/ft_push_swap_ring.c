#include "../includes/libft.h"

int ft_the_ring(t_point *calc) // algo pour nbr > 4
{
    int h;

    h = 0;
	calc->min = 0;
	calc->max = calc->nbr - 1;
	calc->head = 0;
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

// int ft_size_pile(t_point *calc, long *stack)
// {
//     int i;

//     i = 0;
//     while(stack[i] != 9999999999 && i < calc->nbr)
//         i++;
//     return(i);
// }

// void	ft_a_to_b(t_point *calc)
// {
// 	int	dir;

// 	dir = ft_ring_dir(calc);
// 	// printf("dir : %d\n", dir);
// 	while (dir > 0)
// 	{
// 		ft_swap_ra(calc);
// 		calc->algo[calc->head] = 6;
// 		calc->head = calc->head + 1;
// 		dir--;
// 	}
// 	while (dir < 0)
// 	{
// 		ft_swap_rra(calc);
// 		calc->algo[calc->head] = 9;
// 		calc->head = calc->head + 1;
// 		dir++;
// 	}
// 	if (dir == 0)
// 	{
// 		ft_swap_pb(calc);
// 		calc->algo[calc->head] = 5;
// 		calc->head = calc->head + 1;
// 	}
// 	else
// 		ft_putstr("ERROR IN ring-ft_a_to_b\n");
// 	if (calc->b[0] == calc->res[calc->min])
// 		calc->min = calc->min + 1;
// 	else
// 	{
// 		calc->max = calc->max - 1;
// 		ft_swap_rb(calc);
// 		calc->algo[calc->head] = 7;
// 		calc->head = calc->head + 1;
// 	}
// }

int ft_ring_dir(t_point *calc) // ret le nombre de decale en partant de la ou on est
{
    int mi; // tete lecture
	int ma; // tete lecture
	long a; // valeur min de res a trouver
	long b; // valeur max de res a trouver
	int sa; // taille pile a

    mi = 0;
	ma = ft_size_pile(calc ,calc->a) - 1;
	sa = ft_size_pile(calc ,calc->a);
	a = calc->res[calc->min];
	b = calc->res[calc->max];
	// printf("a0: %ld\n", calc->a[0]);
	// printf("a : %ld, b : %ld\n", a, b);
	if (calc->a[0] == a || calc->a[0] == b)
	{
		// printf("a0 %ld\n", calc->a[0]);
		// printf("WTF\n\n");
		return(0);
	}
    // while (((calc->a[mi] != a || calc->a[mi] != b) || (calc->a[ma] != a || calc->a[ma] != b)) && mi < ma)
    // {
	// 	mi++;
	// 	ma--;
    // }
	while (calc->a[mi] != a && calc->a[mi] != b && mi <= sa)
	{
		// printf("a:mi %ld\n", calc->a[mi]);
		mi++;
	}
	// printf("")
	while (calc->a[ma] != a && calc->a[ma] != b && ma >= 0)
		ma--;

	// printf("mi : %d\n", mi);
	// printf("ma : %d\n", ma);
	// if (mi < ma)
	// 	ft_putstr("ERROR : mi < ma in ring-ring_dir\n");
	
	// printf("\nsa %d ma %d\n", sa, ma);
	// printf("mi %d sama %d\n", mi, (-1 * (sa - ma)));
	if (mi < (sa - ma))
		return (mi);
	else
		return (-1 * (sa - ma));
}