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
/*
int		ft_mod(long double nb, long double *mod)
{
	int len;

	*mod = 1;
	len = 1;
	while ((int)(nb /= 10) != 0)
	{
		*mod *= 10;
		len++;
	}
	if (nb < 0)
		len++;
	return (len);
}

char	*integer_f_s(long double nb, t_printf p)
{
	char *s;
	long double mod;
	int i;
	int len;

	len = ft_mod(nb, &mod);
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		exit(1);
	i = 0;
	if ((long long)nb == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	if (nb < 0)
	{
		s[i++] = '-';
		nb *= -1;
	}
	while (i < len)
	{
		s[i++] = (char)((nb / mod) + '0');
		nb -= (int)(nb / mod) * mod;
		mod /= 10;
	}
	s[i] = '\0';
	return (s);
}

char	*decimal_f_s(long double nb, t_printf p, char *integer)
{
	int		i;
	char	*s;
	long double f;

	nb = (nb < 0) ? -nb : nb;
	f = 0;
	if (integer[0] == '-')
		integer++;
	while (*integer != '\0')
	{
		f *= 10;
		f += (long double)(*integer - '0');
		integer++;
	}
	nb -= f;
	i = 0;
	if (!(s = (char*)malloc(sizeof(char) * (p.precision + 1))))
		exit(1);
	while (i < p.precision)
	{
		nb *= 10;
		if (nb > 0)
		{
			if ((int)nb != 9)
				s[i] = (int)(nb + 0.01) + '0';
			else if ((int)(nb + 0.01) == 10)
				s[i] = '0';
			else
				s[i] = (int)nb + '0';
		}
		else
			s[i] = '0';
		i++;
	//	s[i++] = (nb > 0) ? (int)nb + '0' : '0';
		nb -= (int)nb;
	}
	s[i] = '\0';
	return (s);
}
*/
void	print_f_longdouble(char *integer, char *decimal, long double nb)
{
	int i;

	i = 0;
	if (nb > 0 && integer[i] == '-')
		i++;
	while (integer[i])
		write(1, &integer[i++], 1);
	if (decimal[0] != '\0')
		write(1, ".", 1);
	i = 0;
	while (decimal[i])
		write(1, &decimal[i++], 1);
}

char		*integer_f(long double nb)
{
	char		*s;
	char		*ptr;
	int			len;
	int			i;
	long double	temp;

	len = len_f(nb);
	if (!(s = (char*)ft_memalloc(len + 1)))
		exit (1);
	ptr = s;
	while (len)
	{
		i = len - 1;
		temp = nb;
		while (i--)
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

char		*decimal_f(long double nb, int p, char *integer_f)
{
	char	*s;
	int		i;

	i = 0;
	nb = nb < 0 ? -nb : nb;
	nb -= ft_atof(integer_f);
	if (!(s = (char *)ft_memalloc(p + 1)))
		exit (1);
	while (i < p)
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

int 	write_f(t_printf p, char *integer, char *decimal, long double nb)
{
	int len;
	int char_printed;

	char_printed = 0;
	len = ft_strlen(integer) + ft_strlen(decimal) + 1;
	if (decimal[0] == '\0')
		len--;
	if ((p.plus || p.space) && nb >= 0)
		char_printed += 1;
	if (p.space && nb >= 0)
		ft_putchar(' ');
	char_printed += len;
	char_printed += print_width(p, char_printed);
	if (p.plus && nb >= 0)
		ft_putchar('+');
	if (nb < 0)
		ft_putchar('-');
	char_printed += print_zero_padding(p, char_printed);
	print_f_longdouble(integer, decimal, nb);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}

/*
#include <math.h>

void	ft_int(long double *nb, char **str, int *i, long double mod)
{
	char *s;
	long double test1;
	long double test2;
	long double test3;

	test2 = *nb;
	s = *str;
	if ((long long)*nb == 0)
	{
		s[(*i)] = '0';
		(*i)++;
		return ;
	}
	while ((long long)*nb != 0)
	{
		s[*i] = (char)((*nb / mod) + '0');
		(*i)++;
		test1 = *nb / mod;
		test1 = (int)test1;
		test1 = test1 * mod;
		*nb = *nb - test1;
		test3 = *nb;
//		*nb -= (int)(*nb / mod) * mod;
		mod /= 10;
	}
}

void	ft_dec(char **str, int *i, long double nb, t_printf p)
{
	int		j;
	int		tmp;
	char	*s;

	nb *= 10;
	j = 0;
	s = *str;
	s[(*i)++] = '.';
	while (j++ < p.precision)
	{
		if ((int)nb == 0)
		{
			s[(*i)++] = '0';
			continue ;
		}
		tmp = ((int)nb != 9) ? (int)(nb + 0.01) : (int)nb;
		s[(*i)++] = (char)(tmp + 48);
		nb = (nb - tmp) * 10;
	}
}

long double	ft_mod(long double nb, int *len)
{
	long double mod;

	mod = 1;
	while ((int)(nb /= 10) != 0)
	{
		(*len)++;
		mod *= 10;
	}
	return (mod);
}

int ft_inf(char **s)
{
	if (!(*s = malloc(sizeof(char) * 4)))
		return (0);
	*s = "inf";
	return (3);
}

int f_to_s(long double nb, char **str, t_printf p)
{
	int sign;
	int len;
	char *s;
	long double mod;
	int i;

	len = 1;
	sign = 0;
	i = 0;
	if (nb == INFINITY)
		return(ft_inf(str));
	if (nb < 0 && len++ && (sign = -1) == -1)
		nb = -nb;
	mod = ft_mod(nb, &len);
	len += p.precision;
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (sign == -1)
		s[i++] = '-';
	ft_int(&nb, &s, &i, mod);
	ft_dec(&s, &i, nb, p);
	s[--i] = '\0';
	*str = s;
	return (len);
} */