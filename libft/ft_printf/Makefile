# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source Files
SRCS = ft_printf.c \
       ft_print_hex.c \
       ft_print_unsigned.c \
       ft_print_pointer.c \
       ft_printnbr.c \
       ft_printchar.c \
       ft_printstr.c

# Object Files
OBJS = $(SRCS:.c=.o)

# Output (not an executable, but a function to append to a library)
NAME = libftprintf.a

# Default target (build the function to append to the library)
all: $(NAME)

# Compile all object files and create the static library (not an executable)
$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

# Compile libft (uses libft's own Makefile)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and the library
clean:
	rm -f $(OBJS)

# Clean everything (including libft)
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything (including libft)
re: fclean $(NAME)

# Uncomment to test functionality with a main (only for testing)
# run: $(NAME)
# 	./$(NAME)

.PHONY: all clean fclean re
