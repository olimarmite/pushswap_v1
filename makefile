NAME := pushswap

SRC_DIR := src
OBJ_DIR := obj

SRCS := \
	main.c									\
	exception_management/ft_error.c			\
	pushswap/pushswap_create.c				\
	pushswap/pushswap_operations_print.c	\
	pushswap/pushswap_rotate.c				\
	pushswap/pushswap_index_stack.c			\
	pushswap/pushswap_free.c				\
	pushswap/pushswap_operations_add.c		\
	pushswap/pushswap_push.c				\
	pushswap/pushswap_swap.c				\
	pushswap/pushswap_stack_from_id.c		\
	pushswap/pushswap_operations_reduce.c	\
	sorter/sorter.c							\
	sorter/presort.c						\
	utils/ft_memmove.c						\
	utils/ft_isdigit.c						\
	utils/ft_putstr.c						\
	utils/ft_atoi.c							\
	utils/ft_abs.c							\
	utils/stack/stack_insert.c				\
	utils/stack/stack_first.c				\
	utils/stack/stack_resize.c				\
	utils/stack/stack_print.c				\
	utils/stack/stack_indexof.c				\
	utils/stack/stack_add.c					\
	utils/stack/stack_operations.c			\
	utils/stack/stack_last.c				\
	utils/stack/stack_free.c				\
	utils/stack/stack_remove.c				\
	utils/stack/stack_create.c				\
	utils/stack/stack_max_index.c			\
	utils/stack/stack_add_multiple.c		\
	utils/ft_max.c							\
	utils/ft_min.c							\
	utils/distance_from_zero_add.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC	:= gcc
CFLAGS := -Wall -Werror -Wextra
CPPFLAGS := -I .
MAKEFLAGS   += --no-print-directory

RM	:= rm -rf
DIR_DUP = mkdir -p $(@D)


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $@)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS) $(OBJ_DIR)
	$(info DELETED $(OBJ_DIR))

fclean: clean
	$(RM) $(NAME)
	$(info DELETED $(NAME))

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: clean fclean re
.SILENT:
