#include "../includes/libft.h"

void	ft_disp_long(long *str, w_point *calc) // A SUPP
{
	int i;

	i = 0;
	ft_printf("PRINT LONG :\n");
	while (i < calc->nbr)
	{
		if (str[i] != 9999999999)
			printf("|%ld| ", str[i]);
		else
			printf("|RIEN| ");
		i++;
	}
	printf("\n\n");
	// printf("'%ld' '%ld' '%ld' '%ld'\n", str[0], str[1], str[2], str[3]);
	// printf("%ld\n", str[i]); // TESTS A SUPP
	// printf("%ld\n", str[i + 1]);
}

void	ft_disp_long_algo(long *str, w_point *calc) // A SUPP
{
	int i;

	i = 0;
	ft_printf("PRINT LONG :\n");
	while (i < (calc->nbr * 4) && str[i] != 9999999999)
	{
		if (str[i] != 9999999999)
			printf("|%ld| ", str[i]);
		else
			printf("|RIEN| ");
		i++;
	}
	printf("\n\n");
	// printf("'%ld' '%ld' '%ld' '%ld'\n", str[0], str[1], str[2], str[3]);
	// printf("%ld\n", str[i]); // TESTS A SUPP
	// printf("%ld\n", str[i + 1]);
}