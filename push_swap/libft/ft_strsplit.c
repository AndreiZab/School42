/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:33:01 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/07 19:56:45 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_split(char const *s, char **s2, char c, unsigned int i)
{
	size_t			len;
	unsigned int	j;

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
			if (s2[j - 1] == NULL)
			{
				ft_free_2d_array(s2);
				return (NULL);
			}
			i = i + len;
		}
	}
	s2[j] = 0;
	return (s2);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**s2;
	unsigned int	i;

	i = 0;
	if (!s || !c || !(s2 = ft_memalloc(ft_countwords(s, c) + 1)))
		return (NULL);
	ft_split(s, s2, c, i);
	return (s2);
}
