/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:46:59 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 16:52:52 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

int	ft_hex_len(unsigned long long nb)
{
	int char_printed;

	char_printed = 0;
	if (nb < 16)
		char_printed = 1;
	else
		char_printed = ft_u_len_base(nb, 16);
	return (char_printed);
}
