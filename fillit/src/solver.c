

#include "fillit.h"

//Примерный алгоритм.
//ВУОРНИНГ МОЖЕТ НЕ РАБОТАТЬ

char    can_place(t_map *map, t_termino *term)
{
    char y;
    char x;

    if (term->x + term->width >= map->size || term->y + term->height >= map->size)
        return (0);
    y = 0;
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
    char y;
    char x;

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
    char y;
    char x;

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
    char y;
    char x;

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

char    map_calsize(t_termino **terms, char count)
{
    char size_x;
    char size_y;
    char i;

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
}

void    map_best(t_map *map, t_termino **figures, int count)
{
    while (count--)
    {
        map->best[count]->x = figures[count]->x;
        map->best[count]->y = figures[count]->y;
    }
}

//оптимальный размер карты изначально - 13x13
void    solve(t_map *map, t_termino **figures, int count, int depth)
{
    int term_i;
    int pos[2]; //0 - y, 1 - x
    int this_size;

    if (depth == 0) //or == 1
    {
        this_size = map_calcsize(map);
        if (this_size < map->)
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
                        solve(map, figs, count, depth - 1);
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

t_map   *map_new(char term_count)
{
    t_map   *map;
    char    i;

    map = (t_map*)malloc(sizeof(t_map));
    map->term_count = term_count;
    map->best = (t_termino**)malloc(sizeof(t_termino*) * term_count);
    while (term_count--)
        map->best = (t_termino*)malloc(sizeof(t_termino));
    map->size = 13;
    map->arr = (char**)malloc(sizeof(char*) * map->size);
    i = 0;
    while (i < map->size)
        arr[i++] = ft_strnew(map->size - 1);
    return (map);
    
}

void    map_showbest(t_map *map, t_termino **terms, char count)
{
    char x;
    char y;

    while (--count)
    {
        terms[count]->x = map->best[count]->x;
        terms[count]->y = map->best[count]->y;
        map_place_a(map, terms[count], count);
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

void solver(t_termino **terms, char count)
{
    t_map *map;

    map = map_new(count);
    solve(map, terms, count, count);
    map_showbest(map, count);
}