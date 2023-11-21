CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)
NAME = push_swap

INCLUDE_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj

SRCS =  $(SRC_DIR)/push_swap_main.c  \
		$(SRC_DIR)/stack_essentials.c  \
		$(SRC_DIR)/fill_stack_a.c \
		$(SRC_DIR)/errors_utils.c \
		$(SRC_DIR)/extra_utils.c \
		$(SRC_DIR)/testing_essentials.c \
		$(SRC_DIR)/swaps.c \
		$(SRC_DIR)/pushes.c \
		$(SRC_DIR)/rotate.c \
		$(SRC_DIR)/reverse_rotate.c \
		$(SRC_DIR)/split.c \
		$(SRC_DIR)/mini_sort.c \
		$(SRC_DIR)/algorithm.c \
		$(SRC_DIR)/algorithm_utils.c \
		$(SRC_DIR)/algorithm_utils2.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ -o $@

# Make sure dir exists
$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: #TODO

clean:
	rm -f $(OBJS)
	if [ -d "$(OBJ_DIR)" ]; then \
		rmdir $(OBJ_DIR); \
	fi

fclean: clean
	rm -f $(NAME)

re: fclean all

r:
	./push_swap

.PHONY: all clean fclean re

