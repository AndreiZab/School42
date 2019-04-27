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

char		**get_arr(char *s, char ox, char oy, t_termino *elem)
{
	char	**arr;
	int		y;

	arr = (char**)malloc(sizeof(char*) * elem->height);
	y = 0;
	while (y < elem->height)
	{
		arr[y] = (char*)malloc(elem->width);
		ft_memcpy(arr[y], s + (y + oy) * 5 + ox, elem->width);
		++y;
	}
	return (arr);
}

t_termino	*parse_termino(char *str)
{
	t_termino	*elem;
	char		*pos;
	int			i;

	elem = (t_termino*)malloc(sizeof(t_termino));
	pos = ft_strnew(3);
	pos[0] = 5;
	pos[1] = 5;
	i = -1;
	while (str[++i])
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
	elem->width = pos[2] - pos[0] + 1;
	elem->height = pos[3] - pos[1] + 1;
	elem->arr = get_arr(str, pos[0], pos[1], elem);
	return (elem);
}
