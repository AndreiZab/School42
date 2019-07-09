# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 15:32:40 by rhealitt          #+#    #+#              #
#    Updated: 2019/06/14 11:05:47 by rhealitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

LIBF = libft
PRIF = ft_printf

ALIB = libft/libft.a ft_printf/libftprintf.a


SRCS =  stack_manipulations01.c sort_remain.c \
        operations01.c operations02.c operations03.c hard_sort.c tools.c

OBJS = $(SRCS:.c=.o) checker.o push_swap.o

CCFL = -Wall -Wextra -Werror
LOG_RED = \033[1;31m
LOG_NOCOLOR	= \033[0m
LOG_GREEN = \033[32m

all: $(NAME2) $(NAME1)

$(NAME1): $(OBJS)
	@echo "$(LOG_GREEN) - Compiling ... $(LOG_NOCOLOR)"
	@make -C $(PRIF) re
	@make -C $(LIBF) re
	@gcc $(CCFL) checker.c $(ALIB) $(SRCS) $(LIBC) -o $(NAME1)
	@echo "$(LOG_GREEN)Push_swap created successfully$(LOG_NOCOLOR)"

$(NAME2): $(OBJS) $(ALIB)
	@gcc $(CCFL) push_swap.c $(ALIB) $(SRCS) -o $(NAME2)
	@echo "$(LOG_GREEN)Checker created successfully$(LOG_NOCOLOR)"

%.o: %.c libft/libft.h push_swap.h ft_printf/ft_printf.h
	@gcc -Wall -Wextra -Werror -c $<

libft/%.o: libft/%.c libft/libft.h
	@gcc -Wall -Wextra -Werror -c $<

clean:
	@make -C $(LIBF) clean
	@make -C $(PRIF) clean
	@echo "$(LOG_RED)Deleting project binaries $(LOG_NOCOLOR)"
	@/bin/rm -f $(OBJS)

fclean: clean
	@make -C $(LIBF) fclean
	@make -C $(PRIF) fclean
	@echo "$(LOG_RED)Deleting project$(LOG_NOCOLOR)"
	@/bin/rm -f $(NAME1)
	@/bin/rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re
