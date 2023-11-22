CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE_DIR)
NAME = push_swap
BONUS = checker

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
		$(SRC_DIR)/algorithm_utils2.c \
		$(SRC_DIR)/bubble_sort.c

BONUSF = $(SRC_DIR)/stack_essentials.c  \
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
		$(SRC_DIR)/algorithm_utils2.c \
		$(SRC_DIR)/get_next_line_utils.c \
		$(SRC_DIR)/get_next_line.c \
		$(SRC_DIR)/checker.c \
		$(SRC_DIR)/checker_utils.c \
		$(SRC_DIR)/bubble_sort.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
BOBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(BONUSF))

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

bonus: $(BONUS)

$(BONUS): $(BOBJS) 
	$(CC) $^ -o $@

clean:
	rm -f $(OBJS) $(BOBJS) 
	if [ -d "$(OBJ_DIR)" ]; then \
		rm -rf $(OBJ_DIR); \
	fi

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re

