/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitwith.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:26:03 by rlambert          #+#    #+#             */
/*   Updated: 2015/04/01 23:20:06 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*find_next(char *str, char *seps, int skip)
{
	if (skip)
		while (*str != '\0' && ft_strchr(seps, *str) != NULL)
			str++;
	else
		while (*str != '\0' && ft_strchr(seps, *str) == NULL)
			str++;
	return (str);
}

static void		do_words(char *str, char *seps, void *data, void (*f)())
{
	char	*next;

	while (*str != '\0')
	{
		str = find_next(str, seps, 1);
		if (*str != '\0')
		{
			next = find_next(str, seps, 0);
			f(data, str, next);
			str = next;
		}
	}
}

static void		insert_word(char *data, char *str, char *next)
{
	char	***strs;
	size_t	*i;

	i = (size_t*)data;
	strs = (char***)(data + sizeof(size_t));
	if ((*strs) != NULL)
		(*strs)[*i] = ft_strsub(str, 0, next - str);
	*i += 1;
}

static void		setup_arg(char *arg, char **ret)
{
	size_t	*iarg;
	char	***retarg;

	iarg = (size_t*)arg;
	retarg = (char***)(arg + sizeof(size_t));
	*iarg = 0;
	*retarg = ret;
}

char			**ft_strsplitwith(char *str, char *seps, size_t *count)
{
	char	**ret;
	char	arg[sizeof(size_t) + sizeof(char**)];

	setup_arg(arg, NULL);
	do_words(str, seps, arg, insert_word);
	if (count != NULL)
		*count = *(size_t*)arg;
	ret = (char**)malloc(sizeof(char*) * (*(size_t*)arg + 1));
	ret[*(size_t*)arg] = NULL;
	setup_arg(arg, ret);
	if (ret == NULL)
		return (NULL);
	do_words(str, seps, arg, insert_word);
	return (ret);
}
