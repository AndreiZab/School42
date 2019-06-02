/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:23:17 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/31 21:13:45 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_stack *stack, int print)
{
	int i;
	int tmp;

	if (!stack || stack->len_a < 1)
		return ;
	i = stack->len_a - 1;
	tmp = stack->a[stack->len_a - 1];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	if (print)
		write(1, "rra\n", 3);
}

void	do_rrb(t_stack *stack, int print)
{
	int i;
	int tmp;

	if (!stack || stack->len_b < 1)
		return ;
	i = stack->len_b - 1;
	tmp = stack->b[stack->len_b - 1];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	if (print)
		write(1, "rrb\n", 3);
}

void	do_rrr(t_stack *stack, int print)
{
	int i;
	int tmp;

	if (!stack || stack->len_b < 1 || stack->len_a < 1)
		return ;
	i = stack->len_b - 1;
	tmp = stack->b[stack->len_b - 1];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	i = stack->len_a - 1;
	tmp = stack->a[stack->len_a - 1];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	if (print)
		write(1, "rrr\n", 3);
}
