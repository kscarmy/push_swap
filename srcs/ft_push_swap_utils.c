#include "../includes/libft.h"

long	ft_long_atoi(const char *nptr)
{
	long	re;
	long	i;
	long	sig;

	i = 0;
	sig = 1;
	re = 0;
	while ((nptr[i] == '\n') || (nptr[i] == '\t') || (nptr[i] == '\v')
		|| (nptr[i] == '\f') || (nptr[i] == '\r') || (nptr[i] == ' '))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
	{
		if (nptr[i] == 45)
			sig = -sig;
		i++;
	}
	while ((48 <= nptr[i]) && (nptr[i] <= 57))
	{
		re = (re * 10) + (nptr[i] - 48);
		i++;
	}
	return (re * sig);
}


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