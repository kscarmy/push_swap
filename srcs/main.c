#include "../includes/libft.h"

int	ft_verif_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) == 0 && argv[i] != ' ' && argv[i] != '-')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_in_stack(t_point *calc, int argc, char **argv)
{
	if (argc > 2)
	{
		calc->nbr = argc - 1;
		argc = 0;
		calc->stack = malloc(sizeof(long) * (calc->nbr + 1));
		if (calc->stack == NULL)
			return (0);
		calc->stack[calc->nbr] = '\0';
		while (argc < calc->nbr)
		{
			calc->stack[argc] = ft_long_atoi(argv[argc + 1]);
			if ((argv[argc + 1][0] != '-' && calc->stack[argc] < 0) ||
			 (argv[argc + 1][0] == '-' && calc->stack[argc] > 0))
				return (0);
			argc++;
		}
		// printf("nbr : %d\n", calc->nbr);
		// printf("S1'%ld' S2'%ld' S3'%ld'\n",calc->stack[0], calc->stack[1], calc->stack[2]);
	}
	else
	{
		// printf("go in stack 2\n");
		
		if (ft_in_stack_2(calc, argc, argv) == 0)
			return (0);
	}
	calc->stack[calc->nbr] = '\0';
	// printf("nbr : %d\n", calc->nbr);
	// printf("S1'%ld' S2'%ld' S3'%ld'\n",calc->stack[0], calc->stack[1], calc->stack[2]);
	// printf("nbr in stack : %d\n", calc->nbr);
	return (1);
}

void	ft_free_stacks(t_point *calc)
{
	free(calc->a);
	calc->a = NULL;
	free(calc->b);
	calc->b = NULL;
	free(calc->res);
	calc->res = NULL;
	free(calc->algo);
	calc->algo = NULL;
	free(calc->c);
	calc->c = NULL;
}

int	ft_init_stacks(t_point *calc)
{
	int	i;
	// int u;
	// long *tmp;

	i = 0;
	// u = 0;
	// tmp = calc->stack;
	// printf("INIT STACK 1 A nbr : %d\n", calc->nbr);
	// printf("S1'%ld' S2'%ld' S3'%ld'\n\n",calc->stack[0], calc->stack[1], calc->stack[2]);
	calc->a = malloc(sizeof(long) * (calc->nbr + 2));
	if (calc->a == NULL)
		return (0);
	calc->a[calc->nbr] = '\0';
	// printf("INIT STACK 1 B nbr : %d\n", calc->nbr);
	// printf("S1'%ld' S2'%ld' S3'%ld'\n\n",calc->stack[0], calc->stack[1], calc->stack[2]);
	// printf("i : %d\n", i);
	// printf("PreFORCE : '%ld'\n", calc->stack[2]);
	// i = 0;
	// printf("nbr : %d i : %d\n", calc->nbr, i);
	// while (calc->stack[i])
	// {
	// 	printf("S[%d] = %ld\n", i, calc->stack[i]);
	// 	printf("t[%d] = %ld\n", i, tmp[i]);
	// 	i = i + 1;
	// }
	// i = 0;
	while (i < calc->nbr)
	{
		// printf("FORCE A: '%ld'\n", calc->stack[2]);
		// printf("%d : a '%ld' S'%ld'\n", i, calc->a[i], calc->stack[i]);
		calc->a[i] = calc->stack[i];
		// printf("FORCE B: '%ld'\n", calc->stack[2]);
		// printf("%d : a '%ld' S'%ld'\n", i, calc->a[i], calc->stack[i]);
		i++;
		// u++;
	}
	// calc->stack = tmp;
	// // printf(" sortie pb nbr : %d i : %d\n", calc->nbr, i);
	// i = 0;
	// // printf("nbr : %d i : %d\n", calc->nbr, i);
	// while (tmp[i])
	// {
	// 	printf("S[%d] = %ld\n", i, calc->stack[i]);
	// 	printf("t[%d] = %ld\n", i, tmp[i]);
	// 	i = i + 1;
	// }
	// printf("\nINIT STACK 1 C nbr : %d\n", calc->nbr);
	// printf("S1'%ld' S2'%ld' S3'%ld'\n\n",calc->stack[0], calc->stack[1], calc->stack[2]);
	i = 0;
	calc->b = malloc(sizeof(long) * (calc->nbr + 1));
	if (calc->b == NULL)
		return (0);
	calc->b[calc->nbr] = '\0';
	while (i < calc->nbr)
	{
		calc->b[i] = 9999999999;
		i++;
	}
	// printf("INIT STACK 1 D nbr : %d\n", calc->nbr);
	// printf("S1'%ld' S2'%ld' S3'%ld'\n",calc->stack[0], calc->stack[1], calc->stack[2]);
	if (ft_init_stacks_2(calc) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_point	calc;

	i = 1;
	if (argc < 2)
		return (-1);
	// ft_putstr("ok\n");
	while (i <= (argc - 1))
	{
		if (ft_verif_arg(argv[i]) == 0)
			return (ft_exror_free(&calc, 0));
		i++;
	}
	// ft_putstr("ok 2\n");
	if (ft_in_stack(&calc, argc, argv) == 0)
		return (ft_exror_free(&calc, 1));
	// ft_putstr("ok 3\n");
	// printf("MAIN nbr : %d\n", calc.nbr);
	// printf("S1'%ld' S2'%ld' S3'%ld'\n",calc.stack[0], calc.stack[1], calc.stack[2]);
	if (ft_swap_core(&calc) == 0)
		return (ft_exror_free(&calc, 1));
	// ft_putstr("ok 4\n");
	ft_free_all(&calc);
	// while (1); // leaks
	// ft_putstr("ok 5\n");
	return (0);
}
