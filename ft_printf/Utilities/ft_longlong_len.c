/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlong_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:31:29 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 16:40:09 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t		ft_longlong_len(long long nbr)
{
	size_t		len;

	len = 1;
	if (nbr < 0)
		len += 1;
	while (nbr > 9 || nbr < -9)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
