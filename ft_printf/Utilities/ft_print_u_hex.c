/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:56:18 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 16:57:07 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_u_hex(unsigned long long nb, const char *str)
{
	if (nb < 16)
		ft_putchar(str[nb]);
	else
	{
		ft_print_u_hex(nb / 16, str);
		ft_putchar(str[nb % 16]);
	}
}
