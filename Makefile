#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 11:08:14 by nbouteme          #+#    #+#              #
#    Updated: 2016/01/06 18:16:58 by nbouteme         ###   ########.fr        #
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

UNAME = $(shell uname)
$(if $(findstring mlx,$(BUILDLIB)), \
$(eval DEP += mlx\
$(if $(findstring Linux,$(UNAME)),$(eval DEP += X11 Xext))\
$(eval PDEP += minilibx)\
$(eval LDEP += minilibx)\
$(if $(findstring Darwin,$(UNAME)),$(eval SUPF += -framework OpenGL -framework AppKit))))
$(if $(findstring gfx,$(BUILDLIB)), $(eval DEP += m))

SRC =

# no wildcard :^)
$(foreach sublib, $(BUILDLIB), $(eval SRC += $(shell find $(sublib) | grep \\.c$)))

INCDIR = ./includes

OBJ = $(SRC:.c=.o)
CC = clang
WFLAGS = -Wall -Wextra -Werror -I$(INCDIR) 
CFLAGS = -O3 -march=native -mtune=native -ffinite-math-only -funsafe-math-optimizations -fno-math-errno -ffast-math
#CFLAGS = -g
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
	@$(DEP_ECHO) SUPF := $(SUPF)
%.o: %.c
	@$(CC) $(WFLAGS) $(CFLAGS) -c $^ -o $@
	@$(ECHO) -e "\033[0;32m[✓] Built C object" $@

$(NAME): $(OBJ)
	@$(ECHO) "\033[0;34m--------------------------------"
	@ld -r $(OBJ) -o $(NAME)
	@$(ECHO) "\033[0;31m[✓] Linked C library" $(NAME)

.PHONY: clean fclean re

clean:
	@/bin/rm -rf $(OBJ)
	@$(ECHO) -e "\033[0;33m[✓] Removed object files" $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)
	@$(ECHO) -e "\033[0;33m[✓] Removed executable" $(NAME)

re: fclean all
