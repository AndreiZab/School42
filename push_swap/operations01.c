/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:23:20 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/04 20:28:38 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack *stack, int print)
{
	int temp;
	int i;

	if (!stack || stack->len_a < 2)
		return ;
	i = stack->len_a - 1;
	temp = stack->a[i];
	stack->a[i] = stack->a[i - 1];
	stack->a[i - 1] = temp;
	if (print)
		write(1, "sa\n", 3);
}

void	do_sb(t_stack *stack, int print)
{
	int temp;
	int i;

	if (!stack || stack->len_b < 2)
		return ;
	i = stack->len_b - 1;
	temp = stack->b[i];
	stack->b[i] = stack->b[i - 1];
	stack->b[i - 1] = temp;
	if (print)
		write(1, "sb\n", 3);
}

void	do_ss(t_stack *stack, int print)
{
	int temp;
	int i;

	if (!stack || stack->len_b < 2 || stack->len_a < 2)
		return ;
	i = stack->len_b - 1;
	temp = stack->b[i];
	stack->b[i] = stack->b[i - 1];
	stack->b[i - 1] = temp;
	i = stack->len_a - 1;
	temp = stack->a[i];
	stack->a[i] = stack->a[i - 1];
	stack->a[i - 1] = temp;
	if (print)
		write(1, "ss\n", 3);
}

void	do_pa(t_stack *stack, int print)
{

	if (!stack || stack->len_b < 1)
		return ;
	stack->a[stack->len_a] = stack->b[stack->len_b - 1];
	stack->len_a++;
	stack->len_b--;
	if (print)
		write(1, "pa\n", 3);
}

void	do_pb(t_stack *stack, int print)
{

	if (!stack || stack->len_a < 1)
		return ;
	stack->b[stack->len_b] = stack->a[stack->len_a - 1];
	stack->len_b++;
	stack->len_a--;
	if (print)
		write(1, "pb\n", 3);
}
