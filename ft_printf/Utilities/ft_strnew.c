/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:31:34 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 12:55:37 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strnew(size_t size)
{
	char *s;
	char *p;

	if (size + 1 == 0)
		return (NULL);
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
