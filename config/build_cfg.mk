NAME = libft
TYPE = lib

CFLAGS = -Wall -Wextra -Werror -g
MODULES = std parser bits fun

INCLUDE_DIRS = $(PKG_DIR)/includes

OUTPUT = $(PKG_DIR)/libft.a

bits_EXT = .s
bits_CC = nasm

uname = $(shell uname)

ifeq ($(uname),Darwin)
bits_CFLAGS += -f macho64 -D__APPLE__
else
bits_CFLAGS += -f elf64
endif

bits_INPUTPREFIX =
