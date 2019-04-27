/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 11:37:27 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/27 17:08:10 by rhealitt         ###   ########.fr       */
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

int				validation(char *s);
void			ft_free(char **str);

typedef struct	s_termino
{
	char	width;
	char	height;
	char	**arr;
	char	x;
	char	y;
	char	symbol;
}				t_termino;

int				ft_read(int fd, t_termino ***terms, int *count);

typedef struct	s_map
{
	char	size;
	char	**arr;
}				t_map;

t_termino		*parse_termino(char *str);
void			show_termino(t_termino *elem);
void			solver(t_termino **terms, int count);

int				ft_sqrt_plus(int nb);
void			map_show(t_map *map);
void			map_del(t_map **map);
void			terms_del(t_termino ***terms, int count);

#endif
