/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:56:16 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/07 18:23:38 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*s;

	i = 0;
	if ((s = (void*)malloc(sizeof(void*) * size)) == NULL)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
