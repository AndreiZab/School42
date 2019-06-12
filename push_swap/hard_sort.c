/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 12:11:25 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/12 14:21:50 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		split_a(t_stack *stack)
{
	int m;
	int i;
	int push;
	int j;

	m = ft_median(stack->a, stack->len_a);
	i = stack->len_a;
	j = i;
	push = 0;
	while (--i >= 0)
	{
		if (stack->a[stack->len_a - 1] < m && ++push)
			do_pb(stack, 1);
		else if (stack->a[stack->len_a - 1] >= m)
			do_ra(stack, 1);
		if (j % 2 == 0 && push >= (j / 2))
			break ;
	}
	return (push);
}

int		split_b(t_stack *stack)
{
	int m;
	int i;
	int push;
	int j;

	m = ft_median(stack->b, stack->len_b);
	i = stack->len_b;
	j = i;
	push = 0;
	while (--i >= 0)
	{
		if (stack->b[stack->len_b - 1] >= m && ++push)
			do_pa(stack, 1);
		else if (stack->b[stack->len_b - 1] < m)
			do_rb(stack, 1);
		if (j % 2 == 0 && push >= (j / 2))
			break ;
	}
	return (push);
}

void	over_sort(t_stack *stack, int max)
{
	int push_in_a;
	int	*tmp_a;
	int	tmp_len;


	if (max > 3)
	{
		push_in_a = split_b(stack);
		over_sort(stack, stack->len_b);
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


void	hard_sort(t_stack *stack, int max)
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
		over_sort(stack, push_in_b);
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

void	soft_sort(t_stack *stack)
{
	int push;

	push = 0;
	if (stack->len_a > 3)
		push = split_a(stack);
	if (stack->len_a == 3)
		sort_3_element(stack, 'a');
	if (stack->len_b == 3)
		sort_3_element(stack, 'b');
	if (stack->len_a == 2)
		sort_2_element(stack, 'a');
	if (stack->len_b == 2)
		sort_2_element(stack, 'b');
	while (push-- > 0)
		do_pa(stack, 1);
}
