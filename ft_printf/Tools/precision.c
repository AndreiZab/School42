/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:34:31 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 14:34:34 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	precision(char *str)
{
	int		i;
	int		j;
	char	tmp[ft_strlen(str)];

	i = 0;
	j = 0;
	ft_memset(tmp, '\0', ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			ft_memset(tmp, '\0', ft_strlen(str));
			j = 0;
			i++;
			while (ft_strchr("0123456789", str[i]) && str[i] != '\0')
				tmp[j++] = str[i++];
		}
		else
			i++;
	}
	if (ft_strchr(str, '.') && (ft_strcmp(tmp, "0") == 0 || tmp[0] == '\0'))
		return (-1);
	return (ft_atoi(tmp));
}
