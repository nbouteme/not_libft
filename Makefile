#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 11:08:14 by nbouteme          #+#    #+#              #
#    Updated: 2015/11/24 12:07:07 by nbouteme         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCDIR = src

INCDIR = includes

SRC = ft_atoi.c		\
	  ft_io.c		\
	  ft_is.c		\
	  ft_itoa.c		\
	  ft_llio.c		\
	  ft_memalloc.c \
	  ft_memchr.c	\
	  ft_memcmp.c	\
	  ft_memcpy.c	\
	  ft_memmove.c  \
	  ft_memset.c	\
	  ft_strchr.c	\
	  ft_streq.c	\
	  ft_strfun.c	\
	  ft_string.c	\
	  ft_strman.c	\
	  ft_strmem.c	\
	  ft_to.c		\

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -g

all: $(NAME)

%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $^
	@echo "\033[0;32m[✓] Built C object" $@

$(NAME): $(OBJ)
	@echo "\033[0;34m--------------------------------"
	@ar rc $(NAME) $(OBJ)
	@echo "\033[0;31m[✓] Linked C library" $(NAME)
clean:
	@/bin/rm -rf $(OBJ)
	@echo "\033[0;33m[✓] Removed object files" $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[0;33m[✓] Removed executable" $(NAME)

re: fclean all
