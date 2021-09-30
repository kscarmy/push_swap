/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 07:49:23 by guderram          #+#    #+#             */
/*   Updated: 2021/09/30 07:49:25 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_init_stacks_2(t_point *calc)
{
	int	i;

	i = 0;
	calc->res = malloc(sizeof(long) * (calc->nbr + 1));
	if (calc->res == NULL)
		return (0);
	calc->res[calc->nbr] = '\0';
	i = 0;
	calc->algo = malloc(sizeof(long) * ((calc->nbr * 25) + 1));
	if (calc->algo == NULL)
		return (0);
	while (i < (calc->nbr * 25))
	{
		calc->algo[i] = 9999999999;
		i++;
	}
	calc->algo[(calc->nbr * 25)] = '\0';
	return (ft_init_stacks_3(calc));
}

int	ft_init_stacks_3(t_point *calc)
{
	int	i;

	i = 0;
	calc->c = malloc(sizeof(long) * (calc->nbr + 1));
	if (calc->c == NULL)
		return (0);
	while (i < (calc->nbr))
	{
		calc->c[i] = 9999999999;
		i++;
	}
	calc->algo[(calc->nbr)] = '\0';
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
	calc->stack = malloc(sizeof(long) * (calc->nbr + 1));
	if (calc->stack == NULL)
		return (0);
	calc->stack[calc->nbr] = '\0';
	argc = 0;
	return (ft_in_stack_3(calc, argc, argv));
}
