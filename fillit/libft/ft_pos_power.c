/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlyne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:29:19 by larlyne           #+#    #+#             */
/*   Updated: 2019/04/13 11:38:50 by larlyne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_pos_power(int nb, unsigned int power)
{
	long	numb;

	numb = 1;
	while (power-- > 0)
		numb *= nb;
	return (numb);
}
