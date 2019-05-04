/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:15:58 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/12 10:38:40 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	long	num;
	char	sign;

	i = 0;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		++i;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		++i;
	num = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - '0');
		if (num < 0 && sign == 1)
			return (-1);
		else if (num < 0 && sign == -1)
			return (0);
	}
	return ((int)num * sign);
}
