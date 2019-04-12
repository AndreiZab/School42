/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:40:53 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/09 20:38:28 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*c;

	if (s == NULL || f == NULL)
		return (NULL);
	c = ft_strnew(ft_strlen(s));
	if (c == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		c[i] = (*f)(i, s[i]);
		i++;
	}
	return (c);
}
