/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 14:03:20 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/02 15:03:25 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_avl	*ft_avlnew(int key, void *content, size_t content_size)
{
	t_avl *avl;

	if ((avl = (t_avl*)malloc(sizeof(t_avl))) == NULL)
		return (NULL);
	avl->key = key;
	avl->height = 1;
	if (content != NULL)
	{
		avl->content = malloc(content_size);
		if (avl->content == NULL)
		{
			free(avl);
			return (NULL);
		}
		ft_memcpy(avl->content, content, content_size);
		avl->content_size = content_size;
	}
	else
	{
		avl->content = NULL;
		avl->content_size = 0;
	}
	avl->left = NULL;
	avl->right = NULL;
	return (avl);
}
