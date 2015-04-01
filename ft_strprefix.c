/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 23:19:28 by rlambert          #+#    #+#             */
/*   Updated: 2015/04/01 23:19:28 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strprefix(const char *str, const char *prefix)
{
	while (*prefix != '\0' && *str != '\0' && *str == *prefix)
	{
		prefix++;
		str++;
	}
	return (*prefix == '\0');
}
