/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:51:27 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/25 16:52:42 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char		*temp;
	size_t		i;

	i = 0;
	while (string[i])
		i++;
	if (!(temp = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (string[++i])
		temp[i] = string[i];
	temp[i] = '\0';
	return (temp);
}
