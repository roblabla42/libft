/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 11:38:22 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/02 16:23:03 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmp;
	t_list *lst;

	if (alst == NULL)
		return ;
	lst = *alst;
	while (lst != NULL)
	{
		tmp = lst->next;
		ft_lstdelone(&lst, del);
		lst = tmp;
	}
	*alst = NULL;
}
