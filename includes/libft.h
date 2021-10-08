/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2021/10/08 04:50:41 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_point
{
	int		nbr;
	long	*stack;
	long	*a;
	long	*b;
	long	*res;
	long	*algo;
	long	min;
	long	max;
	int		head;
	long	*c;
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
int					ft_in_stack_2(t_point *calc, int argc, char **argv);
int					ft_init_stacks_2(t_point *calc);
int					ft_the_rong(t_point *calc);
int					ft_size_pile(t_point *calc, long *stack);
long				ft_rong_dir(t_point *calc, long val);
void				ft_a_to_b(t_point *calc);
void				ft_init_rong(t_point *calc);
long				ft_b_found_min(t_point *calc);
long				ft_b_found_max(t_point *calc);
long				ft_rong_dir_up_down(t_point *calc, long ret, long *stack);
long				ft_a_found_min(t_point *calc);
long				ft_set_c(t_point *calc);
long				ft_c_found_min(t_point *calc);
void				ft_pre_set_c(t_point *calc);
void				ft_reset_c(t_point *calc);
void				ft_pre_set_a(t_point *calc);
long				ft_rong_dir_c(t_point *calc, long val);
long				ft_found_min_c(t_point *calc);
long				ft_found_max_c(t_point *calc);
int					ft_init_stacks_3(t_point *calc);
int					ft_the_rong_1(t_point *calc, int mi);
int					ft_is_a_good(t_point *calc);
int					ft_size_pile_end(t_point *calc, long *stack);

#endif
