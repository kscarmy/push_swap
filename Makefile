NAME_LIBFT = lib_push_swap.a

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

# LIBFT_C = libft/ft_atoi.c\
# 		libft/ft_bzero.c\
# 		libft/ft_calloc.c\
# 		libft/ft_isalnum.c\
# 		libft/ft_isalpha.c\
# 		libft/ft_isascii.c\
# 		libft/ft_isdigit.c\
# 		libft/ft_isprint.c\
# 		libft/ft_itoa.c\
# 		libft/ft_memccpy.c\
# 		libft/ft_memchr.c\
# 		libft/ft_memcmp.c\
# 		libft/ft_memcpy.c\
# 		libft/ft_memmove.c\
# 		libft/ft_memset.c\
# 		libft/ft_putchar_fd.c\
# 		libft/ft_putendl_fd.c\
# 		libft/ft_putnbr_fd.c\
# 		libft/ft_putstr_fd.c\
# 		libft/ft_split.c\
# 		libft/ft_strchr.c\
# 		libft/ft_strdup.c\
# 		libft/ft_strjoin.c\
# 		libft/ft_strlcat.c\
# 		libft/ft_strlcpy.c\
# 		libft/ft_strlen.c\
# 		libft/ft_strmapi.c\
# 		libft/ft_strncmp.c\
# 		libft/ft_strnstr.c\
# 		libft/ft_strrchr.c\
# 		libft/ft_strtrim.c\
# 		libft/ft_substr.c\
# 		libft/ft_tolower.c\
# 		libft/ft_toupper.c\
# 		libft/ft_get_next_line.c\
# 		libft/ft_get_next_line_utils.c\

# PRINTF_C =	libft/ft_printf.c\
# 			libft/ft_printf_disp.c\
# 			libft/ft_printf_x.c\
# 			libft/ft_printf_c.c\
# 			libft/ft_printf_ana.c\
# 			libft/ft_printf_know.c\
# 			libft/ft_printf_s.c\
# 			libft/ft_printf_percent.c\
# 			libft/ft_printf_u.c\
# 			libft/ft_printf_d.c\
# 			libft/ft_printf_itoa.c\
# 			libft/ft_printf_p.c\

SRC_C = srcs/ft_push_swap_core.c\
			srcs/ft_push_swap_ope.c\
			srcs/ft_push_swap_ope_bis.c\
			srcs/ft_push_swap_ope_bibis.c\
			srcs/ft_push_swap_pre_core.c\
			srcs/ft_push_swap_utils.c\
			srcs/ft_push_swap_brute.c\
			srcs/ft_main_bis.c\
			srcs/ft_push_swap_ring.c\
		# srcs/ft_exit1.c\
		# srcs/ft_check_files.c\
		# srcs/ft_parsing1.c\
		
		# srcs/ft_parsing2.c\
		# srcs/ft_error1.c\
		# srcs/ft_parsing4.c\

MAIN_C = srcs/main.c\

# OBJS =	ft_printf.o\
# 			ft_printf_u.o\
# 			ft_printf_c.o\
# 			ft_printf_x.o\
# 			ft_printf_p.o\
# 			ft_printf_itoa.o\
# 			ft_printf_d.o\
# 			ft_printf_disp.o\
# 			ft_printf_ana.o\
# 			ft_printf_know.o\
# 			ft_printf_s.o\
# 			ft_atoi.o\
# 			ft_bzero.o\
# 			ft_calloc.o\
# 			ft_isalnum.o\
# 			ft_isalpha.o\
# 			ft_isascii.o\
# 			ft_isdigit.o\
# 			ft_isprint.o\
# 			ft_itoa.o\
# 			ft_memccpy.o\
# 			ft_memchr.o\
# 			ft_memcmp.o\
# 			ft_memcpy.o\
# 			ft_memmove.o\
# 			ft_memset.o\
# 			ft_putchar_fd.o\
# 			ft_putendl_fd.o\
# 			ft_putnbr_fd.o\
# 			ft_putstr_fd.o\
# 			ft_split.o\
# 			ft_strchr.o\
# 			ft_strdup.o\
# 			ft_strjoin.o\
# 			ft_strlcat.o\
# 			ft_strlcpy.o\
# 			ft_strlen.o\
# 			ft_strmapi.o\
# 			ft_strncmp.o\
# 			ft_strnstr.o\
# 			ft_strrchr.o\
# 			ft_strtrim.o\
# 			ft_substr.o\
# 			ft_tolower.o\
# 			ft_toupper.o\
# 			ft_get_next_line.o\
# 			ft_get_next_line_utils.o\
# 			ft_printf_percent.o\

OBJS =  ft_push_swap_core.o\
			ft_push_swap_ope.o\
			ft_push_swap_ope_bis.o\
			ft_push_swap_ope_bibis.o\
			ft_push_swap_pre_core.o\
			ft_push_swap_utils.o\
			ft_push_swap_brute.o\
			ft_main_bis.o\
			ft_push_swap_ring.o\



all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(SRC_C) -c
	@ar -rc $(NAME_LIBFT) $(OBJS)
	@ranlib $(NAME_LIBFT)
	@$(CC) $(CFLAGS) $(MAIN_C) $(NAME_LIBFT) -o $(NAME)
#-g3 -fsanitize=leak
#$(SRC_C) 
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_LIBFT)

re : fclean all
	@rm -rf $(OBJS)
