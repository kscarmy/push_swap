NAME_LIBFT = lib_push_swap.a

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_C = srcs/ft_push_swap_core.c\
			srcs/ft_push_swap_ope.c\
			srcs/ft_push_swap_ope_bis.c\
			srcs/ft_push_swap_ope_bibis.c\
			srcs/ft_push_swap_pre_core.c\
			srcs/ft_push_swap_utils.c\
			srcs/ft_main_bis.c\
			srcs/ft_push_swap_rong.c\
			srcs/ft_push_swap_rong_1.c\
			srcs/ft_push_swap_rong_2.c\
			srcs/ft_push_swap_rong_ana.c\
			srcs/ft_push_swap_rong_ana_1.c\
			srcs/ft_push_swap_brute.c\
			

MAIN_C = srcs/main.c\

OBJS =  ft_push_swap_core.o\
			ft_push_swap_ope.o\
			ft_push_swap_ope_bis.o\
			ft_push_swap_ope_bibis.o\
			ft_push_swap_pre_core.o\
			ft_push_swap_utils.o\
			ft_main_bis.o\
			ft_push_swap_rong.o\
			ft_push_swap_rong_1.o\
			ft_push_swap_rong_2.o\
			ft_push_swap_rong_ana.o\
			ft_push_swap_rong_ana_1.o\
			ft_push_swap_brute.o\

all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) $(SRC_C) -c
	@ar -rc $(NAME_LIBFT) $(OBJS)
	@ranlib $(NAME_LIBFT)
	@$(CC) $(CFLAGS) $(MAIN_C) $(NAME_LIBFT) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_LIBFT)

re : fclean all
	@rm -rf $(OBJS)
