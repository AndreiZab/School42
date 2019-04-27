/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:01:27 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/27 16:57:08 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read(int fd, t_termino ***terms, int *count)
{
	int			i;
	char		buf[22];
	t_termino	*curr;

	ft_memset(buf, 0, 22);
	while ((i = read(fd, buf, 21)) >= 20)
	{
		buf[i] = '\0';
		if (*count >= 26 || !validation(buf))
			return (-1);
		if ((curr = parse_termino(buf)) == NULL)
			return (-1);
		curr->symbol = 'A' + (*count);
		(*terms)[(*count)++] = curr;
	}
	if (buf[20] == '\n' || !buf[0])
		return (-1);
	return (i);
}

int		validation(char *s)
{
	int		j;
	int		side;
	int		hash;

	j = -1;
	hash = 0;
	side = 0;
	while (s[++j])
		if (s[j] == '#' && (j + 1) % 5 != 0)
		{
			if ((j + 1) < 20 && s[j + 1] == '#')
				side++;
			if ((j - 1) >= 0 && s[j - 1] == '#')
				side++;
			if ((j + 5) < 20 && s[j + 5] == '#')
				side++;
			if ((j - 5) >= 0 && s[j - 5] == '#')
				side++;
			hash++;
		}
		else if (((j + 1) % 5 == 0 && j != 0 && s[j] != '\n') ||
				(s[j] != '.' && (j + 1) % 5 != 0 && j != 20))
			return (0);
	return (hash == 4 && (j == 21 || j == 20) && (side == 6 || side == 8));
}
