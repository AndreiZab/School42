/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:32:29 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/13 14:40:14 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*p2;

	if (dst == NULL && src == NULL)
		return (NULL);
	p = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	i = 0;
	if (p2 < p)
		while (++i <= len)
			p[len - i] = p2[len - i];
	else
		while (len-- > 0)
			*(p++) = *(p2++);
	return (dst);
}
