/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:38:33 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/08 17:45:36 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_x_longlong(int char_printed, t_printf p, unsigned long long nb)
{
	int	prec;

	prec = 0;
	char_printed += hash_length(p, nb);
	if (!(p.precision == -1 && nb == 0))
		char_printed += ft_hex_len(nb);
	if (p.precision > 0)
		prec = p.precision - ft_hex_len(nb);
	char_printed += print_width(p, char_printed + (prec > 0 ? prec : 0));
	print_hash(p, nb);
	char_printed += print_precision(p, nb, ft_hex_len(nb));
	char_printed += print_zero_padding(p, char_printed);
	if (!(p.precision == -1 && nb == 0))
	{
		if (p.conversion == 'x')
			ft_print_u_hex(nb, "0123456789abcdef");
		else if (p.conversion == 'X')
			ft_print_u_hex(nb, "0123456789ABCDEF");
	}
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}
