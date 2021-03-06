/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:42:02 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/27 17:51:16 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

char	can_place(t_map *map, t_termino *term)
{
	int		y;
	int		x;

	if (term->x + term->width >= map->size ||
		term->y + term->height >= map->size)
		return (0);
	y = 0;
	while (y < term->height)
	{
		x = 0;
		while (x < term->width)
		{
			if (term->arr[y][x] == '#' &&
				map->arr[y + term->y][x + term->x] != '.')
				return (0);
			++x;
		}
		++y;
	}
	return (1);
}

void	map_place_remove(t_map *map, t_termino *term, char place)
{
	int		y;
	int		x;
	char	symb;

	symb = (place == 1) ? term->symbol : '.';
	y = 0;
	while (y < term->height)
	{
		x = 0;
		while (x < term->width)
		{
			if (term->arr[y][x] == '#')
				map->arr[y + term->y][x + term->x] = symb;
			++x;
		}
		++y;
	}
}

int		solve(t_map *map, t_termino **figures, int count, int term_i)
{
	if (term_i == count)
		return (1);
	figures[term_i]->y = 0;
	while (figures[term_i]->y < map->size - figures[term_i]->height + 1)
	{
		figures[term_i]->x = 0;
		while (figures[term_i]->x < map->size - figures[term_i]->width + 1)
		{
			if (can_place(map, figures[term_i]))
			{
				map_place_remove(map, figures[term_i], 1);
				if (solve(map, figures, count, term_i + 1) == 1)
					return (1);
				map_place_remove(map, figures[term_i], 0);
			}
			++figures[term_i]->x;
		}
		++figures[term_i]->y;
	}
	return (0);
}

t_map	*map_new(void)
{
	t_map	*map;
	int		i;

	if ((map = (t_map*)malloc(sizeof(t_map))) == NULL)
		exit(0);
	map->size = 13;
	if ((map->arr = (char**)malloc(sizeof(char*) * map->size)) == NULL)
		exit(0);
	i = 0;
	while (i < map->size)
	{
		if ((map->arr[i] = ft_memalloc(map->size)) == NULL)
		{
			ft_free(map->arr);
			exit(0);
		}
		ft_memset(map->arr[i++], '.', map->size);
	}
	return (map);
}

void	solver(t_termino **terms, int count)
{
	t_map *map;

	map = map_new();
	map->size = ft_sqrt_plus(count * 4);
	while (solve(map, terms, count, 0) == 0)
		map->size += 1;
	map->size -= 1;
	map_show(map);
	map_del(&map);
}
