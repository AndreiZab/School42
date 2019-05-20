/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_longlong_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:27:06 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 16:27:44 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t		ft_u_longlong_len(unsigned long long nb)
{
	size_t		len;

	len = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
