# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/27 14:08:01 by mguinin           #+#    #+#              #
#    Updated: 2015/01/28 11:59:31 by mguinin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LNAME = win
NAME = lib$(LNAME).a
CNAME = l$(LNAME)

SRCS = 	close_win.c \
		fill_win.c \
		loop_func.c \
		open_win.c \
		refresh_win.c \
		win_key_func.c \
		init_mlx.c \
		is_pressed.c \

V ?= 0

D ?= 0

SILENCE_1 :=
SILENCE_0 :=@
SILENCE = $(SILENCE_$(V))

DEBUG_0 :=
DEBUG_1 :=-g3

INCLUDE = ./
CFLAGS = $(DEBUG_$(D)) -Wall -Werror -Wextra
CC = $(SILENCE)gcc
LIB = $(SILENCE)ar rcs
RM = $(SILENCE)rm -rf

SRCPATH = ./

SRC = $(addprefix $(SRCPATH), $(SRCS))
OBJS= $(SRC:.c=.o)

SKIP_1 :=
SKIP_0 := \033[A
SKIP = $(SKIP_$(V))
C = \033[1;34m
U = $(C)[$(NAME)]----->\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(U)$(C)[COMPILE:\033[1;32m DONE$(C)]\033[0m"
	@echo "$(U)$(C)[BUILD LIB]\033[0;32m"
	$(LIB) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(SKIP)$(U)$(C)[BUILD  :\033[1;32m DONE$(C)]\033[0m"

%.o: %.c
	@echo "$(U)$(C)[COMPILE: \033[1;31m$<\033[A\033[0m"
	@echo "\033[0;32m"
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDE)
	@echo "\033[1;31m [.working.]"
	@echo "$(SKIP)\033[A\033[2K$(SKIP)"

clean:
	@echo "$(U)$(C)[CLEAN]\033[0;32m"
	$(RM) $(OBJS)
	@echo "$(SKIP)$(U)$(C)[CLEAN:\033[1;32m   DONE$(C)]\033[0m"

fclean: clean
	@echo "$(U)$(C)[F-CLEAN]\033[1;32m"
	$(RM) $(NAME)
	@echo "$(SKIP)$(U)$(C)[F-CLEAN:\033[1;32m DONE$(C)]\033[0m"

re: fclean all

.PHONY: clean fclean
