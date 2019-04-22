/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:13:49 by rhealitt          #+#    #+#             */
/*   Updated: 2019/04/13 14:51:51 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;

	if (alst == NULL || del == NULL || *alst == NULL)
		return ;
	lst = *alst;
	del(lst->content, lst->content_size);
	free(*alst);
	*alst = NULL;
	return ;
}
