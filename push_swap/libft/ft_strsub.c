/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:31:32 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/08 16:43:45 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sn;
	size_t	i;

	if (s == NULL || start > ft_strlen(s))
		return (NULL);
	sn = (char *)malloc(sizeof(char) * len + 1);
	if (sn == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		sn[i++] = s[start++];
	sn[i] = '\0';
	return (sn);
}
