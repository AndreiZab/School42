/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 12:21:10 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/21 14:06:58 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_check(char **save, char **line)
{
	char	*tmp;
	char	*maybe_n;
	int		i;

	i = 0;
	maybe_n = *save;
	while (maybe_n[i] != '\n')
		if (!maybe_n[i++])
			return (0);
	tmp = &maybe_n[i];
	*tmp = '\0';
	*line = ft_strdup(*save);
	*save = ft_strdup(tmp + 1);
	free(maybe_n);
	return (1);
}

static int		ft_read(int fd, char *temp, char **save, char **line)
{
	ssize_t	result_read;
	char	*temp_2;

	while ((result_read = read(fd, temp, BUFF_SIZE)) > 0)
	{
		temp[result_read] = '\0';
		if (*save)
		{
			temp_2 = *save;
			*save = ft_strjoin(temp_2, temp);
			free(temp_2);
			temp_2 = NULL;
		}
		else
			*save = ft_strdup(temp);
		if (ft_check(save, line) != 0)
			break ;
	}
	if (result_read > 0)
		return (1);
	return (result_read);
}

int				get_next_line(const int fd, char **line)
{
	ssize_t		result;
	char		*temp;
	static char *save[1024];

	if (!line || fd < 0 || (read(fd, save[0], 0) < 0) ||
			((temp = ft_memalloc(BUFF_SIZE + 1)) == NULL))
		return (-1);
	if (save[fd])
		if (ft_check(&save[fd], line) == 1)
			return (1);
	result = ft_read(fd, temp, &save[fd], line);
	free(temp);
	if (result != 0 || save[fd] == NULL || save[fd][0] == '\0')
	{
		if (!result && *line)
			*line = NULL;
		return (result);
	}
	*line = save[fd];
	save[fd] = NULL;
	return (1);
}
