# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 15:32:40 by rhealitt          #+#    #+#              #
#    Updated: 2019/06/07 20:57:11 by rhealitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

LIBF = libft

SRCS =  stack_manipulations01.c sort_remain.c \
        operations01.c operations02.c operations03.c hard_sort.c tools.c

OBJS = $(SRCS:.c=.o) checker.o push_swap.o

CCFL = -Wall -Wextra -Werror
LOG_RED = \033[1;31m
LOG_NOCOLOR	= \033[0m
LOG_GREEN = \033[32m

all: $(NAME1) $(NAME2)

$(NAME1):
	@echo "$(LOG_GREEN) - Compiling ... $(LOG_NOCOLOR)"
	@make -C $(LIBF)
	@gcc $(CCFL) checker.c libft/libft.a $(SRCS) -I ./$(LIBF) -L $(LIBF) -lft -o $(NAME1)
	@echo "$(LOG_GREEN)Push_swap created successfully$(LOG_NOCOLOR)"

$(NAME2):
	@gcc $(CCFL) push_swap.c libft/libft.a $(SRCS) -I ./$(LIBF) -L $(LIBF) -lft -o $(NAME2)
	@echo "$(LOG_GREEN)Checker created successfully$(LOG_NOCOLOR)"

clean:
	@make -C $(LIBF) clean
	@echo "$(LOG_RED)Deleting project binaries $(LOG_NOCOLOR)"
	@/bin/rm -f $(OBJS)

fclean: clean
	@make -C $(LIBF) fclean
	@echo "$(LOG_RED)Deleting project$(LOG_NOCOLOR)"
	@/bin/rm -f $(NAME1)
	@/bin/rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re
