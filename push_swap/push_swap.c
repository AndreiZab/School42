/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:35:25 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/02 10:18:17 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_stack	*stack;

	argv++;
	if (argc > 1 && argv && *argv)
	{

		if (!(stack = parse_integers(argc - 1, argv)))
			return (write(2, "Error\n", 6));
		if (!sorted(stack))
		{
			if (stack->len_a > )//Сколько?
				hard_sort(stack);//тяжелая сортировка
			else
				soft_sort(stack);
		}
		del_stack(stack);
	}
	return (0);
}