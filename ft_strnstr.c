/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:58:25 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/09 19:24:46 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t hlen)
{
	size_t	nlen;
	int		lastresult;

	if (*needle == '\0')
		return ((char*)haystack);
	nlen = ft_strlen(needle);
	lastresult = 1;
	while (nlen <= hlen && *haystack != '\0'
		&& (lastresult = ft_strncmp(haystack, needle, nlen)))
	{
		hlen--;
		haystack++;
	}
	if (lastresult != 0)
		return (NULL);
	else
		return ((char *)haystack);
}
