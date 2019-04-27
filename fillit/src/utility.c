/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 15:13:25 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/26 14:32:35 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt_plus(int nb)
{
	int i;

	i = 1;
	if (nb < 0 || nb == 0)
		return (0);
	while (i * i < nb)
		i = i + 1;
	return (i);
}

void	ft_putnchar(char *str, int n)
{
	write(1, str, n);
}

void	map_show(t_map *map)
{
	int		y;

	y = 0;
	while (y < map->size)
	{
		ft_putnchar(map->arr[y], map->size);
		ft_putchar('\n');
		++y;
	}
}

void	map_del(t_map **map)
{
	t_map	*ptr;
	int		i;

	ptr = *map;
	i = 0;
	while (i < 13)
		free(ptr->arr[i++]);
	free(ptr->arr);
	free(ptr);
	*map = NULL;
}