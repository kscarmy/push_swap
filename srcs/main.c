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
		calc->stack = malloc(sizeof(int) * (calc->nbr + 1));
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
	}
	else
	{
		if (ft_in_stack_2(calc, argc, argv) == 0)
			return (0);
	}
	calc->stack[calc->nbr] = '\0';
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
}

int	ft_init_stacks(t_point *calc)
{
	int	i;

	i = 0;
	calc->a = malloc(sizeof(long) * (calc->nbr + 1));
	if (calc->a == NULL)
		return (0);
	calc->a[calc->nbr] = '\0';
	while (i < calc->nbr)
	{
		calc->a[i] = calc->stack[i];
		i++;
	}
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
	while (i <= (argc - 1))
	{
		if (ft_verif_arg(argv[i]) == 0)
			return (ft_exror_free(&calc, 0));
		i++;
	}
	if (ft_in_stack(&calc, argc, argv) == 0)
		return (ft_exror_free(&calc, 1));
	if (ft_swap_core(&calc) == 0)
		return (ft_exror_free(&calc, 1));
	ft_free_all(&calc);
	return (0);
}
