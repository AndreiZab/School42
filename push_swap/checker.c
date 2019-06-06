/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:14:22 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/05 20:57:11 by rhealitt         ###   ########.fr       */
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
		//
		break ;
		//
	}
	if (sorted(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

t_stack		*parse_one_str(char *str)
{
	t_stack	*stack;
	char	**temp;
	int		i;

	if (!(temp = ft_strsplit(str, ' ')))
		return (0);
	i = 0;
	while (temp[i])
		i++;
	stack = create_stack(i);
	i = -1;
	while (temp[++i])
	{
		stack->a[i] = ft_atoi(temp[i]);
		if (stack->a[i] == 0 && temp[i][0] != '0')
		{
			ft_free_2d_array(temp);
			del_stack(stack);
			return (0);
		}
	}
	stack->a = ft_reverce(stack->a, stack->len_a);
	ft_free_2d_array(temp);
	return (stack);
}

t_stack		*parse_integers(int len, char **str)
{
	t_stack *tmp;
	int		i;

	if (len == 1)
		return (parse_one_str(str[0]));
	if (!(validation_str(str)))
		return (0);
	tmp = create_stack(len);
	i = -1;
	while (++i < len)
	{
		tmp->a[i] = ft_atoi(str[i]);
		if (tmp->a[i] == 0 && str[i][0] != '0')
			return (del_stack(tmp));
	}
	tmp->a = ft_reverce(tmp->a, tmp->len_a);
	return (tmp);
}
/*
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
*/