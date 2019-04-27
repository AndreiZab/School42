/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbackground_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:53:18 by larlyne           #+#    #+#             */
/*   Updated: 2019/04/13 13:56:13 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_setforeground_fd(int foreg, int fd)
{
	if (foreg < 0 || foreg > 7)
		return ;
	ft_putstr_fd("\033[3", fd);
	ft_putchar_fd('0' + (char)foreg, fd);
	ft_putchar_fd('m', fd);
}
