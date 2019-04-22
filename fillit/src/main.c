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
		else if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		i++;
	}
	if ((i + 1) > 546)
		return (0);
	if (((hash % 4) == 0) && ((dot % 12) == 0) && (((i + 1) % 21) == 0))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	ssize_t	ret;
	char	buf[BUFF_SIZE + 1];

	if (argc != 2)
	{
		write(1, "usage: fillit source_file\n", 26);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	ret = (ret + 1) / 21;
	if (fd == -1 || ret < 1 || !size_validation(buf) || !validation(buf, ret))
	{
		printf("\nresult validation: %d\n", validation(buf, ret));
		write(1, "error\n", 6);
		return (0);
	}
//	fillit(fd, buf);
	close(fd);
	printf("VALID Eсли Тетри разделены несколькими ньюлайнами - валид?");
	return (0);
}