/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:23:20 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/31 13:08:18 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void do_sa(t_stack *stack, int print)
{
	int temp;

	if (!stack || stack->len_a < 2)
		return ;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	if (print)
		write(1, "sa\n", 3);
}

void do_sb(t_stack *stack, int print)
{
	int temp;

	if (!stack || stack->len_b < 2)
		return ;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	if (print)
		write(1, "sb\n", 3);
}

void do_ss(t_stack *stack, int print)
{
	int temp;

	if (!stack || stack->len_b < 2 || stack->len_a < 2 )
		return ;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	if (print)
		write(1, "ss\n", 3);
}

void do_pa(t_stack *stack, int print)
{
	int i;

	if (!stack || stack->len_b < 1)
		return ;
	i = stack->len_a;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = stack->b[0];
	stack->len_a++;
	stack->len_b--;
	i = 0;
	while (i < stack->len_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	if (print)
		write(1, "pa\n", 3);
}

void do_pb(t_stack *stack, int print)
{
	int i;

	if (!stack || stack->len_a < 1)
		return ;
	i = stack->len_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = stack->a[0];
	stack->len_b++;
	stack->len_a--;
	i = 0;
	while (i < stack->len_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	if (print)
		write(1, "pb\n", 3);

}