/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:34:45 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/08 17:24:00 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_width(t_printf p, int written)
{
	int	spaces_printed;
	int	i;

	spaces_printed = 0;
	i = p.min_width - written;
	if (p.min_width > 0 && p.min_width > written && !p.minus)
	{
		while (i-- > 0)
		{
			if (ft_strchr("cDOUCsSp", p.conversion)
			&& (p.zero && (p.minus || p.precision)))
			{
				ft_putchar('0');
				spaces_printed++;
			}
			else if (!p.zero || (ft_strchr("diuoxX", p.conversion)
			&& p.precision && p.zero))
			{
				ft_putchar(' ');
				spaces_printed++;
			}
		}
	}
	return (spaces_printed);
}

int	print_zero_padding(t_printf p, int char_printed)
{
	int	zero_printed;
	int	i;

	zero_printed = 0;
	i = 0;
	if (p.zero == 1 && (p.min_width > char_printed))
	{
		i = p.min_width - char_printed;
		while (i > 0)
		{
			ft_putchar('0');
			zero_printed++;
			i--;
		}
	}
	return (zero_printed);
}

int	print_width_minus(t_printf p, int char_printed)
{
	int	spaces_printed;
	int	i;
	int	width;

	spaces_printed = 0;
	width = p.min_width;
	i = 0;
	if (width > 0 && width > char_printed && !p.zero && p.minus)
	{
		i = width - char_printed;
		while (i > 0)
		{
			ft_putchar(' ');
			spaces_printed++;
			i--;
		}
	}
	return (spaces_printed);
}

int	print_precision(t_printf p, long long nb, int nb_len)
{
	int	zero_printed;
	int	i;

	zero_printed = 0;
	i = 0;
	if (nb < 0)
		nb_len -= 1;
	if (p.precision != -1 && p.precision > nb_len)
	{
		i = (p.precision - nb_len);
		while (i > 0)
		{
			ft_putchar('0');
			zero_printed++;
			i--;
		}
	}
	return (zero_printed);
}
