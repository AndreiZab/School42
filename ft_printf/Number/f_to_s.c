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

static void		print_f_longdouble(char *integer, char *decimal, t_printf p)
{
	int i;

	i = 0;
	while (integer[i])
		write(1, &integer[i++], 1);
	if (decimal[0] != '\0' || p.hash)
		write(1, ".", 1);
	i = 0;
	while (decimal[i])
		write(1, &decimal[i++], 1);
}

char			*integer_f(long double nb)
{
	char		*s;
	char		*ptr;
	int			len;
	int			i;
	long double	temp;

	len = len_f(nb);
	if (!(s = (char*)ft_memalloc(len + 1)))
		exit(1);
	ptr = s;
	while (len > 0)
	{
		i = len - 1;
		temp = nb;
		while (i-- > 0)
			temp /= 10;
		*ptr++ = (int)temp + '0';
		temp = (int)temp;
		while (++i < len - 1)
			temp *= 10;
		nb -= temp;
		--len;
	}
	return (s);
}

char			*decimal_f(long double nb, t_printf p, char *integer_f)
{
	char	*s;
	int		i;

	i = 0;
	nb = nb < 0 ? -nb : nb;
	nb -= ft_atof(integer_f);
	if (!(s = (char *)ft_memalloc(p.precision + 1)))
		exit(1);
	while (i < p.precision)
	{
		nb *= 10;
		if (nb > 0)
			s[i] = (int)nb + '0';
		else
			s[i] = '0';
		i++;
		nb -= (int)nb;
	}
	return (s);
}

int				write_f(t_printf p, char *integer, char *decimal, long double nb)
{
	int len;
	int char_printed;

	char_printed = 0;
	len = ft_strlen(integer) + ft_strlen(decimal) + 1;
	if (decimal[0] == '\0' && !p.hash)
		len--;
	if ((p.plus || p.space) && nb >= 0)
		char_printed += 1;
	if (p.space && nb >= 0)
		ft_putchar(' ');
	char_printed += len;
	char_printed += print_width(p, char_printed);
	if (p.plus > 0)
		ft_putchar('+');
	if (p.plus < 0)
		ft_putchar('-');
	char_printed += print_zero_padding(p, char_printed);
	print_f_longdouble(integer, decimal, p);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}
