/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsuffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblabla </var/spool/mail/roblabla>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:55:04 by roblabla          #+#    #+#             */
/*   Updated: 2015/02/28 13:34:12 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strsuffix(const char *str, const char *suffix)
{
	const char	*str_iter;
	const char	*suffix_iter;

	str_iter = str;
	suffix_iter = suffix;
	while (*str_iter != '\0')
		str_iter++;
	while (*suffix_iter != '\0')
		suffix_iter++;
	while (suffix_iter >= suffix && str_iter >= str &&
			*str_iter == *suffix_iter)
	{
		str_iter--;
		suffix_iter--;
	}
	return (suffix_iter < suffix);
}
