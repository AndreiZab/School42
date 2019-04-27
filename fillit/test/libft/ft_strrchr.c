/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:37:40 by larlyne           #+#    #+#             */
/*   Updated: 2019/04/09 10:52:17 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	char_c;
	char	*find_ptr;

	find_ptr = NULL;
	char_c = (char)c;
	while (*s)
	{
		if (*s == char_c)
			find_ptr = (char*)s;
		++s;
	}
	if (c == '\0')
		return ((char*)s);
	return (find_ptr);
}
