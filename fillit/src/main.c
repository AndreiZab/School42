/* ************************************************************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:25:28 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/23 19:25:54 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
 	if (fd == -1)
		return (message(1, "error\n"));
	ret = ft_read(fd, buf);
	if (ret < 0)
		return (message(1, "error\n"));
	close(fd);
	return (0);
}
