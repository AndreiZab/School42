/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:31:35 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/08 18:30:53 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	zero_flag(char *str, int minus)
{
	int		i;
	char	*before;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0' && !minus)
		{
			before = ft_strndup(str, i);
			if (ft_str_multi_chr(before, "123456789") == NULL &&
				!ft_strchr(before, '.'))
			{
				free(before);
				return (1);
			}
			else
			{
				free(before);
				return (0);
			}
		}
		i++;
	}
	return (0);
}

int	plus_flag(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

int	minus_flag(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	hash_flag(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

int	space_flag(char *str, int plus)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && !plus)
			return (1);
		i++;
	}
	return (0);
}
