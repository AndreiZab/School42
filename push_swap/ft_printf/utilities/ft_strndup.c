/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:50:10 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 12:51:28 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dest;

	dest = ft_strnew(n);
	if (dest)
	{
		dest = ft_strncpy(dest, str, n);
		return (dest);
	}
	else
		return (NULL);
}
