/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 11:37:27 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/20 16:03:00 by rhealitt         ###   ########.fr       */
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

ssize_t check_line_cube(char *str);
ssize_t check_g(char *str);
ssize_t check_l(char *str);
ssize_t check_t(char *str);
ssize_t check_z(char *str);

typedef struct  t_termino
{
    char    width;
    char    height;
    char    **arr;
}

#endif
