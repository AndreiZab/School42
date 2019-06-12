/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:35:25 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/12 12:42:39 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_stack	*stack;
	int		v;

	if (argc > 1 && ++argv && *argv)
	{
		v = 0;
		if (argv[0][0] == '-' && argv[0][1] == 'v' && (v = 1) > 0)
		{
			if (argv[0][2] == '\0')
				argv++;
			else
				*argv = *argv + 3;
			if (argc > 2)
				argc--;
		}
		if (!(stack = parse_integers(argc - 1, argv, v)))
			return (write(2, "Error\n", 6));
		else if (ft_duplicates(stack->a, stack->len_a))
			return (del_stack(stack) + (int)write(2, "Error\n", 6));
		else if (!sorted(stack))
			stack->len_a > 6 ? hard_sort(stack, stack->len_a)
				: soft_sort(stack);
		del_stack(stack);
	}
	return (0);
}

/*
Будет краш, если количесво операций со стеком будет больше инта - фиксить?
 
@@@ Визуализировать операции со стеком
@@@ Сделать мейкфайл богов

Перед пушем удалить все не родные принты

SOLVED Обработать flag V
SOLVED Прогнать по тестам/ видел на форуме в интре
SOLVED Буква по середине слова пропускается - фиксануть
SOLVED Чекнуть работу с отрецательными числами
SOLVED Починить работу с отрицательными числами
SOLVED Ломается МAX_INT+1(2147483648) в валидаторе
SOLVED @ Сделать человеческий мейкфайл
SOLVED - Divide and Conquer(Merge sort)-Выбрать алгоритм для осн сорт-и
SOLVED Выбрать сортировку для не большого кол-ва элементов
SOLVED Где мой чек на дабл?!
SOLVED Значение больше инта просто непопало в массив, но и эрора нет!
*/