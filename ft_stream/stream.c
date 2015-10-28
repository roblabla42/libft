/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 19:23:36 by rlambert          #+#    #+#             */
/*   Updated: 2015/04/02 23:51:21 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include "stream.h"
#include <stdlib.h>

void			create_stream(int fd, t_stream *stream)
{
	stream->fd = fd;
	stream->size = read(fd, stream->buf, 4096);
	stream->cursor = 0;
}

void			fill_buf(t_stream *stream)
{
	if (stream->size > 0 && (ssize_t)stream->cursor >= stream->size)
	{
		stream->size = read(stream->fd, stream->buf, 4096);
		stream->cursor = 0;
	}
}

int				read_string(t_stream *stream, char **str, size_t *size)
{
	uint32_t	strsize;
	uint32_t	striter;
	int			oldstriter;
	char		*tmp;

	if (!read_u32be(stream, &strsize))
		return (0);
	*str = malloc(sizeof(char) * (strsize + 1));
	(*str)[strsize] = '\0';
	tmp = *str;
	striter = 0;
	oldstriter = 0;
	while (striter < strsize && stream->size > 0)
	{
		striter += FT_MIN(stream->size - stream->cursor, strsize - striter);
		ft_memmove(tmp, stream->buf + stream->cursor, striter - oldstriter);
		tmp += striter - oldstriter;
		stream->cursor += striter - oldstriter;
		oldstriter = striter;
		if (striter < strsize)
			fill_buf(stream);
	}
	if (size != NULL)
		*size = (size_t)strsize;
	return (striter == strsize);
}
