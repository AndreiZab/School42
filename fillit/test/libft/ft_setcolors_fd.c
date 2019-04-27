/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcolor_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 09:23:57 by larlyne           #+#    #+#             */
/*   Updated: 2019/04/13 13:58:50 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_setcolors_fd(int foreg, int backg, int fd)
{
	if (foreg < 0 || foreg > 7 || backg < 0 || backg > 7)
		return ;
	ft_putstr_fd("\033[3", fd);
	ft_putchar_fd('0' + (char)foreg, fd);
	ft_putstr_fd(";4", fd);
	ft_putchar_fd('0' + (char)backg, fd);
	ft_putchar('m');
}
