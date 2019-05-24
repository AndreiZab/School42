/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:31:15 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/08 15:04:36 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	parse_format(va_list *arg, char *format)
{
	size_t char_printed;

	char_printed = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			char_printed += parse_percentage(arg, &format);
		else
		{
			ft_putchar(*format);
			char_printed++;
		}
		if (*format != '\0')
			format++;
	}
	return (char_printed);
}

int				ft_printf(const char *format, ...)
{
	va_list	arg;
	size_t	char_printed;

	va_start(arg, format);
	char_printed = parse_format(&arg, (char*)format);
	va_end(arg);
	return (char_printed);
}
