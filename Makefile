# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 11:25:08 by rlambert          #+#    #+#              #
#    Updated: 2015/10/28 14:16:38 by roblabla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS += -Wall -Wextra -Werror -Iinclude/

SRCS = ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strlen.c \
	   ft_nstrlen.c \
	   ft_strdup.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_strrev.c \
	   ft_atoi.c \
	   ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strjoin.c \
	   ft_multistrjoin.c \
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_strsplitwith.c \
	   ft_strprefix.c \
	   ft_strsuffix.c \
	   ft_itoa.c \
	   ft_utoa.c \
	   ft_putchar.c \
	   ft_putwchar.c \
	   ft_putstr.c \
	   ft_putwstr.c \
	   ft_putnwstr.c \
	   ft_putnstr.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putnbrbase.c \
	   ft_putchar_fd.c \
	   ft_putwchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putnstr_fd.c \
	   ft_putwstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putnbrbase_fd.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstlink.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_max.c \
	   ft_min.c \
	   ft_avladd.c \
	   ft_avlheight.c \
	   ft_avlnew.c \
	   ft_avlfind.c \
	   ft_stream/read_line.c \
	   ft_stream/read_signed.c \
	   ft_stream/read_unsigned.c \
	   ft_stream/stream.c \
	   ft_stream/write_stream.c \

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $?

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
