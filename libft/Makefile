# Define library
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
#Source Files
SRCS = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c\
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c \
get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c \
ft_printf/ft_printstr.c \
ft_printf/ft_printchar.c \
ft_printf/ft_print_unsigned.c \
ft_printf/ft_printf.c \
ft_printf/ft_putstr.c \
ft_printf/ft_print_hex.c \
ft_printf/ft_printnbr.c \
ft_printf/ft_print_pointer.c \
ft_isspace.c \
ft_strcmp.c \
ft_strspn.c \
ft_strndup.c
#Object files
OBJS = $(SRCS:.c=.o)
#Rules
all: $(NAME)
#link mandatory object files into a static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
#complile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
#clean up object files
clean:
	rm -f $(OBJS)
#Clean up all generated files
fclean: clean
	rm -f $(NAME)
#Recompile everything
re: fclean all
