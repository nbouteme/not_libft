NAME = libft
TYPE = lib

CFLAGS = -Wall -Wextra -Werror -g
MODULES = std parser bits fun

INCLUDE_DIRS = $(PKG_DIR)/includes

OUTPUT = $(PKG_DIR)/libft.a

bits_EXT = .s
bits_CC = nasm
bits_CFLAGS = -f macho64

uname = $(shell uname)

ifeq ($(uname),Darwin)
bits_CFLAGS += -D__APPLE__
endif

bits_INPUTPREFIX =
