# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 15:32:40 by rhealitt          #+#    #+#              #
#    Updated: 2019/04/19 17:25:17 by rhealitt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBF = libft

INCL = src/

SRCS = src/main.c src/parser.c src/solver.c src/utility.c src/validation.c

CCFL = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIBF) re
	@gcc $(CCFL) -L $(LIBF)  $(SRCS) -I $(LIBF) -I $(INCL) -o $(NAME) -lft

clean:
	@make -C $(LIBF) clean

fclean: clean
	@make -C $(LIBF) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
