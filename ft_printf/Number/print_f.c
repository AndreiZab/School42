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

long double	ft_va_arg(va_list *arg, t_printf p)
{
	long double nb;

	if (p.L == 1)
		nb = va_arg(*arg, long double);
	else
		nb = (long double)va_arg(*arg, double);
	return (nb);
}

int			ft_write_nan(t_printf p, char *s, char char_printed, long double nb)
{
	int len;

	len = (nb == -(1.0 / 0.0)) ? 4 : 3;
	char_printed += len;
	char_printed += print_width(p, char_printed);
	if (nb == -(1.0 / 0.0))
		ft_putchar('-');
	ft_putstr(s);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}

int			ft_nun_inf(t_printf p, char char_printed, long double nb)
{
	char *s;

	if (!(s = (char*)malloc(sizeof(char) * 4)))
		exit (1);
	if (p.conversion == 'F')
		s = p.inf ? "INF" : "NAN";
	else
		s = p.inf ? "inf" : "nan";
	char_printed += ft_write_nan(p, s, char_printed, nb);
	s = NULL;
	free (s);
	return (char_printed);
}

int			print_f(va_list *arg, int char_printed, t_printf p)
{
	char *integer;
	char *decimal;
	long double nb;

	nb = ft_va_arg(arg, p);
	p = flag_manager_f(nb, p);
	if (!p.inf && !p.nan)
	{
		nb = round_ld(nb, p);
		integer = integer_f(nb);
		decimal = decimal_f(nb, p.precision, integer);
//		integer = integer_f_s(nb, p);
	//	printf("%s", integer);
//		decimal = decimal_f_s(nb, p, integer);
//		printf(".%s", decimal);
		char_printed += write_f(p, integer, decimal, nb);
		integer = NULL;
		free(integer);
		decimal = NULL;
		free(decimal);
	}
	else
		char_printed += ft_nun_inf(p, char_printed, nb);
//	char_printed += f_to_s(nb, &str, p);
//	printf("%s", str);
//	ft_write(str, char_printed, p);
//	free(str);
		return (char_printed);
}

		/*static void	ft_put_f_real(long long nbr)
{
	char sign;

	sign = (nbr < 0) ? -1 : 1;
	if (nbr >= 10 || nbr <= -10)
		ft_put_f_real(nbr / 10);
	ft_putchar((nbr % 10) * sign + '0');
}

int			print_f_real(t_printf p, long long nb, long double nbr_save)
{
	int	nb_len;
	int char_printed;

	char_printed = 0;
	nb_len = ft_longlong_len(nbr_save);
	if (p.plus && nbr_save >= 0)
		char_printed++;
	char_printed += print_space(p, nb);
	char_printed += nb_len;
	if (nb < 0)
		ft_putchar('-');
	ft_put_f_real(nb);
	return(char_printed);
}

		start test
		long long t;
		nb = nb - (long long)nb;
		t = (p.precision == 0) ? -6 : 0;
		write(1, ".", 1);
		char_printed++;
		while (t < p.precision)
		{
			t++;
			nb = (nb > 0) ? nb : -nb;
			nb = nb * 10;
			if (nb < 1)
			{
				write(1, "0", 1);
				char_printed++;
			}
			else if (nb > 1)
			{
				char_printed += print_f_real(p, (long long) nb, nbr_save);
				nb = nb - (long long) nb;
			}
		}
		end test */