/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 19:36:16 by larlyne           #+#    #+#             */
/*   Updated: 2019/04/23 19:36:26 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char        **get_arr(char *s, char ox, char oy, char w, char  h)
{
    char    **arr;
    int     y;

    arr = (char**)malloc(sizeof(char*) * h );
    y = 0;
    while (y < h)
    {
        arr[y] = (char*)malloc(w);
        ft_memcpy(arr[y], s + y * 5 + ox, w);
        ++y;
    }
    return (arr);
}

t_termino   *parse_termino(char *str)
{
    t_termino   *elem;
    char *pos; //0 - xmin; 1 - ymin; 2 - xmax; 3 - ymax
    int i;

    elem = (t_termino*)malloc(sizeof(t_termino));
    pos = ft_strnew(3);
    i = 0;
    while (str[i])
    {
        if (str[i] == '#')
        {
            if (i % 5 < pos[0])
                pos[0] = i % 5;
            if (i % 5 > pos[2])
                pos[2] = i % 5;
            if (i / 5 < pos[1])
                pos[1] = i / 5;
            if (i / 5 > pos[3])
                pos[3] = i / 5;
        }
        ++i;
    }
    elem->width = pos[2] - pos[0] + 1;
    elem->height = pos[3] - pos[1] + 1;
    elem->arr = get_arr(s, pos[0], pos[1], elem->width, elem->height);
    return (elem);
}
