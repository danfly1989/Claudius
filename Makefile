NAME_MINISHELL = minishell

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_MINISHELL = \
	src/minishell.c src/heredoc.c src/util.c src/util2.c src/signal.c src/token.c src/update.c src/builtin.c src/child.c src/redir.c src/exit.c src/pipe.c src/main.c src/dir.c src/parent.c src/shell_lvl.c src/free.c src/check.c src/syntax.c src/sigint.c src/var.c src/quote.c src/count.c src/extract.c src/merge.c src/expand.c src/export.c src/env.c src/duplicate.c src/list.c src/cmd.c src/parse.c src/clean.c src/exec.c src/remove.c src/apply_redir.c src/define.c src/util3.c src/hold.c src/tokenize_line.c

OBJ_MINISHELL = $(SRC_MINISHELL:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wunused-function -Wunused-variable -Wunused-label -Iincludes -I$(LIBFT_DIR)
LDFLAGS = -L$(LIBFT_DIR)
LDLIBS = -lft -lreadline -lhistory

.PHONY: all clean fclean re debug check-deps

all: check-deps $(NAME_MINISHELL)

check-deps:
	@echo "If you only see this message, it is already made..."
	@if [ ! -f "$(LIBFT)" ]; then \
		echo "libft not found, will build it..."; \
		make -C $(LIBFT_DIR); \
	fi

$(NAME_MINISHELL): $(OBJ_MINISHELL) $(LIBFT)
	@echo "Linking $(NAME_MINISHELL)..."
	$(CC) $(CFLAGS) $(OBJ_MINISHELL) -o $@ $(LDFLAGS) $(LDLIBS)

src/%.o: src/%.c
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJ_MINISHELL)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME_MINISHELL)

re: fclean all

debug:
	@echo "=== Debug Information ==="
	@echo "Operating system: $(shell uname -s)"
	@echo "LIBFT exists: $(shell test -f $(LIBFT) && echo 'YES' || echo 'NO')"
	@echo "Git available: $(shell which git >/dev/null 2>&1 && echo 'YES' || echo 'NO')"
	@echo "Source files:"
	@ls -la src/ 2>/dev/null || echo "src/ directory not found"
	@echo "========================"
