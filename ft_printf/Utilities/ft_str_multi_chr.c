/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_multi_chr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:28:18 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/08 18:38:17 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_str_multi_chr(char *str, char *c)
{
	int	i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (c[j])
		{
			if (str[i] == c[j])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
