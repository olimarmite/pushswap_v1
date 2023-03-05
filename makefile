ifndef USE_BASIC_ERROR
	USE_BASIC_ERROR=1
endif

NAME			=	push_swap
NAME_CHECKER	=	checker

OBJ_COMMON_DIR	=	obj

SRC_STATION_DIR	=	src/pushswap_station
OBJ_STATION_DIR	=	$(OBJ_COMMON_DIR)/pushswap_station

SRC_SORTER_DIR	=	src/sorter
OBJ_SORTER_DIR	=	$(OBJ_COMMON_DIR)/sorter

SRC_CHECKER_DIR	=	src/checker
OBJ_CHECKER_DIR	=	$(OBJ_COMMON_DIR)/checker

SRCS_STATION = \
	$(addprefix utils/,							\
		$(addprefix printf/,					\
			ft_printf.c							\
			$(addprefix printers/,				\
				ft_printf_chr.c					\
				ft_printf_hex.c					\
				ft_printf_int.c					\
				ft_printf_percent.c				\
				ft_printf_ptr.c					\
				ft_printf_str.c					\
				ft_printf_u_int.c				\
			)									\
			$(addprefix utils/,					\
				ft_putchar.c					\
				ft_putnbr_base.c				\
				ft_putstr.c						\
				ft_u_putnbr_base.c				\
			)									\
		)										\
		$(addprefix stack/,						\
			stack_add.c							\
			stack_add_multiple.c				\
			stack_copy.c						\
			stack_create.c						\
			stack_first.c						\
			stack_free.c						\
			stack_indexof.c						\
			stack_insert.c						\
			stack_last.c						\
			stack_max.c							\
			stack_max_index.c					\
			stack_min.c							\
			stack_min_index.c					\
			stack_operations.c					\
			stack_print.c						\
			stack_remove.c						\
			stack_resize.c						\
			stack_is_sorted.c					\
		)										\
		distance_from_zero_add.c				\
		ft_abs.c								\
		ft_atoi.c								\
		ft_isdigit.c							\
		ft_max.c								\
		ft_memmove.c							\
		ft_min.c								\
		ft_putstr_fd.c							\
		ft_strcmp.c								\
	)											\
	$(addprefix pushswap/,						\
		pushswap_copy.c							\
		pushswap_create.c						\
		pushswap_free.c							\
		pushswap_index_stack.c					\
		pushswap_operations_add.c				\
		pushswap_operations_print.c				\
		pushswap_operations_reduce.c			\
		pushswap_push.c							\
		pushswap_rotate.c						\
		pushswap_stack_from_id.c				\
		pushswap_swap.c							\
	)											\
	$(addprefix parser/,						\
		parse_args.c							\
	)											\
	$(addprefix exception_management/,			\
		ft_error.c								\
	)

SRCS_SORTER = \
	$(addprefix sorter/, 						\
		cost_sort.c								\
		presort.c								\
		sort_small.c							\
		sort_utils.c							\
		sort_variator.c							\
		sorter.c								\
	)											\
	main.c

SRCS_CHECKER = \
	$(addprefix get_next_line/,					\
		get_next_line.c							\
		get_next_line_utils.c					\
		get_next_line_close.c					\
	)											\
	$(addprefix checker/,						\
		exec_operation.c						\
		parse_operations.c						\
		read_operations.c						\
	)											\
	main.c

SRCS_STATION	:= $(SRCS_STATION:%=$(SRC_STATION_DIR)/%)
OBJS_STATION	= $(SRCS_STATION:$(SRC_STATION_DIR)/%.c=$(OBJ_STATION_DIR)/%.o)

SRCS_SORTER		:= $(SRCS_SORTER:%=$(SRC_SORTER_DIR)/%)
OBJS_SORTER		= $(SRCS_SORTER:$(SRC_SORTER_DIR)/%.c=$(OBJ_SORTER_DIR)/%.o)

SRCS_CHECKER	:= $(SRCS_CHECKER:%=$(SRC_CHECKER_DIR)/%)
OBJS_CHECKER	= $(SRCS_CHECKER:$(SRC_CHECKER_DIR)/%.c=$(OBJ_CHECKER_DIR)/%.o)

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
CFLAGS			+= -g -D USE_BASIC_ERROR=$(USE_BASIC_ERROR) -I .

RM				= rm -rf
MKDIR 			= mkdir -p


all : $(NAME)

bonus : $(NAME_CHECKER)

$(NAME): $(OBJS_STATION) $(OBJS_SORTER)
	$(CC) $^ -o $@
	$(info CREATED $@)

$(NAME_CHECKER): $(OBJS_STATION) $(OBJS_CHECKER)
	$(CC) $^ -o $@
	$(info CREATED $@)

$(OBJ_STATION_DIR)/%.o: $(SRC_STATION_DIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<
	$(info CREATED $@)

$(OBJ_SORTER_DIR)/%.o: $(SRC_SORTER_DIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<
	$(info CREATED $@)

$(OBJ_CHECKER_DIR)/%.o: $(SRC_CHECKER_DIR)/%.c
	$(MKDIR) $(@D)
	$(CC) $(CFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJ_COMMON_DIR)
	$(info DELETED $(OBJ_COMMON_DIR))

fclean: clean
	$(RM) $(NAME) $(NAME_CHECKER)
	$(info DELETED $(NAME) $(NAME_CHECKER))

re: fclean all

# malloc_test:  $(OBJS_STATION) $(OBJS_SORTER)
# 	$(CC) $(OBJS_STATION) $(OBJS_SORTER) -fsanitize=undefined -rdynamic -o $@ -L. -lmallocator

.PHONY: clean fclean re bonus

.SILENT:
