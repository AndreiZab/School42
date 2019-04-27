/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 09:45:34 by larlyne           #+#    #+#             */
/*   Updated: 2019/04/09 08:37:25 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*char_s1;
	unsigned char	*char_s2;
	unsigned char	*s1_end;

	char_s1 = (unsigned char*)s1;
	s1_end = char_s1 + n;
	char_s2 = (unsigned char*)s2;
	while (char_s1 != s1_end)
	{
		if (*char_s1 != *char_s2)
			return (*char_s1 - *char_s2);
		++char_s1;
		++char_s2;
	}
	return (0);
}
