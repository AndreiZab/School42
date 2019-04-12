/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:42:06 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/09 19:08:29 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[j])
	{
		while ((haystack[i + j] == needle[i]) && needle[i])
			i++;
		if (!needle[i])
			return ((char *)&haystack[j]);
		i = 0;
		j++;
	}
	return (NULL);
}
