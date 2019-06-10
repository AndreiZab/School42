/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:23:24 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/10 13:24:49 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define GREEN "\x1b[32m"
#define NO_C "\x1b[0m"

void	do_ra(t_stack *stack, int print)
{
	int i;
	int tmp;

	if (!stack || stack->len_a < 1)
		return ;
	i = stack->len_a;
	tmp = stack->a[i - 1];
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = tmp;
	if (print && stack->v)
		print_v(stack, "ra");
	else if (print)
		write(1, "ra\n", 3);
}

void	do_rb(t_stack *stack, int print)
{
	int i;
	int tmp;

	if (!stack || stack->len_b < 1)
		return ;
	i = stack->len_b;
	tmp = stack->b[i - 1];
	while (--i > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = tmp;
	if (print && stack->v)
		print_v(stack, "rb");
	else if (print)
		write(1, "rb\n", 3);
}

void	do_rr(t_stack *stack, int print)
{
	int i;
	int tmp;

	if (!stack || stack->len_a < 1 || stack->len_b < 1)
		return ;
	i = stack->len_a;
	tmp = stack->a[i - 1];
	while (--i > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = tmp;
	i = stack->len_b;
	tmp = stack->b[i - 1];
	while (--i > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = tmp;
	if (print && stack->v)
		print_v(stack, "rr");
	else if (print)
		write(1, "rr\n", 3);
}
