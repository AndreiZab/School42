/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:14:22 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/07 15:08:15 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		gnl(t_stack *stack, char *line)
{
	if (!ft_strcmp(line, "pb"))
		do_pb(stack, 0);
	else if (!ft_strcmp(line, "pa"))
		do_pa(stack, 0);
	else if (!ft_strcmp(line, "sb"))
		do_sb(stack, 0);
	else if (!ft_strcmp(line, "sa"))
		do_sa(stack, 0);
	else if (!ft_strcmp(line, "ss"))
		do_ss(stack, 0);
	else if (!ft_strcmp(line, "ra"))
		do_ra(stack, 0);
	else if (!ft_strcmp(line, "rb"))
		do_rb(stack, 0);
	else if (!ft_strcmp(line, "rrb"))
		do_rrb(stack, 0);
	else if (!ft_strcmp(line, "rra"))
		do_rra(stack, 0);
	else if (!ft_strcmp(line, "rrr"))
		do_rrr(stack, 0);
	else if (!ft_strcmp(line, "rr"))
		do_rr(stack, 0);
	else
		exit(write(2, "Error\n", 6));
}

void		parse_instructions(t_stack *stack)
{
	char	*line;

	while (get_next_line(0, &line) == 1)
	{
		gnl(stack, line);
		free(line);
	}
	if (sorted(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int			main(int argc, char **argv)
{
	t_stack	*stack;

	argv++;
	if (argc > 1 && argv && *argv)
	{
		if (!(stack = parse_integers(argc - 1, argv)))
			return (write(2, "Error\n", 6));
		if (ft_duplicates(stack->a, stack->len_a))
		{
			del_stack(stack);
			return (write(2, "Error\n", 6));
		}
		parse_instructions(stack);
		del_stack(stack);
	}
	return (0);
}
