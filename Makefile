NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Directories
OBJ_DIR		= obj
PRINTF_DIR	= printf

# Printf library
PRINTF		= $(printf)/libftprintf.a

# Source files (in root directory)
SRCS		= main.c \
			  parse_args.c \
			  parse_strategy.c \
			  error.c \
			  stack_new.c \
			  stack_free.c \
			  stack_push.c \
			  stack_pop.c \
			  stack_peek.c \
			  stack_utils.c \
			  stack_search.c \
			  stack_print.c \
			  op_swap.c \
			  op_push.c \
			  op_rotate.c \
			  op_reverse_rotate.c \
			  disorder.c \
			  sort_simple.c \
			  sort_three.c \
			  sort_five.c \
			  sort_medium.c \
			  sort_complex.c \
			  sort_adaptive.c \
			  benchmark.c

# Object files
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Header file
HEADER		= push_swap.h

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(PRINTF) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)
	@echo "$(GREEN)✓ push_swap compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)✓ Compiled: $<$(RESET)"

$(PRINTF):
	@echo "$(GREEN)Building ft_printf...$(RESET)"
	@make -C $(PRINTF_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@make -C $(PRINTF_DIR) clean
	@echo "$(RED)✗ Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(PRINTF_DIR) fclean
	@echo "$(RED)✗ push_swap removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re
