# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/07 18:40:55 by rhealitt          #+#    #+#              #
#    Updated: 2019/05/23 19:40:24 by rhealitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c parse.c ./number/print_num.c ./number/print_di.c \
	   ./number/print_o.c ./number/print_x.c ./number/print_u.c \
	   ./tools/width.c ./tools/precision.c ./tools/length.c ./tools/flag.c \
	   ./char/print_cs.c ./utilities/ft_atoi.c ./utilities/ft_memset.c \
	   ./utilities/ft_strchr.c ./utilities/ft_strcmp.c \
	   ./utilities/ft_strlen.c ./utilities/ft_strncpy.c \
	   ./utilities/ft_strndup.c ./utilities/ft_strnew.c \
	   ./utilities/ft_putchar.c ./utilities/ft_putstr.c \
	   ./utilities/ft_putnstr.c ./tools/print_flag.c ./tools/print_padding.c \
	   ./utilities/ft_u_len_base.c ./utilities/ft_u_longlong_len.c \
	   ./utilities/ft_str_multi_chr.c ./utilities/ft_longlong_len.c \
	   ./utilities/ft_len_base.c ./utilities/ft_hex_len.c \
	   ./utilities/ft_put_longlong_base.c \
	   ./utilities/ft_putnchar.c ./utilities/ft_put_u_longlong_base.c \
	   ./utilities/ft_ptr_len_base.c ./utilities/ft_print_u_hex.c \
	   ./number/print_f.c ./char/print_ptr.c ./number/f_to_s.c \
	   ./tools/flag_manager_f.c ./tools/round_ld.c ./utilities/ft_memalloc.c \
	   ./utilities/ft_bzero.c

OBJS = ./ft_atoi.o ./ft_memset.o ./ft_putnchar.o ./ft_strlen.o ./ft_bzero.o \
	   ./ft_print_u_hex.o ./print_cs.o ./print_ptr.o\
	   ./ft_putnstr.o ./ft_strncpy.o ./ft_hex_len.o ./ft_ptr_len_base.o \
	   ./ft_putstr.o ./ft_strndup.o ./ft_len_base.o ./ft_put_longlong_base.o \
	   ./ft_str_multi_chr.o ./ft_strnew.o ./ft_longlong_len.o \
	   ./ft_put_u_longlong_base.o ./ft_strchr.o ./ft_u_len_base.o \
	   ./ft_memalloc.o ./ft_putchar.o ./ft_strcmp.o ./ft_u_longlong_len.o \
	   ./flag.o length.o ./print_flag.o ./round_ld.o ./flag_manager_f.o \
	   ./precision.o ./print_padding.o ./width.o ./f_to_s.o \
	   ./print_di.o ./print_f.o ./print_num.o \
	   ./print_o.o ./print_u.o ./print_x.o ./ft_printf.o ./parse.o

CCFL = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS) 
	@gcc $(CCFL) -I ./ -c $(SRCS) 
	@ar rc $(NAME) $(OBJS)
	 
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
