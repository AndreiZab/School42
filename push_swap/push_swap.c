/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:35:25 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/10 13:30:58 by rhealitt         ###   ########.fr       */
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
				: soft_sort(stack, stack->len_a);
		del_stack(stack);
	}
	return (0);
}
