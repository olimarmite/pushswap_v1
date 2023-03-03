ifndef USE_BASIC_ERROR
	USE_BASIC_ERROR=1
endif

NAME := push_swap
NAME_CHECKER := checker

OBJ_COMMON_DIR := obj

SRC_STATION_DIR := src/pushswap_station
OBJ_STATION_DIR := $(OBJ_COMMON_DIR)/pushswap_station

SRC_SORTER_DIR := src/sorter
OBJ_SORTER_DIR := $(OBJ_COMMON_DIR)/sorter

SRC_CHECKER_DIR := src/checker
OBJ_CHECKER_DIR := $(OBJ_COMMON_DIR)/checker

SRCS_STATION := \
	utils/distance_from_zero_add.c				\
	utils/ft_abs.c								\
	utils/ft_atoi.c								\
	utils/ft_isdigit.c							\
	utils/ft_max.c								\
	utils/ft_memmove.c							\
	utils/ft_min.c								\
	utils/ft_putstr_fd.c						\
	utils/printf/ft_printf.c					\
	utils/printf/printers/ft_printf_chr.c		\
	utils/printf/printers/ft_printf_hex.c		\
	utils/printf/printers/ft_printf_int.c		\
	utils/printf/printers/ft_printf_percent.c	\
	utils/printf/printers/ft_printf_ptr.c		\
	utils/printf/printers/ft_printf_str.c		\
	utils/printf/printers/ft_printf_u_int.c		\
	utils/printf/utils/ft_putchar.c				\
	utils/printf/utils/ft_putnbr_base.c			\
	utils/printf/utils/ft_putstr.c				\
	utils/printf/utils/ft_u_putnbr_base.c		\
	utils/ft_strcmp.c							\
	utils/stack/stack_add.c						\
	utils/stack/stack_add_multiple.c			\
	utils/stack/stack_copy.c					\
	utils/stack/stack_create.c					\
	utils/stack/stack_first.c					\
	utils/stack/stack_free.c					\
	utils/stack/stack_indexof.c					\
	utils/stack/stack_insert.c					\
	utils/stack/stack_last.c					\
	utils/stack/stack_max.c						\
	utils/stack/stack_max_index.c				\
	utils/stack/stack_min.c						\
	utils/stack/stack_min_index.c				\
	utils/stack/stack_operations.c				\
	utils/stack/stack_print.c					\
	utils/stack/stack_remove.c					\
	utils/stack/stack_resize.c					\
	utils/stack/stack_is_sorted.c				\
	pushswap/pushswap_copy.c					\
	pushswap/pushswap_create.c					\
	pushswap/pushswap_free.c					\
	pushswap/pushswap_index_stack.c				\
	pushswap/pushswap_operations_add.c			\
	pushswap/pushswap_operations_print.c		\
	pushswap/pushswap_operations_reduce.c		\
	pushswap/pushswap_push.c					\
	pushswap/pushswap_rotate.c					\
	pushswap/pushswap_stack_from_id.c			\
	pushswap/pushswap_swap.c					\
	parser/parse_args.c							\
	exception_management/ft_error.c

SRCS_SORTER := \
	main.c					\
	sorter/cost_sort.c		\
	sorter/presort.c		\
	sorter/sort_small.c		\
	sorter/sort_utils.c		\
	sorter/sort_variator.c	\
	sorter/sorter.c

SRCS_CHECKER := \
	main.c										\
	get_next_line/get_next_line.c				\
	get_next_line/get_next_line_utils.c			\
	checker/exec_operation.c					\
	checker/parse_operations.c					\
	checker/read_operations.c

SRCS_STATION := $(SRCS_STATION:%=$(SRC_STATION_DIR)/%)
OBJS_STATION := $(SRCS_STATION:$(SRC_STATION_DIR)/%.c=$(OBJ_STATION_DIR)/%.o)

SRCS_SORTER := $(SRCS_SORTER:%=$(SRC_SORTER_DIR)/%)
OBJS_SORTER := $(SRCS_SORTER:$(SRC_SORTER_DIR)/%.c=$(OBJ_SORTER_DIR)/%.o)

SRCS_CHECKER := $(SRCS_CHECKER:%=$(SRC_CHECKER_DIR)/%)
OBJS_CHECKER := $(SRCS_CHECKER:$(SRC_CHECKER_DIR)/%.c=$(OBJ_CHECKER_DIR)/%.o)

CC	:= cc
CFLAGS := -Wall -Wextra -Werror -g -D USE_BASIC_ERROR=$(USE_BASIC_ERROR)
CPPFLAGS := -I .
MAKEFLAGS   += --no-print-directory

RM	:= rm -rf
DIR_DUP = mkdir -p $(@D)


all : $(NAME)

bonus : $(NAME_CHECKER)

$(NAME): $(OBJS_STATION) $(OBJS_SORTER)
	$(CC) $(OBJS_STATION) $(OBJS_SORTER) -o $(NAME)
	$(info CREATED $@)

$(NAME_CHECKER): $(OBJS_STATION) $(OBJS_CHECKER)
	$(CC) $(OBJS_STATION) $(OBJS_CHECKER) -o $(NAME_CHECKER)
	$(info CREATED $(NAME_CHECKER))

$(OBJ_STATION_DIR)/%.o: $(SRC_STATION_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

$(OBJ_SORTER_DIR)/%.o: $(SRC_SORTER_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

$(OBJ_CHECKER_DIR)/%.o: $(SRC_CHECKER_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS_SORTER) $(OBJS_CHECKER) $(OBJ_SORTER_DIR) $(OBJ_CHECKER_DIR) $(OBJ_COMMON_DIR)
	$(info DELETED $(OBJ_SORTER_DIR) $(OBJ_CHECKER_DIR) $(OBJ_COMMON_DIR))

fclean: clean
	$(RM) $(NAME) $(NAME_CHECKER)
	$(info DELETED $(NAME) $(NAME_CHECKER))

re:
	$(MAKE) fclean
	$(MAKE) all

# malloc_test: $(OBJS_SORTER)
# 	$(CC) $(OBJS_SORTER) -fsanitize=undefined -rdynamic -o $@ -L. -lmallocator

.PHONY: clean fclean re bonus
.SILENT:
