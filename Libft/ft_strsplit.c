/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:33:01 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/12 15:25:57 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char			**s2;
	unsigned int	i;
	int				j;
	size_t			len;

	if (!s || !c || !(s2 = ft_memalloc(ft_countwords(s, c) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] && (s[i + len] != c))
				len++;
			s2[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	s2[j] = 0;
	return (s2);
}
