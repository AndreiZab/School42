/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:41:35 by larlyne           #+#    #+#             */
/*   Updated: 2019/04/21 11:12:03 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char		ft_is_trim_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	char	*start;
	char	*end;

	if (s == NULL)
		return (NULL);
	start = (char*)s;
	end = (char*)s + ft_strlen(s) - 1;
	while (ft_is_trim_space(*start))
		++start;
	while (end >= s && ft_is_trim_space(*end))
		--end;
	if (end < start)
		return (ft_strnew(1));
	str = ft_strsub(s, start - s, end - start + 1);
	return (str);
}
