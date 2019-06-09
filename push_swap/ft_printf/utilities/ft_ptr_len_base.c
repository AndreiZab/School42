/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_len_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:55:02 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 16:55:06 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_ptr_len_base(size_t ptr, unsigned int base)
{
	size_t	len;

	len = 1;
	while (ptr >= base)
	{
		ptr /= base;
		len++;
	}
	return (len);
}
