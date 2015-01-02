/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:56:08 by rlambert          #+#    #+#             */
/*   Updated: 2015/01/02 16:04:25 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *s2;

	if (dst == NULL || src == NULL)
		return (NULL);
	s2 = dst;
	while (*src != '\0' && len > 0)
	{
		*dst++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*dst++ = '\0';
		len--;
	}
	return (s2);
}
