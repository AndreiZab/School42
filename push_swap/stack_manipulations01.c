/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 13:16:52 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/31 17:20:29 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		*del_stack(t_stack *stack)
{
	//Сделать его войдовым? Или где-то будет stack = del_stack(stack)?
	free(stack->a);
	free(stack->b);
	free(stack);
	return (NULL);
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

int			validation_str(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
			if (str[i][j] > '9' || str[i][j++] < '0')
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

int			sorted(t_stack *stack)
{
	int		i;

	if (!stack || stack->len_b)
		return (0);
	i = 0;
	while (i++ < stack->len_a)
		if (stack->a[i - 1] >= stack->a[i])
			return (0);
	return (1);
}
