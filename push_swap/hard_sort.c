/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 12:11:25 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/06 15:09:27 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		split_a(t_stack *stack)
{
	int m;
	int i;
	int back;
	int push;

	m = ft_median(stack->a, stack->len_a);
	i = stack->len_a;
	back = 0;
	push = 0;
	while (--i >= 0)
	{
		if (stack->a[stack->len_a - 1] < m && ++push)
			do_pb(stack, 1);
		if (stack->a[stack->len_a - 1] >= m && ++back)
			do_ra(stack, 1);
	}
	while (back-- > 0)
		do_rra(stack, 1);
	return (push);
}

int		split_b(t_stack *stack)
{
	int m;
	int i;
	int back;
	int push;

	m = ft_median(stack->b, stack->len_b);
	i = stack->len_b;
	back = 0;
	push = 0;
	while (--i >= 0)
	{
		if (stack->b[stack->len_b - 1] >= m && ++push)
			do_pa(stack, 1);
		if (stack->b[stack->len_b - 1] < m && ++back)
			do_rb(stack, 1);
	}
	while (back-- > 0)
		do_rrb(stack, 1);
	return (push);
}

void 	sort_b(t_stack *stack, int max)
{
	int push_in_a;
	int	*tmp_a;
	int	tmp_len;

	if (max > 3)
	{
		push_in_a = split_b(stack);
		sort_b(stack, stack->len_b);
		tmp_a = stack->a;
		tmp_len = stack->len_a;
		stack->a = tmp_a + (tmp_len - push_in_a);
		stack->len_a = push_in_a;
		hard_sort(stack, push_in_a);
		stack->a = tmp_a;
		stack->len_a = tmp_len;
		while (--push_in_a >= 0)
			do_pb(stack, 1);
	}
	else if (max == 2)
		sort_2_element(stack, 'b');
	else if (max == 3)
		sort_3_element(stack, 'b');
}

void 	hard_sort(t_stack *stack, int max)
{
	int push_in_b;
	int	*tmp_b;
	int	tmp_len;

	if (max > 3)
	{
		push_in_b = split_a(stack);
		hard_sort(stack, stack->len_a);
		tmp_b = stack->b;
		tmp_len = stack->len_b;
		stack->b = tmp_b + (tmp_len - push_in_b);
		stack->len_b = push_in_b;
		sort_b(stack, push_in_b);
		stack->b = tmp_b;
		stack->len_b = tmp_len;
		while (--push_in_b >= 0)
			do_pa(stack, 1);
	}
	else if (max == 2)
		sort_2_element(stack, 'a');
	else if (max == 3)
		sort_3_element(stack, 'a');
}

void	soft_sort(t_stack *stack, int i) {
	int m;
	int push;

	push = 0;
	if (stack->len_a > 3) {
		m = ft_median(stack->a, stack->len_a);
		while (--i >= 0) {
			if (stack->a[stack->len_a - 1] < m && ++push)
				do_pb(stack, 1);
			else if (stack->a[stack->len_a - 1] >= m)
				do_ra(stack, 1);
		}
	}
	if (stack->len_a == 2)
		sort_2_element(stack, 'a');
	if (stack->len_b == 2)
		sort_2_element(stack, 'b');
	if (stack->len_a == 3)
		sort_3_elemnt(stack, 'a');
	if (stack->len_b == 3)
		sort_3_elemnt(stack, 'b');
	while (push-- > 0)
		do_pa(stack, 1);
}