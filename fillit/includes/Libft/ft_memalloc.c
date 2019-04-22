/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:56:16 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/14 13:49:34 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (size + 1 == 0)
		return (NULL);
	if ((s = (void*)malloc(sizeof(void*) * size)) == NULL)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
