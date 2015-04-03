/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avladd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 16:42:47 by rlambert          #+#    #+#             */
/*   Updated: 2015/04/03 17:21:36 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_avlupdateheight(t_avl *n)
{
	n->height = ft_max(ft_avlheight(n->left), ft_avlheight(n->right)) + 1;
}

static void		ft_avllrotate(t_avl **node)
{
	t_avl	*root;
	t_avl	*pivot;

	root = (*node);
	pivot = root->right;
	root->right = pivot->left;
	pivot->left = root;
	ft_avlupdateheight(root);
	ft_avlupdateheight(pivot);
	*node = pivot;
}

static void		ft_avlrrotate(t_avl **node)
{
	t_avl	*root;
	t_avl	*pivot;

	root = (*node);
	pivot = root->left;
	root->left = pivot->right;
	pivot->right = root;
	ft_avlupdateheight(root);
	ft_avlupdateheight(pivot);
	*node = pivot;
}

static void		ft_avlrebalance(t_avl **root)
{
	int		balance;
	int		lbalance;
	int		rbalance;
	t_avl	*n;

	n = *root;
	balance = n == NULL ? 0 : ft_avlheight(n->left) - ft_avlheight(n->right);
	lbalance = (n != NULL && balance > 1) ? ft_avlheight(n->left->left) -
											ft_avlheight(n->left->right) : 0;
	rbalance = (n != NULL && balance < -1) ? ft_avlheight(n->right->left) -
											ft_avlheight(n->right->right) : 0;
	if (balance > 1 && lbalance >= 0)
		ft_avlrrotate(root);
	else if (balance > 1 && lbalance < 0)
	{
		ft_avllrotate(&n->left);
		ft_avlrrotate(root);
	}
	else if (balance < -1 && rbalance <= 0)
		ft_avllrotate(root);
	else if (balance < -1 && rbalance > 0)
	{
		ft_avlrrotate(&n->right);
		ft_avllrotate(root);
	}
}

void			ft_avladd(t_avl **node, t_avl *avl)
{
	if (*node == NULL)
	{
		*node = avl;
		return ;
	}
	if (avl->key < (*node)->key)
		ft_avladd(&(*node)->left, avl);
	else
		ft_avladd(&(*node)->right, avl);
	ft_avlupdateheight(*node);
	ft_avlrebalance(node);
}
