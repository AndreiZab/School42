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
    //Прилегает к левому верхнему углу
    if ((term->y == 0 && term->x < 6) || (term->x == 0 && term->y < 6))
        return (1);
    //Есть соприкосновения
    y = 0;
    if (term->x != 0)
    {
        while (y < term->height)
        {
            if (map->arr[term->x - 1][term->y + y] == '#')
                return (1);
            ++y;
        }
    }
    x = 0;
    if (term->y != 0)
    {
        while (x < term->width)
        {
            if (map->arr[term->x + x][term->y - 1] == '#')
                return (1);
            ++x;
        }
    }
    return (0);
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
void    solve(t_map *map, t_termino **figures, int count, int depth)
{
    int term_i;
    int this_size;

    if (depth == 0) //or == 1
    {
        this_size = map_calcsize(figures, count);
        if (this_size < map->size)
        {
            map_best(map, figures, count);
            map->size = this_size;
        }
        return ;
    }
    term_i = 0;
    while (term_i < count)
    {
        if (figures[term_i]->used == 0)
        {
            figures[term_i]->used = 1;
            figures[term_i]->y = 0;
            while (figures[term_i]->y < map->size - figures[term_i]->height + 1)
            {
                figures[term_i]->x = 0;
                while (figures[term_i]->x < map->size - figures[term_i]->width + 1)
                {
                    if (can_place(map, figures[term_i]))
                    {
                        map_place(map, figures[term_i]);
                        solve(map, figures, count, depth - 1);
						++ticks;
                        map_remove(map, figures[term_i]);
                    }
                    ++figures[term_i]->x;
                }
                ++figures[term_i]->y;
            }
            figures[term_i]->used = 0;
        }
        ++term_i;
    }
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
    solve(map, terms, count, count);
    map_showbest(map, terms, count);
	printf("Ticks: %d\n", ticks);
}
