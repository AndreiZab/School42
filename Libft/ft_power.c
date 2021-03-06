/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:01:38 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/10 16:03:04 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int power)
{
	if ((nb == -10 && (power % 2 == 0)) || nb == 1)
	{
		return (1);
	}
	if (nb == -1 && (power % 2 == 1))
	{
		return (-1);
	}
	if (power == 0)
	{
		return (1);
	}
	if (power < 0)
	{
		return (0);
	}
	return (nb * (ft_power(nb, power - 1)));
}
