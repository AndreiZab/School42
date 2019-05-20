/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_len_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:25:07 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 16:26:07 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_u_len_base(unsigned long long int nb, char base)
{
	size_t len;

	len = 1;
	while (nb >= (unsigned long long)base)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}
