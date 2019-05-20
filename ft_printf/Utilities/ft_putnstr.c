/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:47:57 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 13:56:15 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnstr(const char *str, size_t n)
{
	size_t	len;

	if (str != NULL)
	{
		len = ft_strlen(str);
		if (len < n)
			write(1, str, len);
		else
			write(1, str, n);
	}
}
