NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = main.c \
	data.c \
	stack.c \
	stack_find.c \
	checks.c \
	analysis.c \
	parse_flags.c \
	parsing.c \
	ops_utils.c \
	ops_swap.c \
	ops_push.c \
	ops_rotate.c \
	ops_rrotate.c \
	rotate_utils.c \
	sort_simple.c \
	sort_medium.c \
	sort_complex.c \
	sort_adaptive.c \
	sort_small.c \
	bench.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re