/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:53:06 by larlyne           #+#    #+#             */
/*   Updated: 2019/04/09 11:09:59 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		if (needle[j] == '\0')
			return ((char*)haystack + i - j);
		if (haystack[i] == needle[j])
			++j;
		else
		{
			i -= j;
			j = 0;
		}
		++i;
	}
	if (needle[j] == '\0')
		return ((char*)haystack + i - j);
	return (NULL);
}
