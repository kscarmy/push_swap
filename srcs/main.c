
#include "../includes/libft.h"

void	ft_free_all(w_point *calc) // free tout
{
	free(calc->stack);
	calc->stack = NULL;
}

int	ft_verif_arg(char *argv) // ret 0 si erreur, 1 sinon
{
	int i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) == 0 && argv[i] != ' ' && argv[i] != '-')
		{
			return(0);
		}
		i++;
	}

	return(1);
}

int	ft_in_stack(w_point *calc, int argc, char **argv) // ret 0 erreur, 1 sinon
{
	int i;
	
	i = 0;
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
			if ((argv[argc + 1][0] != '-' && calc->stack[argc] < 0) || (argv[argc + 1][0] == '-' && calc->stack[argc] > 0))
				return (0);
			// ft_printf("1 argc '%d' stack '%d'\n", argc, calc->stack[argc]);
			argc++;
		}
	}
	else
	{
		argc = 0;
		calc->nbr = 0;
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

		calc->stack = malloc(sizeof(int) * calc->nbr);
		if (calc->stack == NULL)
			return (0);
		calc->stack[calc->nbr] = '\0';
		argc = 0;
		while (argv[1][argc] != '\0')
		{
			calc->stack[i] = ft_long_atoi((argv[1] + argc));
			if ((argv[1][argc] != '-' && calc->stack[argc] < 0) || (argv[1][argc] == '-' && calc->stack[argc] > 0))
				return (0);
			
			if (argv[1][argc] == '-')
				argc++;
			// ft_printf("2 i '%d' stack '%d'\n", i, calc->stack[i]);
			while (ft_isdigit(argv[1][argc]) == 1)
				argc++;
			i++;
			if (argv[1][argc] == ' ')
				argc++;
		}
	}
	calc->stack[calc->nbr] = '\0';
	// ft_printf("ft in stack :\n");
	// ft_disp_long(calc->stack, calc);
	// ft_printf("nbr : '%d'\n", calc->nbr);
	return (1);
}

void	ft_free_stacks(w_point *calc)
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
 
int	ft_init_stacks(w_point *calc) // ret 0 si erreur, 1 sinon
{
	int i;

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
 
int main(int argc, char **argv)
{
	int i;
	w_point calc;

	i = 1;
    if(argc < 2)
	{
    	return (-1);
	}
	while (i <= (argc - 1))
	{
		if (ft_verif_arg(argv[i]) == 0)
		{
			ft_printf("Error\n");
			return (-1);
		}
		i++;
	}
	if (ft_in_stack(&calc, argc, argv) == 0)
	{
		ft_free_all(&calc);
		ft_printf("Error while malloc\n");
		return (-1);
	}
	if (ft_swap_core(&calc) == 0)
	{
		ft_printf("Error in core\n");
		ft_free_all(&calc);
		return (-1);
	}
	ft_printf("OK\n");
	ft_free_all(&calc);
    return (0);
}