#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 11:08:14 by nbouteme          #+#    #+#              #
#    Updated: 2015/12/09 13:39:11 by nbouteme         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCDIR = .

INCDIR = .

SRC =	ft_putchar_fd.c			\
		ft_putendl_fd.c			\
		ft_lstreduce.c			\
		ft_lstdelone.c			\
		ft_strindexof.c			\
		ft_putnbr_fd.c			\
		ft_putstr_fd.c			\
		ft_lstmapup.c			\
		ft_lstfilter.c			\
		ft_memalloc.c			\
		ft_strsplit.c			\
		ft_striteri.c			\
		ft_tolower.c			\
		ft_toupper.c			\
		ft_lstpush.c			\
		ft_isalnum.c			\
		ft_isalpha.c			\
		ft_isascii.c			\
		ft_isdigit.c			\
		ft_islower.c			\
		ft_isprint.c			\
		ft_isspace.c			\
		ft_isupper.c			\
		ft_lstiter.c			\
		ft_memccpy.c			\
		ft_memmove.c			\
		ft_putchar.c			\
		ft_putendl.c			\
		ft_striter.c			\
		ft_strjoin.c			\
		ft_strlcat.c			\
		ft_strmapi.c			\
		ft_strncat.c			\
		ft_strncmp.c			\
		ft_strncpy.c			\
		ft_strnstr.c			\
		ft_strrchr.c			\
		ft_strtrim.c			\
		ft_lstadd.c				\
		ft_lstdel.c				\
		ft_lstmap.c				\
		ft_lstnew.c				\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_memcpy.c				\
		ft_memdel.c				\
		ft_memset.c				\
		ft_putstr.c				\
		ft_strcat.c				\
		ft_strchr.c				\
		ft_strclr.c				\
		ft_strcmp.c				\
		ft_strcpy.c				\
		ft_strdel.c				\
		ft_strdup.c				\
		ft_strlen.c				\
		ft_strmap.c				\
		ft_strnequ.c				\
		ft_strnew.c				\
		ft_strrev.c				\
		ft_strstr.c				\
		ft_strsub.c				\
		ft_putnbr.c				\
		ft_bzero.c				\
		ft_strequ.c				\
		ft_atoi.c				\
		ft_itoa.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -g

all: $(NAME)

%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $^
	@echo -e "\033[0;32m[✓] Built C object" $@

$(NAME): $(OBJ)
	@echo -e "\033[0;34m--------------------------------"
	@ar rc $(NAME) $(OBJ)
	@echo -e "\033[0;31m[✓] Linked C library" $(NAME)
.PHONY: clean fclean re
clean:
	@/bin/rm -rf $(OBJ)
	@echo -e "\033[0;33m[✓] Removed object files" $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo -e "\033[0;33m[✓] Removed executable" $(NAME)

re: fclean all
