/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:23:17 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/04 20:38:25 by rhealitt         ###   ########.fr       */
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
	if (print)
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
	if (print)
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
	if (print)
		write(1, "rrr\n", 4);
}
