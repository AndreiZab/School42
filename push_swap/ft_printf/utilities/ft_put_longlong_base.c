/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_longlong_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:49:27 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 16:50:28 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_longlong_base(long long nbr, char base)
{
	unsigned long long nb;

	if (base > 1 && base <= 10)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			if (nbr != LONG_LONG_MIN)
				nbr *= -1;
		}
		nb = nbr;
		if (nb >= (unsigned long long)base)
			ft_put_longlong_base(nb / base, base);
		ft_putchar(nb % base + '0');
	}
	else if (base == 1)
		ft_putnchar('1', nbr);
}
