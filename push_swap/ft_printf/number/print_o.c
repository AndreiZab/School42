/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:37:55 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 14:38:36 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_u_o_long(int char_printed, t_printf p, unsigned long long nb)
{
	int prec;
	int nb_len;

	prec = 0;
	nb_len = ft_u_len_base(nb, 8);
	if (!(p.precision == -1 && nb == 0))
		char_printed += nb_len;
	if (p.precision > 0)
		prec = p.precision - nb_len;
	if (p.hash == 1 && ((nb_len >= p.precision && nb != 0)
		|| (p.precision == -1 && nb == 0)))
		char_printed++;
	char_printed += print_width(p, char_printed + (prec > 0 ? prec : 0));
	if (p.hash == 1 && ((nb_len >= p.precision && nb != 0)
		|| (p.precision == -1 && nb == 0)))
		print_hash(p, nb);
	char_printed += print_precision(p, nb, nb_len);
	char_printed += print_zero_padding(p, char_printed);
	if (!(p.precision == -1 && nb == 0))
		ft_put_u_longlong_base(nb, 8);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}

int			print_o_unsigned(va_list *arg, int char_printed, t_printf p)
{
	unsigned long long	u_nb;

	u_nb = 0;
	if (p.l == 1 || p.conversion == 'O')
		u_nb = (unsigned long long)va_arg(*arg, unsigned long);
	else if (p.l == 2)
		u_nb = va_arg(*arg, unsigned long long);
	else if (p.h == 1)
		u_nb = (unsigned short)va_arg(*arg, unsigned int);
	else if (p.h == 2)
		u_nb = (unsigned char)va_arg(*arg, unsigned int);
	else if (p.j == 1)
		u_nb = (unsigned long long)va_arg(*arg, uintmax_t);
	else if (p.z == 1)
		u_nb = (unsigned long long)va_arg(*arg, size_t);
	char_printed += print_u_o_long(char_printed, p, u_nb);
	return (char_printed);
}

int			print_o_longlong(int char_printed, t_printf p, long long nb)
{
	int	prec;
	int	nb_len;

	prec = 0;
	nb_len = ft_len_base(nb, 8);
	if (p.precision != -1 || nb != 0 || p.hash)
		char_printed += nb_len;
	if (p.precision > 0)
		prec = p.precision - (nb < 0 ? nb_len - 1 : nb_len);
	if (p.hash && nb != 0 && nb_len >= p.precision)
	{
		if (p.zero == 0)
			p.precision -= 1;
		char_printed += 1;
	}
	char_printed += print_width(p, char_printed + (prec > 0 ? prec : 0));
	print_hash(p, nb);
	char_printed += print_precision(p, nb, nb_len);
	char_printed += print_zero_padding(p, char_printed);
	if (p.precision != -1 || nb != 0)
		ft_put_longlong_base(nb, 8);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}
