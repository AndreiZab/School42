/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 11:37:27 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/23 18:09:40 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../includes/Libft/libft.h"
# define BUFF_SIZE 1024

int     connect_validation(char *str);
int     ft_read(int fd, char *buf);
int     size_validation(char *s);

typedef struct	s_termino
{
	char	width;
	char	height;
	char	**arr;
}				t_termino;

typedef struct s_map
{
	char size;
	char **arr;
	t_termino **best;
}				t_map;

t_termino   *parse_termino(char *str);
void    show_termino(t_termino *elem);

#endif
