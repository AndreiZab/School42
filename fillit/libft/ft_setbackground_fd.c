/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbackground_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:53:18 by larlyne           #+#    #+#             */
/*   Updated: 2019/04/13 13:55:16 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_setbackground_fd(int backg, int fd)
{
	if (backg < 0 || backg > 7)
		return ;
	ft_putstr_fd("\033[4", fd);
	ft_putchar_fd('0' + (char)backg, fd);
	ft_putchar_fd('m', fd);
}
