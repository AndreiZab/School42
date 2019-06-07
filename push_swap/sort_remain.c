/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_remain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:32:34 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/06 15:23:33 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_2_element(t_stack *stack, char s)
{
	if (!stack)
		return ;
	if (s == 'b' && stack->b[stack->len_b - 1] < stack->b[stack->len_b - 2])
		do_sb(stack, 1);
	if (s == 'a' && stack->a[stack->len_a - 1] > stack->a[stack->len_a - 2])
		do_sa(stack, 1);
}

int			compare(int a, int b, int c)
{
	if (a > b && b > c)
		return (2);
	if (a > c && c > b)
		return (1);
	if (b > a && a > c)
		return (5);
	if (c > a && a > b)
		return (6);
	if (b > c && c > a)
		return (3);
	if (c > b && b > a)
		return (4);
	return (0);
}

void		do_swap(t_stack *stack, char s)
{
	if (s == 'a')
	{
		do_pb(stack, 1);
		do_sa(stack, 1);
		do_pa(stack, 1);
	}
	if (s == 'b')
	{
		do_pa(stack, 1);
		do_sb(stack, 1);
		do_pb(stack, 1);
	}
}

void		sort_3_element(t_stack *stack, char s)
{
	int cmp;

	if (s == 'a')
	{
		cmp = compare(stack->a[stack->len_a - 1], stack->a[stack->len_a - 2],
				stack->a[stack->len_a - 3]);
		if (cmp == 2 || cmp == 6 || cmp == 1)
			do_sa(stack, 1);
		if (cmp == 2 || cmp == 5 || cmp == 1 || cmp == 3)
			do_swap(stack, s);
		if (cmp == 2 || cmp == 5)
			do_sa(stack, 1);
	}
	if (s == 'b')
	{
		cmp = compare(stack->b[stack->len_b - 1], stack->b[stack->len_b - 2],
				stack->b[stack->len_b - 3]);
		if (cmp == 4 || cmp == 3 || cmp == 5)
			do_sb(stack, 1);
		if (cmp == 4 || cmp == 3 || cmp == 6 || cmp == 1)
			do_swap(stack, s);
		if (cmp == 4 || cmp == 6)
			do_sb(stack, 1);
	}
}

void		sort_3_elemnt(t_stack *stack, char s)
{
	int cmp;

	cmp = compare(stack->a[stack->len_a - 1], stack->a[stack->len_a - 2],
			stack->a[stack->len_a - 3]);
	if (s == 'b')
		cmp = compare(stack->b[stack->len_b - 1], stack->b[stack->len_b - 2],
				stack->b[stack->len_b - 3]);
	if (s == 'a' && (cmp == 5 || cmp == 3))
		do_rra(stack, 1);
	if (s == 'a' && (cmp == 2 || cmp == 6 || cmp == 3))
		do_sa(stack, 1);
	if (s == 'a' && cmp == 2)
		do_rra(stack, 1);
	if (s == 'a' && cmp == 1)
		do_ra(stack, 1);
	if (s == 'b' && (cmp == 1 || cmp == 6))
		do_rrb(stack, 1);
	if (s == 'b' && (cmp == 1 || cmp == 4 || cmp == 5))
		do_sb(stack, 1);
	if (s == 'b' && cmp == 4)
		do_rrb(stack, 1);
	if (s == 'b' && cmp == 3)
		do_rb(stack, 1);
}
