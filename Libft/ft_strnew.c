/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:31:34 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/08 13:26:52 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *s;
	char *p;

	s = (char *)malloc(sizeof(char) * size + 1);
	if (s == NULL)
		return (NULL);
	p = s;
	while (size)
	{
		*p++ = '\0';
		size--;
	}
	*p = '\0';
	return (s);
}
