/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_stream.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 19:52:50 by rlambert          #+#    #+#             */
/*   Updated: 2015/04/02 23:16:32 by rlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <netinet/in.h>
#include "stream.h"

int				write_s8(t_stream *stream, int8_t c)
{
	return (write(stream->fd, &c, 1) >= 0);
}

int				write_s32be(t_stream *stream, int32_t nbr)
{
	nbr = htonl(nbr);
	return (write(stream->fd, &nbr, sizeof(nbr)) >= 0);
}

int				write_string(t_stream *stream, char *s, size_t len)
{
	if (s == NULL)
	{
		s = "";
		len = 0;
	}
	return (write_s32be(stream, len) && write(stream->fd, s, len) >= 0);
}
