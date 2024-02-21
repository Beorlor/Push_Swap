# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jedurand <jedurand@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 05:04:13 by jedurand          #+#    #+#              #
#    Updated: 2024/02/21 06:04:16 by jedurand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

INCS = ./checker.h \
       ./push_swap.h \
       ./gnl/get_next_line.h

AR = ar
ARFLAGS = rc

SRCS_DIR = ./gnl \
           ./operations \
           ./utils

OBJS_DIR = ./objs

LIBFT = libft.a
LIBFT_DIR = ./libft

GNL = libgnl.a
GNL_DIR = ./gnl

SRCS = ./operations/push_pop.c \
       ./operations/reverse_rotate_stack.c \
       ./operations/swap.c \
       ./utils/check_utils.c \
       ./utils/free.c \
       ./utils/my_atoi.c \
       ./utils/stack_utils.c \
       ./utils/min_mid_max.c \
       ./main.c \
       ./checker.c \
       ./do_operations.c

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(GNL_DIR)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(GNL_DIR) -lgnl

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(GNL_DIR) -c $< -o $@

clean :
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) clean
	@$(RM) -r $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
