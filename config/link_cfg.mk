INCLUDE_DIRS = $(PKG_DIR)/includes
LFLAGS = -L$(PKG_DIR) -lft
CFLAGS = $(addprefix -I,$(INCLUDE_DIRS))
