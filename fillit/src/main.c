/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:25:28 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/21 18:05:13 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validation(char *str, ssize_t ret)
{
	if ((check_g(str) + check_l(str) + check_z(str) + check_t(str) +
				check_line_cube(str)) == ret)
		return (1);
	return (0);
}

int		size_validation(char *str)
{
	int i;
	int hash;
	int dot;

	i = 0;
	hash = 0;
	dot = 0;
	while (str[i])
	{
		if (str[i] == '#')
			hash++;
		else if (str[i] == '.')
			dot++;
		else if (str[i] != '\n')
			return (0);
		i++;
	}
	if ((i + 1) > 546)
		return (0);
	if (((hash % 4) == 0) && ((dot % 12) == 0) && (((i + 1) % 21) == 0))
		return (1);
	return (0);
}

int		message(int ret, char *str)
{
	ft_putstr(str);
	return (ret);
}

int		main(int argc, char **argv)
{
	int		fd;
	ssize_t	ret;
	char	buf[BUFF_SIZE + 1];

	if (argc != 2)
		return (message(0, "usage: fillit source_file\n"));
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret < 1)
		return (error(1, "error\n"));
	buf[ret] = '\0';
	ret = (ret + 1) / 21;
	if (fd == -1 || !size_validation(buf) || !validation(buf, ret))
		return (message(1, "error\n"));
	close(fd);
	return (0);
}
