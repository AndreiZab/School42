/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:39:15 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 16:07:27 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_space(t_printf p, long long nb)
{
	if (p.space && ft_strchr("diD", p.conversion))
	{
		if (nb >= 0)
		{
			ft_putchar(' ');
			return (1);
		}
	}
	return (0);
}

int	print_hash(t_printf p, long long nb)
{
	char	c;

	c = p.conversion;
	if (p.hash && ft_strchr("oO", c) && nb != 0 && ft_u_len_base(nb, 8) > p.precision)
	{
		ft_putchar('0');
		return (1);
	}
	if (p.hash && ft_strchr("oO", c) && p.precision == -1 && nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else if (p.hash && c == 'x' && nb != 0)
	{
		ft_putstr("0x");
		return (2);
	}
	else if (p.hash && c == 'X' && nb != 0)
	{
		ft_putstr("0X");
		return (2);
	}
	return (0);
}

int	hash_length(t_printf p, long long nb)
{
	if (p.hash && ft_strchr("oO", p.conversion) && nb != 0)
		return (1);
	else if (p.hash && p.conversion == 'x' && nb != 0)
		return (2);
	else if (p.hash && p.conversion == 'X' && nb != 0)
		return (2);
	return (0);
}

int	print_plus(t_printf p,long long nb)
{
	if (p.plus && nb >= 0 && !ft_strchr("uU", p.conversion))
	{
		ft_putchar('+');
		return (1);
	}
	return (0);
}
