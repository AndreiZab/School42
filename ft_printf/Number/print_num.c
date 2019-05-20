/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:37:40 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/12 11:04:53 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_d(va_list *arg, int char_printed, t_printf p)
{
	char		c;
	long long	nb;

	c = p.conversion;
	if (c == 'd' || c == 'i' || c == 'D')
	{
		if (p.l == 1 || c == 'D')
			nb = (long long)va_arg(*arg, long);
		else if (p.l == 2)
			nb = va_arg(*arg, long long);
		else if (p.j == 1)
			nb = (long long)va_arg(*arg, intmax_t);
		else if (p.z == 1)
			nb = (long long)va_arg(*arg, size_t);
		else if (p.h == 1)
			nb = (short)va_arg(*arg, int);
		else if (p.h == 2)
			nb = (char)va_arg(*arg, int);
		else
			nb = (long long)va_arg(*arg, int);
		char_printed += print_d_longlong(char_printed, p, nb);
	}
	return (char_printed);
}

int	print_o(va_list *arg, int char_printed, t_printf p)
{
	long long			nb;

	if (p.l || p.h || p.j || p.z || p.conversion == 'O')
		char_printed += print_o_unsigned(arg, char_printed, p);
	else
	{
		nb = (long long)va_arg(*arg, unsigned int);
		char_printed += print_o_longlong(char_printed, p, nb);
	}
	return (char_printed);
}

int	print_u(va_list *arg, int char_printed, t_printf p)
{
	char				c;
	unsigned long long	nb;

	c = p.conversion;
	if (c == 'u' || c == 'U')
	{
		if (p.l == 1 || c == 'U')
			nb = (unsigned long long)va_arg(*arg, unsigned long);
		else if (p.l == 2)
			nb = va_arg(*arg, unsigned long long);
		else if (p.h == 1)
			nb = (unsigned short)va_arg(*arg, unsigned int);
		else if (p.h == 2)
			nb = (unsigned char)va_arg(*arg, unsigned int);
		else if (p.j == 1)
			nb = (unsigned long long)va_arg(*arg, uintmax_t);
		else if (p.z == 1)
			nb = (unsigned long long)va_arg(*arg, size_t);
		else
			nb = (unsigned long long)va_arg(*arg, unsigned int);
		char_printed += print_u_longlong(char_printed, p, nb);
	}
	return (char_printed);
}

int	print_x(va_list *arg, int char_printed, t_printf p)
{
	unsigned long long	nb;

	if (p.l == 1)
		nb = (unsigned long long)va_arg(*arg, unsigned long);
	else if (p.l == 2)
		nb = va_arg(*arg, unsigned long long);
	else if (p.h == 1)
		nb = (unsigned short)va_arg(*arg, unsigned int);
	else if (p.h == 2)
		nb = (unsigned char)va_arg(*arg, unsigned int);
	else if (p.j == 1)
		nb = (unsigned long long)va_arg(*arg, uintmax_t);
	else if (p.z == 1)
		nb = (unsigned long long)va_arg(*arg, size_t);
	else
		nb = (unsigned long long)va_arg(*arg, unsigned int);
	char_printed += print_x_longlong(char_printed, p, nb);
	return (char_printed);
}

int	print_num(va_list *arg, t_printf p)
{
	int				char_printed;
	char			c;

	char_printed = 0;
	c = p.conversion;
	if (c == 'd' || c == 'i' || c == 'D')
		char_printed += print_d(arg, char_printed, p);
	else if (c == 'u' || c == 'U')
		char_printed += print_u(arg, char_printed, p);
	else if (c == 'o' || c == 'O')
		char_printed += print_o(arg, char_printed, p);
	else if (c == 'x' || c == 'X')
		char_printed += print_x(arg, char_printed, p);
	else if (c == 'f' || c == 'F')
		char_printed += print_f(arg, char_printed, p);
	return (char_printed);
}
