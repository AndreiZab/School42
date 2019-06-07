# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 15:32:40 by rhealitt          #+#    #+#              #
#    Updated: 2019/06/07 15:17:36 by rhealitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

LIBF = libft

SRCS =  stack_manipulations01.c sort_remain.c \
        operations01.c operations02.c operations03.c hard_sort.c tools.c

OBJS = $(SRCS:.c=.o) checker.o push_swap.o

CCFL = -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(NAME1):
	@make -C $(LIBF)
	@gcc $(CCFL) checker.c libft/libft.a -L $(LIBF)  $(SRCS) -I ./$(LIBF) -o $(NAME1) -lft

$(NAME2):
	@make -C $(LIBF) re
	@gcc $(CCFL) push_swap.c libft/libft.a -L $(LIBF)  $(SRCS) -I ./$(LIBF) -o $(NAME2) -lft

clean:
	@make -C $(LIBF) clean
	@/bin/rm -f $(OBJS)

fclean: clean
	@make -C $(LIBF) fclean
	@/bin/rm -f $(NAME1)
	@/bin/rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re
