/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 19:51:07 by rlambert          #+#    #+#             */
/*   Updated: 2015/11/11 15:36:38 by roblabla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_H
# define STREAM_H
# define BUFSIZE 4096
# include <stdint.h>
# include <sys/types.h>

typedef struct	s_stream
{
	int			fd;
	char		buf[BUFSIZE];
	ssize_t		size;
	size_t		cursor;
}				t_stream;

void			create_stream(int fd, t_stream *stream);
void			fill_buf(t_stream *stream);
int				read_s8(t_stream *stream, int8_t *c);
int				read_s32be(t_stream *stream, int32_t *c);
int				read_u8(t_stream *stream, uint8_t *c);
int				read_u32be(t_stream *stream, uint32_t *c);
int				read_string(t_stream *stream, char **str, size_t *size);
int				read_until(t_stream *stream, char **str, char c);
int				write_s8(t_stream *stream, int8_t c);
int				write_s32be(t_stream *stream, int32_t c);
int				write_string(t_stream *stream, char *s, size_t size);
int				write_line(t_stream *stream, char *s);
#endif
