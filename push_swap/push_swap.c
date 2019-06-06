/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:35:25 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/06 16:35:44 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack)
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

	//	ft_reverce(stack->a, stack->len_a);
//		print_stack(stack);

		del_stack(stack);
	}
	return (0);
}

/*

Будет краш, если колличесво операций со стеком будет больше инта - фиксить?
Визуализировать операции со стеком

@ Сделать человеческий мейкфайл
@ Прогнать по тестам/ видел на форуме в интре
@ Переде пушем удалить все принты

SOLVED  - Divide and conquer (Merge sort)  -  Выбрать алгоритм для основной сортировки
SOLVED Выбрать сортировку для не большого кол-ва элементов
SOLVED Где мой чек на дабл?!
SOLVED Значение больше инта просто непопало в массив, но и эрора нет!

*/
