#include "../includes/libft.h"

int	ft_init_stacks_2(t_point *calc)
{
	int	i;

	i = 0;
	printf("nbr INIT STACK 2: %d\n", calc->nbr);
	printf("S1'%ld' S2'%ld' S3'%ld'\n",calc->stack[0], calc->stack[1], calc->stack[2]);
	calc->res = malloc(sizeof(long) * (calc->nbr + 1));
	if (calc->res == NULL)
		return (0);
	calc->res[calc->nbr] = '\0';
	i = 0;
	calc->algo = malloc(sizeof(long) * ((calc->nbr * 4) + 1));
	if (calc->algo == NULL)
		return (0);
	while (i < (calc->nbr * 4))
	{
		calc->algo[i] = 9999999999;
		i++;
	}
	calc->algo[(calc->nbr * 4)] = '\0';
	return (1);
}

int	ft_in_stack_3(t_point *calc, int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[1][argc] != '\0')
	{
		calc->stack[i] = ft_long_atoi((argv[1] + argc));
		if ((argv[1][argc] != '-' && calc->stack[argc] < 0) ||
		 (argv[1][argc] == '-' && calc->stack[argc] > 0))
			return (0);
		if (argv[1][argc] == '-')
			argc++;
		while (ft_isdigit(argv[1][argc]) == 1)
			argc++;
		i++;
		if (argv[1][argc] == ' ')
			argc++;
	}
	return (1);
}

int	ft_in_stack_2(t_point *calc, int argc, char **argv)
{
	argc = 0;
	calc->nbr = 0;
	// printf("nbr in stack : %d\n", calc->nbr);
	while (argv[1][argc] != '\0')
	{
		if (argv[1][argc] == '-')
			argc++;
		while (ft_isdigit(argv[1][argc]) == 1)
		{
			argc++;
		}
		calc->nbr = calc->nbr + 1;
		if (argv[1][argc] == ' ')
			argc++;
	}
	// printf("nbr in stack : %d\n", calc->nbr);
	calc->stack = malloc(sizeof(int) * (calc->nbr + 1));
	if (calc->stack == NULL)
		return (0);
	calc->stack[calc->nbr] = '\0';
	argc = 0;
	return (ft_in_stack_3(calc, argc, argv));
}
