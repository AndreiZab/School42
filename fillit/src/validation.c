/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:01:27 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/23 18:52:38 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		connect_validation(char *str)
{
	int hash;
	int i;

	hash = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				hash++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				hash++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				hash++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				hash++;
		}
		i++;
	}
	return (hash == 6 || hash == 8);
}

int		ft_read(int fd, char *buf)
{
	ssize_t		i;
	
	while ((i = read(fd, buf, 21)) >= 20)
	{
		buf[i] = '\0';
		if (!connect_validation(buf) || !size_validation(buf))
			return (-1);
		//test
		show_termino(parse_termino(buf));
	}
	return (i);
}

int		size_validation(char *s)
{
	int i;
	int hash;
	int dot;

	i = 0;
	hash = 0;
	dot = 0;
	while (s[i])
	{
		if (s[i] == '#')
			hash++;
		else if (s[i] == '.')
			dot++;
		else if (s[i] != '\n')
		{
			return (0);
		}
		if ((i + 1) % 5 == 0 && i != 0)
			if (s[i] != '\n')
				return(0);
		i++;
	}
	if (hash == 4 && dot == 12 && (i == 21 || i == 20))
		return (1);
	return (0);
}