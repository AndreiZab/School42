/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:23:17 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/10 14:15:15 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_stack *stack, int print)
{
	int i;
	int tmp;

	if (!stack || stack->len_a < 1)
		return ;
	tmp = stack->a[0];
	i = 0;
	while (++i < stack->len_a)
		stack->a[i - 1] = stack->a[i];
	stack->a[i - 1] = tmp;
	if (print && stack->v)
		print_v(stack, "rra");
	else if (print)
		write(1, "rra\n", 4);
}

void	do_rrb(t_stack *stack, int print)
{
	int i;
	int tmp;

	if (!stack || stack->len_b < 1)
		return ;
	tmp = stack->b[0];
	i = 0;
	while (++i < stack->len_b)
		stack->b[i - 1] = stack->b[i];
	stack->b[i - 1] = tmp;
	if (print && stack->v)
		print_v(stack, "rrb");
	else if (print)
		write(1, "rrb\n", 4);
}

void	do_rrr(t_stack *stack, int print)
{
	int i;
	int tmp;

	if (!stack || stack->len_b < 1 || stack->len_a < 1)
		return ;
	tmp = stack->a[0];
	i = 0;
	while (++i < stack->len_a)
		stack->a[i - 1] = stack->a[i];
	stack->a[i - 1] = tmp;
	tmp = stack->b[0];
	i = 0;
	while (++i < stack->len_b)
		stack->b[i - 1] = stack->b[i];
	stack->b[i - 1] = tmp;
	if (print && stack->v)
		print_v(stack, "rrr");
	else if (print)
		write(1, "rrr\n", 4);
}

t_stack	*parse_integers(int len, char **str, int v)
{
	t_stack	*tmp;
	int		i;

	if (!(validation_str(str, len)))
		return (0);
	if (len == 1)
		return (parse_one_str(str[0], v));
	tmp = create_stack(len);
	tmp->v = (v == 1) ? 1 : 0;
	i = -1;
	while (++i < len)
	{
		tmp->a[i] = ft_atoi(str[i]);
		if (tmp->a[i] == 0 && str[i][0] != '0' && !del_stack(tmp))
			return (0);
	}
	tmp->a = ft_reverce(tmp->a, tmp->len_a);
	return (tmp);
}

void	print_v(t_stack *stack, char *str)
{
	int i;
	int tmp_la;
	int tmp_lb;

	tmp_la = stack->len_a;
	tmp_lb = stack->len_b;
	i = (stack->len_a > stack->len_b) ? stack->len_a : stack->len_b;
	ft_printf("\nExec:"LYELLOW" %s\n"NO_C, str);
	while (--i >= 0)
	{
		system("sleep 0.5");
		if (tmp_lb >= 1 && tmp_la >= 1)
			ft_printf("%-4d|%3d\n", stack->a[--tmp_la], stack->b[--tmp_lb]);
		else if (tmp_lb < 1)
			ft_printf("%-4d|%3c\n", stack->a[--tmp_la], ' ');
		else if (tmp_la < 1)
			ft_printf("%-4c|%3d\n", ' ', stack->b[--tmp_lb]);
	}
}
