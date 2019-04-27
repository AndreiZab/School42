/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:53:06 by larlyne           #+#    #+#             */
/*   Updated: 2019/04/20 10:22:35 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (haystack[i])
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
