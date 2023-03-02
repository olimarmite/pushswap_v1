ifndef USE_BASIC_ERROR
	USE_BASIC_ERROR=1
endif

NAME := push_swap
NAME_BONUS := checker

OBJ_COMMON_DIR := obj

SRC_DIR := src/sorter
OBJ_DIR := $(OBJ_COMMON_DIR)/sorter

SRC_BONUS_DIR := src/checker
OBJ_BONUS_DIR := $(OBJ_COMMON_DIR)/checker

SRCS := \
	main.c										\
	exception_management/ft_error.c				\
	parser/parse_args.c							\
	pushswap/pushswap_create.c					\
	pushswap/pushswap_copy.c					\
	pushswap/pushswap_operations_print.c		\
	pushswap/pushswap_rotate.c					\
	pushswap/pushswap_index_stack.c				\
	pushswap/pushswap_free.c					\
	pushswap/pushswap_operations_add.c			\
	pushswap/pushswap_push.c					\
	pushswap/pushswap_swap.c					\
	pushswap/pushswap_stack_from_id.c			\
	pushswap/pushswap_operations_reduce.c		\
	sorter/sorter.c								\
	sorter/presort.c							\
	sorter/sort_utils.c							\
	sorter/cost_sort.c							\
	sorter/sort_small.c							\
	sorter/sort_variator.c						\
	utils/ft_memmove.c							\
	utils/ft_isdigit.c							\
	utils/ft_putstr_fd.c						\
	utils/ft_atoi.c								\
	utils/ft_abs.c								\
	utils/stack/stack_insert.c					\
	utils/stack/stack_first.c					\
	utils/stack/stack_resize.c					\
	utils/stack/stack_print.c					\
	utils/stack/stack_indexof.c					\
	utils/stack/stack_add.c						\
	utils/stack/stack_operations.c				\
	utils/stack/stack_last.c					\
	utils/stack/stack_free.c					\
	utils/stack/stack_remove.c					\
	utils/stack/stack_create.c					\
	utils/stack/stack_copy.c					\
	utils/stack/stack_max_index.c				\
	utils/stack/stack_min_index.c				\
	utils/stack/stack_max.c						\
	utils/stack/stack_min.c						\
	utils/stack/stack_add_multiple.c			\
	utils/ft_max.c								\
	utils/ft_min.c								\
	utils/distance_from_zero_add.c				\
	utils/printf/utils/ft_putchar.c				\
	utils/printf/utils/ft_putstr.c				\
	utils/printf/utils/ft_putnbr_base.c			\
	utils/printf/utils/ft_u_putnbr_base.c		\
	utils/printf/ft_printf.c					\
	utils/printf/printers/ft_printf_percent.c	\
	utils/printf/printers/ft_printf_str.c		\
	utils/printf/printers/ft_printf_u_int.c		\
	utils/printf/printers/ft_printf_int.c		\
	utils/printf/printers/ft_printf_chr.c		\
	utils/printf/printers/ft_printf_ptr.c		\
	utils/printf/printers/ft_printf_hex.c


SRCS_BONUS := \
	main.c										\
	utils/get_next_line/get_next_line_utils.c	\
	utils/get_next_line/get_next_line.c			\
	exception_management/ft_error.c				\
	parser/parse_args.c							\
	parser/parse_operations.c					\
	pushswap/pushswap_create.c					\
	pushswap/pushswap_copy.c					\
	pushswap/pushswap_operations_print.c		\
	pushswap/pushswap_rotate.c					\
	pushswap/pushswap_index_stack.c				\
	pushswap/pushswap_free.c					\
	pushswap/pushswap_operations_add.c			\
	pushswap/pushswap_push.c					\
	pushswap/pushswap_swap.c					\
	pushswap/pushswap_stack_from_id.c			\
	pushswap/pushswap_operations_reduce.c		\
	utils/ft_memmove.c							\
	utils/ft_isdigit.c							\
	utils/ft_putstr_fd.c						\
	utils/ft_atoi.c								\
	utils/ft_abs.c								\
	utils/ft_strcmp.c							\
	utils/stack/stack_insert.c					\
	utils/stack/stack_first.c					\
	utils/stack/stack_resize.c					\
	utils/stack/stack_print.c					\
	utils/stack/stack_indexof.c					\
	utils/stack/stack_add.c						\
	utils/stack/stack_operations.c				\
	utils/stack/stack_last.c					\
	utils/stack/stack_free.c					\
	utils/stack/stack_remove.c					\
	utils/stack/stack_create.c					\
	utils/stack/stack_copy.c					\
	utils/stack/stack_max_index.c				\
	utils/stack/stack_min_index.c				\
	utils/stack/stack_max.c						\
	utils/stack/stack_min.c						\
	utils/stack/stack_add_multiple.c			\
	utils/stack/stack_is_sorted.c				\
	utils/ft_max.c								\
	utils/ft_min.c								\
	utils/distance_from_zero_add.c				\
	utils/printf/utils/ft_putchar.c				\
	utils/printf/utils/ft_putstr.c				\
	utils/printf/utils/ft_putnbr_base.c			\
	utils/printf/utils/ft_u_putnbr_base.c		\
	utils/printf/ft_printf.c					\
	utils/printf/printers/ft_printf_percent.c	\
	utils/printf/printers/ft_printf_str.c		\
	utils/printf/printers/ft_printf_u_int.c		\
	utils/printf/printers/ft_printf_int.c		\
	utils/printf/printers/ft_printf_chr.c		\
	utils/printf/printers/ft_printf_ptr.c		\
	utils/printf/printers/ft_printf_hex.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS_BONUS := $(SRCS_BONUS:%=$(SRC_BONUS_DIR)/%)
OBJS_BONUS := $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)

CC	:= cc
CFLAGS := -Wall -Wextra -Werror -g -D USE_BASIC_ERROR=$(USE_BASIC_ERROR)
CPPFLAGS := -I .
MAKEFLAGS   += --no-print-directory

RM	:= rm -rf
DIR_DUP = mkdir -p $(@D)


all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $@)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $(NAME_BONUS)
	$(info CREATED $(NAME_BONUS))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $(OBJ_DIR) $(OBJ_BONUS_DIR) $(OBJ_COMMON_DIR)
	$(info DELETED $(OBJ_DIR) $(OBJ_BONUS_DIR) $(OBJ_COMMON_DIR))

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(info DELETED $(NAME) $(NAME_BONUS))

re:
	$(MAKE) fclean
	$(MAKE) all


# malloc_test: $(OBJS)
# 	$(CC) $(OBJS) -fsanitize=undefined -rdynamic -o $@ -L. -lmallocator

.PHONY: clean fclean re bonus
.SILENT:
