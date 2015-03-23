/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:52:58 by roblabla          #+#    #+#             */
/*   Updated: 2015/02/28 13:33:51 by roblabla         ###   ########.fr       */
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
