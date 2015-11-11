/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:58:25 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/09 19:28:56 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *s1_it;
	const char *s2_it;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		s1_it = s1;
		s2_it = s2;
		while (*s2_it != '\0' && *s1_it == *s2_it)
		{
			s1_it++;
			s2_it++;
		}
		if (*s2_it == '\0')
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
