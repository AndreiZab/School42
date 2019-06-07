/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:23:17 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/07 21:06:08 by rhealitt         ###   ########.fr       */
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

t_stack	*parse_integers(int len, char **str)
{
	t_stack	*tmp;
	int		i;

	if (!(validation_str(str, len)))
		return (0);
	if (len == 1)
		return (parse_one_str(str[0]));
	tmp = create_stack(len);
	i = -1;
	while (++i < len)
	{
		tmp->a[i] = ft_atoi(str[i]);
		if (tmp->a[i] == 0 && str[i][0] != '0')
			return (del_stack(tmp));
	}
	tmp->a = ft_reverce(tmp->a, tmp->len_a);
	return (tmp);
}
