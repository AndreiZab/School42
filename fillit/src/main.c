/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:25:28 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/23 18:52:36 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

<<<<<<< HEAD
=======
int		validation(char *str, ssize_t ret)
{
	if ((check_g(str) + check_l(str) + check_z(str) + check_t(str) +
				check_line_cube(str)) == ret)
		return (1);
	return (0);
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
			return (0);
		i++;
	}
	if ((i + 1) > 546)
		return (0);
	if (((hash % 4) == 0) && ((dot % 12) == 0) && (((i + 1) % 21) == 0))
		return (1);
	return (0);
}

>>>>>>> db9ff127e387dc3464814f782011612ff639eb11
int		message(int ret, char *str)
{
	ft_putstr(str);
	return (ret);
}

int		main(int argc, char **argv)
{
	int		fd;
	ssize_t	ret;
	char	buf[22];

	if (argc != 2)
		return (message(0, "usage: fillit source_file\n"));
	fd = open(argv[1], O_RDONLY);
	ret = ft_read(fd, buf);
	if (ret < 0)
	{
		return (message(1, "error\n"));
	}
	if (fd == -1 || !size_validation(buf) || !connect_validation(buf))
	{
		printf("%d", size_validation(buf));
		printf("%d", connect_validation(buf));
		return (message(1, "error\n"));
	}
	close(fd);
	return (0);
}
