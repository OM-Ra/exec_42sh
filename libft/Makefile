# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 12:33:02 by mdelphia          #+#    #+#              #
#    Updated: 2019/04/07 12:33:05 by mdelphia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILE_C = 	ft_atoi.c ft_bzero.c ft_del.c ft_digitint.c \
			ft_freesplit.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_itoa.c ft_lenint.c ft_lstadd.c ft_lstadd_end.c \
			ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
			ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
			ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
			ft_putstr_fd.c ft_space_end.c ft_space_start.c ft_spacepass.c ft_strcat.c \
			ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
			ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
			ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
			ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
			ft_toupper.c ft_bintodec.c ft_dectobin.c ft_intlimit.c ft_llintlimit.c \
			ft_pow.c ft_powint.c ft_numchar.c ft_puterror.c ft_str_puterror.c \
			ft_faktorial.c ft_str3str.c ft_strmas.c ft_int_to_str.c ft_put_lli_nbr.c \
			ft_putspase.c ft_move_str_index.c

FILE_O = $(FILE_C:.c=.o)

FILE_H = -I ./

FLAGS = -Wall -Wextra -Werror

LIB = ar rc $(NAME) $(FILE_O)

all: $(NAME)

$(NAME): $(FILE_O)
	$(LIB)
	ranlib $(NAME)

%.o: %.c
	gcc -o $@ -c $< $(FLAGS) $(FILE_H)

clean:
	rm -f $(FILE_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
