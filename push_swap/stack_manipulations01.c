/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:16:52 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/09 18:51:27 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			del_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
	return (0);
}

t_stack		*create_stack(int len)
{
	t_stack *temp;

	if (!(temp = (t_stack *)malloc(sizeof(t_stack))))
		exit(1);
	temp->a = (int *)malloc(sizeof(int) * len);
	temp->b = (int *)malloc(sizeof(int) * len);
	if (!temp->a || !temp->b)
		exit(1);
	temp->len_a = len;
	temp->len_b = 0;
	return (temp);
}

int			validation_str(char **str, int len)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		while (str[i][j])
		{
			if (str[i][j] == ' ' && len == 1)
				j++;
			else if ((str[i][j] == '-' || str[i][j] == '+') &&
				str[i][j + 1] <= '9' && str[i][j + 1] >= '0')
			{
				if ((j > 1 && str[i][j - 1] == ' ') || j == 0)
					j++;
				else
					return (0);
			}
			else if (str[i][j] > '9' || str[i][j++] < '0')
				return (0);
		}
		j = 0;
	}
	return (1);
}

int			sorted(t_stack *stack)
{
	int		i;

	if (!stack || stack->len_b)
		return (0);
	i = 0;
	while (++i < stack->len_a)
		if (stack->a[i - 1] < stack->a[i])
			return (0);
	return (1);
}

t_stack		*parse_one_str(char *str, int v)
{
	t_stack	*stack;
	char	**temp;
	int		i;

	if (!(temp = ft_strsplit(str, ' ')))
		return (0);
	i = 0;
	while (temp[i])
		i++;
	stack = create_stack(i);
	if (v == 1)
		stack->v = 1;
	i = -1;
	while (temp[++i])
	{
		stack->a[i] = ft_atoi(temp[i]);
		if (stack->a[i] == 0 && temp[i][0] != '0' && !del_stack(stack)
			&& !ft_free_2d_array(temp))
			return (0);
	}
	stack->a = ft_reverce(stack->a, stack->len_a);
	ft_free_2d_array(temp);
	return (stack);
}
