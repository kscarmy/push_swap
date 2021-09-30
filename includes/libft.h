/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2019/11/20 13:25:42 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct s_point
{
	int		nbr; // nombres passés en parametres 
	long	*stack; // pile d origine
	long	*a;
	long	*b;
	long	*res; // resultat recherché
	long	*algo; // algo de sortie
	long		min; // tete lecture basse dans res
	long		max; // tete lecture haute dans res
	int		head; // tete lecture dans algo
	long		*c; // pile de calcul de la pile a
}				t_point;

int					ft_verif_arg(char *argv);
int					ft_in_stack(t_point *calc, int argc, char **argv);
void				ft_free_all(t_point *calc);
int					ft_init_stacks(t_point *calc);
void				ft_free_stacks(t_point *calc);
int					ft_swap_core(t_point *calc);
void				ft_swap_sa(t_point *calc);
void				ft_swap_sb(t_point *calc);
void				ft_swap_ss(t_point *calc);
void				ft_swap_pa(t_point *calc);
void				ft_swap_pb(t_point *calc);
void				ft_swap_ra(t_point *calc);
void				ft_swap_rb(t_point *calc);
void				ft_swap_rr(t_point *calc);
void				ft_swap_rra(t_point *calc);
void				ft_swap_rrb(t_point *calc);
void				ft_swap_rrr(t_point *calc);
void				ft_swap_trad(t_point *calc);
int					ft_is_int(t_point *calc);
void				ft_swap_trad_2(t_point *calc, int i);
void				ft_swap_tradrun_2(t_point *calc, int i);
void				ft_putstr(char *str);
long				ft_long_atoi(const char *nptr);
int					ft_isdigit(int c);
int					ft_exror_free(t_point *calc, int free);
int					ft_make_res(t_point *calc);
long				ft_found_with_min(long *str, long min, t_point *calc);
long				ft_found_min(long *str, t_point *calc);
int					ft_is_doublon(t_point *calc);
int					ft_swap_broke(t_point *calc);
int					ft_swap_checker(t_point *calc);
int					ft_swap_reset_ab(t_point *calc);
void				ft_swap_tradrun(t_point *calc);
int					ft_swap_broke_i(t_point *calc, int i, int who);
int					ft_in_stack_2(t_point *calc, int argc, char **argv);
int					ft_init_stacks_2(t_point *calc);

int ft_the_ring(t_point *calc); // algo pour nbr > 4
// int ft_size_pile(t_point *calc, long *stack);
void	ft_a_to_b(t_point *calc);
int ft_ring_dir(t_point *calc); // ret le nombre de decale en partant de la ou on est
int	ft_the_rong(t_point *calc);
// void	ft_b_min_max(t_point *calc);
int ft_size_pile(t_point *calc, long *stack);
long	ft_rong_dir(t_point *calc, long val);
void	ft_a_to_b(t_point *calc);
void	ft_init_rong(t_point *calc);
long	ft_b_found_min(t_point *calc);
long	ft_b_found_max(t_point *calc);
long	ft_rong_dir_up_down(t_point *calc, long ret, long *stack);
long	ft_a_found_min(t_point *calc);
long	ft_set_c(t_point *calc); // remplis c des valeurs calculees de a
long	ft_c_found_min(t_point *calc);
void	ft_pre_set_c(t_point *calc);
void	ft_reset_c(t_point *calc); // remplis c de 9999999999
void	ft_pre_set_a(t_point *calc);
long	ft_rong_dir_c(t_point *calc, long val);
long	ft_found_min_c(t_point *calc);
long	ft_found_max_c(t_point *calc);


#endif
