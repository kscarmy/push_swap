/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2019/11/20 13:25:42 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h> // A SUPPRIMER

# define BUFFER_SIZE 32

int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset (void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
char			*ft_strnstr(const char	*source, const char *objet, size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_tolower(int c);
int				ft_toupper(int c);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dest, const char *src, size_t destsize);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
void			*ft_calloc(size_t count, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
int				ft_gnl_strlen(char *str);
char			*ft_gnl_strnew(int *error);
int				ft_gnl_strchr(char *str);
int				ft_gnl_strcount(char *str);
void			ft_gnl_strjoin
(char **str, const char *buff, int buff_size, int *error);
int				ft_gnl_exerror(char **str, int error);
void			ft_gnl_strdel(char **as);
char			*ft_gnl_strsub
(char const *s, unsigned int start, size_t len, int **error);
void			ft_gnl_read(char **str, char **line, int ret, int *error);
int				ft_get_next_line(int fd, char **line);

typedef struct	s_point
{
	va_list				ap;
	int					ret;
	int					i;
	int					u;
	int					wdh;
	int					pco;
	int					siz;
	char				*str;
	char				*fmt;
	char				c;
	char				typ;
	char				fag;
	char				d[64];
	int					t;
	unsigned long long	ull;
	int					b;
	int					maj;
	int					g;
	unsigned int		ui;
}				t_point;

int				ft_printf(const char *format, ...);
void			ft_init_ptf(t_point	*ptf, char *format);
void			ft_putchar_printf(char c, t_point *ptf);
void			ft_putstr_printf(char *str, t_point *ptf);
void			ft_know_flags(t_point *ptf);
void			ft_know_width(t_point *ptf);
void			ft_know_precision(t_point *ptf);
void			ft_ana_types(t_point *ptf);
int				ft_make_type(char type, t_point *ptf);
int				ft_find_type(t_point *ptf);
void			ft_ana_flags(t_point *ptf);
void			ft_printf_s(t_point *ptf);
void			ft_clear_ptf(t_point *ptf);
int				ft_printf_strlen(char *str);
void			ft_printf_percent(t_point *ptf);
void			ft_printf_c(t_point *ptf);
void			ft_printf_d(t_point *ptf);
void			ft_printf_itoa(t_point *ptf);
void			ft_printf_d_disp(t_point *ptf);
void			ft_printf_itoa_init(t_point *ptf);
void			ft_printf_d_incre(int x, t_point *ptf);
void			ft_printf_d_suite(t_point *ptf);
int				ft_printf_d_disp_suite(int *m, int *a, int *u, t_point *ptf);
void			ft_printf_p(t_point *ptf);
void			ft_printf_p_suite(t_point *ptf);
void			ft_printf_p_incre(int x, t_point *ptf);
void			ft_printf_itoa_ull(t_point *ptf);
void			ft_printf_p_disp(t_point *ptf);
void			ft_printf_p_disp_suite(int *m, int *a, int *u, t_point *ptf);
void			ft_printf_u(t_point *ptf);
void			ft_printf_u_suite(t_point *ptf);
void			ft_printf_itoa_u(t_point *ptf);
int				ft_printf_u_disp_suite(int *m, int *a, int *u, t_point *ptf);
void			ft_printf_u_disp(t_point *ptf);
void			ft_printf_x(t_point *ptf);
void			ft_printf_x_suite(t_point *ptf);
void			ft_printf_itoa_x(t_point *ptf);
void			ft_printf_x_disp(t_point *ptf);
void			ft_printf_x_disp_suite(int *m, int *a, int *u, t_point *ptf);
int				ft_false_type(t_point *ptf);
void			ft_printf_itoa_ll(t_point *ptf);

typedef struct	t_point
{
	int		nbr;
	long	*stack;
	long	*a;
	long	*b;
	long	*res;
	long	*algo;
}				w_point;

int				ft_verif_arg(char *argv); // ret 0 si erreur, 1 sinon
int				ft_in_stack(w_point *calc, int argc, char **argv); // ret 0 si erreur, 1 sinon
void			ft_free_all(w_point *calc); // free stack
int				ft_init_stacks(w_point *calc); // ret 0 si erreur, 1 sinon
void			ft_free_stacks(w_point *calc); // free a et b
int				ft_swap_core(w_point *calc);// ret 0 si erreur, 1 sinon
void				ft_swap_sa(w_point *calc); 
void				ft_swap_sb(w_point *calc); 
void				ft_swap_ss(w_point *calc); 
void				ft_swap_pa(w_point *calc); 
void				ft_swap_pb(w_point *calc); 
void				ft_swap_ra(w_point *calc); 
void				ft_swap_rb(w_point *calc); 
void				ft_swap_rr(w_point *calc); 
void				ft_swap_rra(w_point *calc);
void				ft_swap_rrb(w_point *calc);
void				ft_swap_rrr(w_point *calc);

// core 
void				ft_swap_trad(w_point *calc); // affiche les résultats
int					ft_is_int(w_point *calc); // ret 0 si erreur, 1 sinon

// utils
void				ft_disp_long(long *str, w_point *calc); // affiche la lsite de long
void				ft_disp_long_algo(long *str, w_point *calc);
long				ft_long_atoi(const char *nptr);

// pre core :
int					ft_make_res(w_point *calc); // ret 0 si erreur, 1 sinon
long				ft_found_with_min(long *str, long min, w_point *calc);
long				ft_found_min(long *str, w_point *calc);
int					ft_is_doublon(w_point *calc); // ret 0 si erreur, 1 sinon

// brute :
int					ft_swap_broke(w_point *calc); // ret 0 si erreur, 1 sinon
int 				ft_swap_checker(w_point *calc); // ret 0 si erreur, 1 sinon
int					ft_swap_reset_ab(w_point *calc); // call in checker for reset and ret 0 for error
void 				ft_swap_tradrun(w_point *calc);

#endif
