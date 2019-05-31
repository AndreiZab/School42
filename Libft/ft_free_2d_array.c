/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:33:18 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/13 19:17:43 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d_array(char **string)
{
	int i;

	if (string == NULL)
		return ;
	i = 0;
	while (string[i])
	{
		free(string[i]);
		string[i] = NULL;
		i++;
	}
	free(string);
	string = NULL;
}
