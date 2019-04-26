/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 11:37:27 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/26 13:28:49 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 1024

int     validation(char *s);

typedef struct	s_termino
{
	char	width;
	char	height;
	char	**arr;
	char	x;
	char	y;
	char	used;
}				t_termino;

int     ft_read(int fd, t_termino ***terms, int *count);

typedef struct s_map
{
	char size;
	char **arr;
	char term_count;
	t_termino **best;
}				t_map;

t_termino   *parse_termino(char *str);
void    show_termino(t_termino *elem);
void	solver(t_termino **terms, int count);

int		ft_sqrt_plus(int nb);

//optimization mark
//struct t_point

#endif
