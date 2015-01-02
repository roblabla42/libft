/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:30:12 by rlambert          #+#    #+#             */
/*   Updated: 2014/11/08 15:44:49 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*first;
	t_list	*prev;
	t_list	*new;

	first = NULL;
	if (lst != NULL)
	{
		first = ft_lstnew(lst->content, lst->content_size);
		if (first == NULL)
			return (NULL);
		first = f(first);
		prev = first;
		lst = lst->next;
	}
	while (lst != NULL)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		if (new == NULL)
			return (NULL);
		new = f(new);
		prev->next = new;
		lst = lst->next;
	}
	return (first);
}
