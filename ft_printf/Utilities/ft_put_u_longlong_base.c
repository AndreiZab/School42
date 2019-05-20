/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_longlong_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:53:30 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 16:53:52 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_put_u_longlong_base(unsigned long long nb, char base)
{
	if (base > 1 && base <= 10)
	{
		if (nb < (unsigned long long)base)
			ft_putchar('0' + nb);
		else
		{
			ft_put_u_longlong_base(nb / base, base);
			ft_putchar('0' + nb % base);
		}
	}
	else if (base == 1)
		ft_putnchar('1', nb);
}
