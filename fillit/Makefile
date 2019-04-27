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

LNAM = libft.a

LIBF = libft

INCL = ./src/

SRCS = ./src

CCFL = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIBF) re
	@$(CCFL) -L $(LIBF)  $(SRCS)/*.c -I $(LIBF) -I $(INCL) -o $(NAME) -lft

clean:
	@make -C $(LIBF) clean

fclean: clean
	@make -C $(LIBF) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
