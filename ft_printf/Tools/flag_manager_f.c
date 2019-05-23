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

int			is_nan(long double nb)
{
	return (!(nb == nb));
}

int			is_inf(long double nb)
{
	if (nb == (1.0 / 0.0) || nb == -(1.0 / 0.0))
		return (1);
	else
		return (0);
}

t_printf	flag_manager_f(long double nb, t_printf p)
{
	p.inf = 0;
	p.nan = 0;
	if (nb < 0)
		p.plus = -1;
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
