/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 12:21:20 by rhealitt          #+#    #+#             */
/*   Updated: 2019/06/07 19:57:10 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	quick_sort(int *list, int min, int max)
{
	int pivot;
	int i;
	int j;
	int k;

	if (min < max)
	{
		k = (min + max) / 2;
		ft_swap(&list[min], &list[k]);
		pivot = list[min];
		i = min + 1;
		j = max;
		while (i <= j)
		{
			while ((i <= max) && (list[i] <= pivot))
				i++;
			while ((j >= min) && (list[j] > pivot))
				j--;
			if (i < j)
				ft_swap(&list[i], &list[j]);
		}
		ft_swap(&list[min], &list[j]);
		quick_sort(list, min, j - 1);
		quick_sort(list, j + 1, max);
	}
}

int		ft_median(int *array, int len)
{
	int	temp[len];

	ft_memcpy(temp, array, len * 4);
	quick_sort(temp, 0, len - 1);
	return (temp[len / 2]);
}

int		ft_duplicates(int *array, int len)
{
	int	temp[len];
	int i;

	i = 0;
	ft_memcpy(temp, array, len * 4);
	quick_sort(temp, 0, len - 1);
	while (++i < len)
		if (temp[i - 1] == temp[i])
			return (1);
	return (0);
}

int		*ft_reverce(int *ar, size_t n)
{
	int		tmp;
	size_t	i;

	if (!ar)
		return (0);
	i = -1;
	while (++i < n / 2)
	{
		tmp = ar[i];
		ar[i] = ar[n - i - 1];
		ar[n - i - 1] = tmp;
	}
	return (ar);
}
