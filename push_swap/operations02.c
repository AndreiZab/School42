/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:23:24 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/31 21:05:33 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stack *stack, int print)
{
	int i;
	int tmp;

	if (!stack || stack->len_a < 1)
		return ;
	i = 0;
	tmp = stack->a[i];
	while (i < stack->len_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->len_a - 1] = tmp;
	if (print)
		write(1, "ra\n", 3);
}

void	do_rb(t_stack *stack, int print)
{
	int i;
	int tmp;

	if (!stack || stack->len_b < 1)
		return ;
	i = 0;
	tmp = stack->b[i];
	while (i < stack->len_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->len_b - 1] = tmp;
	if (print)
		write(1, "rb\n", 3);
}

void	do_rr(t_stack *stack, int print)
{
	int i;
	int tmp;

	if (!stack || stack->len_b < 1 || stack->len_a < 1)
		return ;
	i = 0;
	tmp = stack->b[i];
	while (i < stack->len_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->len_b - 1] = tmp;
	i = 0;
	tmp = stack->a[i];
	while (i < stack->len_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->len_a - 1] = tmp;
	if (print)
		write(1, "rr\n", 3);
}