/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:18:48 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 12:55:37 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_atoi(const char *str)
{
	char	sign;
	int		i;
	long	numb;
	char	was_sign;

	i = 0;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		++i;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		++i;
	was_sign = sign;
	numb = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		numb = numb * 10 + (str[i++] - '0');
		if (numb < 0 && was_sign == 1)
			return (-1);
		else if (numb < 0 && was_sign == -1)
			return (0);
	}
	return ((int)numb * sign);
}
