/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:35:25 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/07 19:57:17 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stack(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->len_a)
	{
		printf("%d\n", stack->a[i]);
		i++;
	}
	printf("---\n");
	i = 0;
	while (i < stack->len_b)
	{
		printf("%d\n", stack->b[i]);
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_stack	*stack;

	argv++;
	if (argc > 1 && argv && *argv)
	{

		if (!(stack = parse_integers(argc - 1, argv)))
			return (write(2, "Error\n", 6));
		else if (ft_duplicates(stack->a, stack->len_a))
		{
			del_stack(stack);
			return (write(2, "Error\n", 6));
		}
		else if (!sorted(stack))
		{
			if (stack->len_a > 6)
				hard_sort(stack, stack->len_a);
			else if (stack->len_a <= 6)
				soft_sort(stack, stack->len_a);
		}
		del_stack(stack);
	}
	return (0);
}

/*
Буква по середине слова пропускается - фиксануть
Будет краш, если колличесво операций со стеком будет больше инта - фиксить?
±Чекнуть работу с отрецательными числами
 
@@@ Визуализировать операции со стеком
@@@ Сделать мейкфайл богов

Прогнать по тестам/ видел на форуме в интре
Перед пушем удалить все принты

SOLVED Починить работу с отрицательными числами
SOLVED Ломается МAX_INT+1(2147483648) в валидаторе
SOLVED @ Сделать человеческий мейкфайл
SOLVED - Divide and Conquer(Merge sort)-Выбрать алгоритм для осн сорт-и
SOLVED Выбрать сортировку для не большого кол-ва элементов
SOLVED Где мой чек на дабл?!
SOLVED Значение больше инта просто непопало в массив, но и эрора нет!
*/