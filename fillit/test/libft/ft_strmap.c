/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:23:24 by larlyne           #+#    #+#             */
/*   Updated: 2019/04/20 10:21:49 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*map;

	if (s == NULL || f == NULL || (len = ft_strlen(s)) == 0 || len + 1 == 0)
		return (NULL);
	if ((map = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	map += len;
	s += len;
	*map = '\0';
	while (len--)
		*(--map) = f(*(--s));
	return (map);
}
