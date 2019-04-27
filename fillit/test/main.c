/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:25:28 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/27 17:51:45 by rhealitt         ###   ########.fr       */
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
	int			fd;
	ssize_t		ret;
	t_termino	**terms;
	int			count;

	count = 0;
	if (argc != 2)
		return (message(0, "usage: fillit source_file\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (message(1, "error\n"));
	if ((terms = (t_termino**)malloc(sizeof(t_termino*) * 26)) == NULL)
		exit();
	ret = ft_read(fd, &terms, &count);
	if (ret < 0 || (ret < 20 && ret > 0))
	{
		terms_del(&terms, count);
		return (message(1, "error\n"));
	}
	solver(terms, count);
	terms_del(&terms, count);
	close(fd);
	return (0);
}
