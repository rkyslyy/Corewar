NAME = corewar

SRCDIR = ./src/
SRCNAMES = $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./inc/
BUILDDIR = ./
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

LIBDIR = ../libft/libft
LIBFT = ../libft/libft/libft.a
LIBINC = ../libft/libft
CORHEAR = ./inc/corewar.h
VISHEAD = ./inc/visualization.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NC = -lncurses

all: $(NAME)

$(BUILDDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -o $@ -c $<

$(NAME): $(LIBFT) $(BUILDOBJS) $(CORHEAD) $(VISHEAD)
	$(CC) $(CFLAGS) $(NC) -o $(NAME) $(BUILDOBJS) $(LIBFT)

$(LIBFT):
	make -C $(LIBDIR)

clean:
	rm -f $(BUILDOBJS)
	make clean -C $(LIBDIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBDIR)

re: fclean all

.PHONY: all fclean clean re
