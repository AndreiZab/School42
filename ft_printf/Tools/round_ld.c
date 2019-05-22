/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 19:50:01 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/13 21:00:29 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long double	ft_pow(int pow)
{
	long double nb;

	nb = 1;
	while (pow > 0)
	{
		nb = nb * 10;
		pow--;
	}
	while (pow < 0)
	{
		nb = nb / 10;
		pow++;
	}
	return (nb);
}

int		len_f(long double nb)
{
	int len;

	len = 0;
	while (nb > 1)
	{
		len++;
		nb /= 10;
	}
	if (len == 0)
		return (1);
	return (len);
}

long double	ft_atof(char *s)
{
	long double nb;

	nb = 0;
	while (*s)
	{
		nb *= 10;
		nb += (long double)(*s - '0');
		++s;
	}
	return (nb);
}


int			ft_even(char *str)
{
	return ((str[ft_strlen(str) - 1] - '0') % 2);
}

long double	round_ld(long double nb, t_printf p)
{
	long double	temp;
	char		*integer_s;

	nb = nb < 0 ? -nb : nb;
	temp = nb * ft_pow(p.precision);
	integer_s = integer_f(temp);
	temp -= ft_atof(integer_s);
	free(integer_s);
	if (temp > 0.5 || (temp == 0.5 && ft_even(integer_s)))
		nb += 0.5 * ft_pow(-p.precision);
	return (nb);
}