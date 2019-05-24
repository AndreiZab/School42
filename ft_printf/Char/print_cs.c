/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:36:16 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/24 20:08:06 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_str_null(int char_printed, t_printf p)
{
	int prec;

	prec = p.precision;
	char_printed += 6;
	char_printed += print_width(p, char_printed);
	char_printed += print_zero_padding(p, char_printed);
	if (prec > 0)
		ft_putnstr("(null)", prec);
	else if (prec != -1)
		ft_putstr("(null)");
	return (char_printed);
}

static int	print_string(int char_printed, t_printf p, char *str)
{
	int	prec;

	prec = p.precision;
	if (str || prec != 0)
	{
		if (!str)
			if ((str = (char*)malloc(sizeof(char) * 7)))
				str = "(null)";
		if (prec == 0 && ft_strlen(str) > 0)
			char_printed += (int)ft_strlen(str);
		else if (str && prec > 0 && prec < (int)ft_strlen(str))
			char_printed += prec;
		else if (str && prec > 0)
			char_printed += (int)ft_strlen(str);
		char_printed += print_width(p, char_printed);
		char_printed += print_zero_padding(p, char_printed);
		if (prec > 0)
			ft_putnstr(str, prec);
		else if (prec != -1)
			ft_putstr(str);
	}
	else
		char_printed += print_str_null(char_printed, p);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}

static int	print_char(int char_printed, t_printf p, char c)
{
	char_printed += 1;
	char_printed += print_width(p, char_printed);
	char_printed += print_zero_padding(p, char_printed);
	ft_putchar(c);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}

int			print_simple_char(int char_printed, t_printf p)
{
	char_printed += 1;
	char_printed += print_width(p, char_printed);
	char_printed += print_zero_padding(p, char_printed);
	ft_putchar(p.conversion);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}

int			print_sc(va_list *arg, t_printf p)
{
	int		char_printed;
	char	c;
	char	*str;

	char_printed = 0;
	if (p.conversion == 'c')
	{
		c = (char)va_arg(*arg, int);
		char_printed += print_char(char_printed, p, c);
	}
	else if (p.conversion == 's')
	{
		str = (char *)va_arg(*arg, char *);
		char_printed += print_string(char_printed, p, str);
	}
	return (char_printed);
}
