/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:14:22 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/02 10:18:17 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	gnl(t_stack	*stack, char *line)
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
	//передавать в команды значение для печати?
}

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

void		parse_instructions(t_stack *stack)
{
	char	*line;

//	print_stack(stack);
	while (get_next_line(0, &line) == 1)
	{
		gnl(stack, line);
		free(line);
		//
		break;
		//
	}
//	print_stack(stack);
	if (sorted(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

t_stack		*parse_one_str(char *str)
{
	t_stack	*stack;
	char	**temp;
	int i;

	if(!(temp = ft_strsplit(str, ' ')))
		return (0);
	i = 0;
	while (temp[i])
		i++;
	stack = create_stack(i);
	i = 0;
	while(temp[i])
	{
		stack->a[i] = ft_atoi(temp[i]);
		if (stack->a == 0 && temp[i][0] != '0')
		{
			ft_free_2d_array(temp);
			del_stack(stack);
			return(0);
		}
	}
	ft_free_2d_array(temp);
	return (stack);

}

t_stack		*parse_integers(int len, char **str)
{
	t_stack *tmp;
	int i;

	if (len == 1)
		return (parse_one_str(str[0]));
	if (!(validation_str(str)))
		return (0);
	tmp = create_stack(len);
	i = -1;
	while (++i < len)
	{
		tmp->a[i] = ft_atoi(str[i]);
		if (tmp->a == 0 && str[i][0] != '0')
			return (del_stack(tmp));
	}
	//чек на повторы происходит после сортировки :C
	return (tmp);
}

int			main(int argc, char **argv)
{
	t_stack	*stack;

	argv++;
	if (argc > 1 && argv && *argv)
	{

		if (!(stack = parse_integers(argc - 1, argv)))
			return (write(2, "Error\n", 6));
		parse_instructions(stack);
		del_stack(stack);
	}
	return (0);
}