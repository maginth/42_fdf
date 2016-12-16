#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/28 14:44:33 by mguinin           #+#    #+#              #
#    Updated: 2015/01/31 15:03:23 by mguinin          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
IPATH = ./include/
SPATH = ./src/
OPATH = ./obj/
SRCS = 	main.c \
		draw_grid.c \
		geom.c \
		projection.c \
		put_line.c \
		put_triangle.c \
		limit_shape.c \
		view.c \
		bind_key.c \
		read_file.c \
		fill_grid.c \
		quicksort.c \

LIB = -L./libft -lft -L./win -lwin -L./minilibx -lmlx -lXext -lX11 

V ?= 0

D ?= 0

SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))

DEBUG_1 = -g3
DEBUG_0 =


CFLAGS = $(DEBUG_$(D)) -Wall -Werror -Wextra -O3
CC = $(SILENCE)gcc
RM = $(SILENCE)rm -rf

SRC = $(addprefix $(SPATH), $(SRCS))
OBJS= $(SRC:$(SPATH)%.c=$(OPATH)%.o)

SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
C = \033[1;34m
U = $(C)[$(NAME)]----->\033[0m

all: $(NAME)

$(NAME): $(OPATH) $(OBJS) libft/libft.a win/libwin.a
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]\033[0m"
	@echo "\033[0;32m"
	$(CC) -o $@ $(CFLAGS) -I$(IPATH) $(OBJS) $(LIB)
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

$(OPATH):
	mkdir -p $(OPATH)

libft/libft.a:
	@make -C libft

win/libwin.a:
	@make -C win

mlx: minilibx/libmlx.a

minilibx/libmlx.a:
	sed -i 's_<mlx.h>_<../minilibx/mlx.h>_g' */*.h
	wget http://files.achedeuzot.me/42/mlx/mlx-2014-01-06.tgz
	tar -xzf mlx-2014-01-06.tgz
	if make -C minilibx 2>&1 > /dev/null | grep strlcpy ; \
	then ; \
		sed -i 's/strlcpy/strncpy/g' minilibx/*.c ; \
		make -C minilibx; \
	fi

$(OPATH)%.o: $(SPATH)%.c
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) -o $@ $(CFLAGS) -I$(IPATH) -c $<
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"

clean:
	@echo "$(U)$(C)[CLEAN]\033[0;32m"
	$(RM) $(OBJS)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean
	@echo "$(U)$(C)[F-CLEAN]\033[1;32m"
	$(RM) $(NAME)
	@make -C win fclean
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re: fclean all

.PHONY: clean fclean
