/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:31:59 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/10 14:54:00 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int old_n)
{
	char	*str;
	int		size;
	int		n;

	if (old_n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = (old_n < 0) ? 2 : 1;
	n = old_n;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		size++;
	}
	n = (old_n < 0) ? -old_n : old_n;
	if ((str = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[--size] = (n % 10) + '0';
		n = n / 10;
	}
	if (old_n < 0)
		str[0] = '-';
	return (str);
}
