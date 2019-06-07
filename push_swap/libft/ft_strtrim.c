/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:06:25 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/10 13:40:46 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*c;
	size_t	i;
	size_t	len;
	size_t	j;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	while (s[len - 1] == '\n' || s[len - 1] == '\t' || s[len - 1] == ' ')
		len--;
	j = (len < i) ? 1 : len - i + 1;
	c = (char*)malloc(sizeof(char) * j);
	if (c == NULL)
		return (NULL);
	j = 0;
	while (i < len)
		c[j++] = s[i++];
	c[j] = '\0';
	return (c);
}
