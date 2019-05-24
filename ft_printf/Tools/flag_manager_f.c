/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:31:35 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/08 18:30:53 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdint.h>

static int			is_nan(long double nb)
{
	return (!(nb == nb));
}

static int			is_inf(long double nb)
{
	if (nb == (1.0 / 0.0) || nb == -(1.0 / 0.0))
		return (1);
	else
		return (0);
}

static void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (s1);
}

t_printf		flag_manager_f(long double nb, t_printf p)
{
	unsigned __int128 sign;

	ft_memcpy(&sign, &nb, 8);
	sign = sign & ((unsigned __int128)1 << 79);
	if (sign)
		p.plus = -1;
	p.inf = 0;
	p.nan = 0;
	if (!p.precision)
		p.precision = 6;
	if (is_nan(nb) || is_inf(nb))
	{
		p.precision = -1;
		p.hash = 0;
		p.zero = 0;
		if (is_inf(nb))
			p.inf = 1;
		if (is_nan(nb))
		{
			p.plus = 0;
			p.nan = 1;
		}
	}
	if (p.plus)
		p.space = 0;
	return (p);
}
