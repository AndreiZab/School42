# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 15:32:40 by rhealitt          #+#    #+#              #
#    Updated: 2019/04/27 14:25:55 by rhealitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBF = libft

SRCS = main.c parser.c solver.c utility.c validation.c

CCFL = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIBF) re
	@gcc $(CCFL) -L $(LIBF)  $(SRCS) -I $(LIBF) -I /. -o $(NAME) -lft

clean:
	@make -C $(LIBF) clean

fclean: clean
	@make -C $(LIBF) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
