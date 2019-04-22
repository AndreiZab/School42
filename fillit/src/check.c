/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:59:16 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/21 18:03:23 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

ssize_t		check_line_cube(char *str)
{
	ssize_t i;
	ssize_t num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 5] == '#' && \
				str[i + 10] == '#' && str[i + 15] == '#')
			num++;
		if (str[i] == '#' && str[i + 1] == '#' && \
				str[i + 5] == '#' && str[i + 6] == '#')
			num++;
		if (str[i] == '#' && str[i + 1] == '#' && \
				str[i + 2] == '#' && str[i + 3] == '#')
			num++;
		i++;
	}
	return (num);
}

ssize_t		check_t(char *str)
{
	ssize_t i;
	ssize_t num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 1] == '#' && \
				str[i + 2] == '#' && str[i + 6] == '#')
			num++;
		if (str[i] == '#' && str[i + 5] == '#' && \
				str[i + 6] == '#' && str[i + 10] == '#')
			num++;
		if (str[i] == '#' && str[i + 4] == '#' && \
				str[i + 5] == '#' && str[i + 6] == '#')
			num++;
		if (str[i] == '#' && str[i + 4] == '#' && \
				str[i + 5] == '#' && str[i + 10] == '#')
			num++;
		i++;
	}
	return (num);
}

ssize_t		check_l(char *str)
{
	ssize_t i;
	ssize_t num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 5] == '#' && \
				str[i + 9] == '#' && str[i + 10] == '#')
			num++;
		if (str[i] == '#' && str[i + 1] == '#' && \
				str[i + 2] == '#' && str[i + 7] == '#')
			num++;
		if (str[i] == '#' && str[i + 1] == '#' && \
				str[i + 5] == '#' && str[i + 10] == '#')
			num++;
		if (str[i] == '#' && str[i + 5] == '#' && \
				str[i + 6] == '#' && str[i + 7] == '#')
			num++;
		i++;
	}
	return (num);
}

ssize_t		check_g(char *str)
{
	ssize_t i;
	ssize_t num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 5] == '#' && \
				str[i + 10] == '#' && str[i + 11] == '#')
			num++;
		if (str[i] == '#' && str[i + 3] == '#' && \
				str[i + 4] == '#' && str[i + 5] == '#')
			num++;
		if (str[i] == '#' && str[i + 1] == '#' && \
				str[i + 6] == '#' && str[i + 11] == '#')
			num++;
		if (str[i] == '#' && str[i + 1] == '#' && \
				str[i + 2] == '#' && str[i + 5] == '#')
			num++;
		i++;
	}
	return (num);
}

ssize_t		check_z(char *str)
{
	ssize_t i;
	ssize_t num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#' && str[i + 1] == '#' && \
				str[i + 6] == '#' && str[i + 7] == '#')
			num++;
		if (str[i] == '#' && str[i + 4] == '#' && \
				str[i + 5] == '#' && str[i + 9] == '#')
			num++;
		if (str[i] == '#' && str[i + 1] == '#' && \
				str[i + 4] == '#' && str[i + 5] == '#')
			num++;
		if (str[i] == '#' && str[i + 5] == '#' && \
				str[i + 6] == '#' && str[i + 11] == '#')
			num++;
		i++;
	}
	return (num);
}
