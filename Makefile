#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 11:08:14 by nbouteme          #+#    #+#              #
#    Updated: 2015/12/09 15:57:49 by nbouteme         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

#defaut
BUILDLIB = std

$(if $(OBUILDLIBS), $(eval BUILDLIB := $(OBUILDLIBS)))

DEP = ft
PDEP =
LDEP = libft

BUILDLIB := $(sort $(BUILDLIB))

$(if $(findstring mlx,$(BUILDLIB)), $(eval DEP += mlx X11 Xext) $(eval PDEP += minilibx) $(eval LDEP += minilibx))
$(if $(findstring gfx,$(BUILDLIB)), $(eval DEP += m))

SRC =

# no wildcard :^)
$(foreach sublib, $(BUILDLIB), $(eval SRC += $(shell find $(sublib) | grep \\.c$)))

INCDIR = ./includes

OBJ = $(SRC:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror -I$(INCDIR) -g

ECHO = echo
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
ECHO = echo -e
endif

DEP_ECHO = true

$(if $(OBUILDLIBS), $(eval DEP_ECHO := $(ECHO)) $(eval ECHO = true))

all: $(NAME)
	@$(DEP_ECHO) DEP := $(DEP)
	@$(DEP_ECHO) PDEP := $(PDEP)
	@$(DEP_ECHO) LDEP := $(LDEP)
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	@$(ECHO) -e "\033[0;32m[✓] Built C object" $@

$(NAME): $(OBJ)
	@$(ECHO) -e "\033[0;34m--------------------------------"
	@ld -r $(OBJ) -o $(NAME)
	@$(ECHO) -e "\033[0;31m[✓] Linked C library" $(NAME)

.PHONY: clean fclean re

clean:
	@/bin/rm -rf $(OBJ)
	@$(ECHO) -e "\033[0;33m[✓] Removed object files" $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)
	@$(ECHO) -e "\033[0;33m[✓] Removed executable" $(NAME)

re: fclean all
