/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 17:42:02 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/25 18:34:23 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

//Примерный алгоритм.
//ВУОРНИНГ МОЖЕТ НЕ РАБОТАТЬ

char    can_place(t_map *map, t_termino *term)
{
    int y;
    int x;
    //optimization mark
    //termy, termx
    if (term->x + term->width >= map->size || term->y + term->height >= map->size)
        return (0);
    y = 0;
    //Нет столкновений
    while (y < term->height)
    {
        x = 0;
        while (x < term->width)
        {
            if (term->arr[y][x] == '#' && map->arr[y + term->y][x + term->x] == '#')
                return (0);
            ++x;
        }
        ++y;
    }
    return (1);
}

void    map_place(t_map *map, t_termino *term)
{
    int y;
    int x;
    //optimization mark
    //termy, termx
    y = 0;
    while (y < term->height)
    {
        x = 0;
        while (x < term->width)
        {
            if (term->arr[y][x] == '#')
                map->arr[y + term->y][x + term->x] = '#';
            ++x;
        }
        ++y;
    }
}

void    map_place_a(t_map *map, t_termino *term, char num)
{
    int y;
    int x;
    //optimization mark
    //termy, termx
    y = 0;
    while (y < term->height)
    {
        x = 0;
        while (x < term->width)
        {
            if (term->arr[y][x] == '#')
                map->arr[y + term->y][x + term->x] = 'A' + num;
            ++x;
        }
        ++y;
    }
}

void    map_remove(t_map *map, t_termino *term)
{
    int y;
    int x;
    //optimization mark
    //termy, termx
    y = 0;
    while (y < term->height)
    {
        x = 0;
        while (x < term->width)
        {
            if (term->arr[y][x] == '#')
                map->arr[y + term->y][x + term->x] = '.';
            ++x;
        }
        ++y;
    }
}

char    map_calcsize(t_termino **terms, char count)
{
    char size_x;
    char size_y;
    int i;

    size_x = 0;
    size_y = 0;
    i = 0;
    while (i < count)
    {
        if (terms[i]->x + terms[i]->width > size_x)
            size_x = terms[i]->x + terms[i]->width;
        if (terms[i]->y + terms[i]->height > size_y)
            size_y = terms[i]->y + terms[i]->height;
        ++i;
    }
    size_x = (size_x > size_y) ? size_x : size_y;
    return (size_x);
}

void    map_best(t_map *map, t_termino **figures, int count)
{
    while (count--)
    {
        map->best[count]->x = figures[count]->x;
        map->best[count]->y = figures[count]->y;
    }
}

int ticks = 0;

//оптимальный размер карты изначально - 13x13
//optimization mark
//адаптивный размер?
int    solve(t_map *map, t_termino **figures, int count, int term_i)
{
    //int this_size;

    if (term_i == count) //or == 1
    {
        map_best(map, figures, count);
        return (1);
    }
    figures[term_i]->y = 0;
    while (figures[term_i]->y < map->size - figures[term_i]->height + 1)
    {
        figures[term_i]->x = 0;
        while (figures[term_i]->x < map->size - figures[term_i]->width + 1)
        {
            if (can_place(map, figures[term_i]))
            {
                map_place(map, figures[term_i]);
                if (solve(map, figures, count, term_i + 1) == 1)
                    return (1);
                ++ticks;
                map_remove(map, figures[term_i]);
            }
            ++figures[term_i]->x;
        }
        ++figures[term_i]->y;
    }
    return (0);
}

t_map   *map_new(int term_count)
{
    t_map   *map;
    int   i;

    map = (t_map*)malloc(sizeof(t_map));
    map->term_count = term_count;
    map->best = (t_termino**)malloc(sizeof(t_termino*) * term_count);
    while (term_count--)
        map->best[term_count] = (t_termino*)malloc(sizeof(t_termino));
    map->size = 13;
    map->arr = (char**)malloc(sizeof(char*) * map->size);
    i = 0;
    while (i < map->size)
    {
        map->arr[i] = ft_memalloc(map->size);
        ft_memset(map->arr[i++], '.', map->size);
    }
        
    return (map);
    
}

void    map_showbest(t_map *map, t_termino **terms, int count)
{
    int x;
    int y;
    int i;

    i = 0;
    while (i < count)
    {
        terms[i]->x = map->best[i]->x;
        terms[i]->y = map->best[i]->y;
        map_place_a(map, terms[i], i);
        ++i;
    }
    y = 0;
    while (y < map->size)
    {
        x = 0;
        while (x < map->size)
        {
            ft_putchar(map->arr[y][x]);
            ++x;
        }
        ++y;
        ft_putchar('\n');
    }
        
}

#include <stdio.h>

void solver(t_termino **terms, int count)
{
    t_map *map;

    map = map_new(count);
    map->size = 5;
    while (solve(map, terms, count, 0) == 0)
        map->size += 1;
    map->size -= 1;
    map_showbest(map, terms, count);
	//printf("Ticks: %d\n", ticks);
}
