NAME = minishell

CC = cc
CFLAGS = -Wall -Werror -Wextra 
INCLUDES = -I include -I Libft -I pipex -I Lexer/includes
LIBFT = Libft/libft.a
PIPEX = pipex/libpipex.a
LEXER = Lexer/lexer.a

OBJ_DIR = obj
OBJ_UTILS_DIR = obj/utils
OBJ_DEBUG_DIR = obj/debug

SRC_DIR = src
SRC =	$(SRC_DIR)/minishell.c \
		$(SRC_DIR)/find_key.c \
		$(SRC_DIR)/utils/utils_envp.c \
		$(SRC_DIR)/utils/utils_redir.c \
		$(SRC_DIR)/utils/utils_mini.c \
		$(SRC_DIR)/utils/utils_cmd.c \
		$(SRC_DIR)/heredoc.c \
		$(SRC_DIR)/debug/debug_tokens.c \
		$(SRC_DIR)/debug/debug_cmd.c \
		$(SRC_DIR)/parser.c

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# --------------------------------------------------------------
# 👇 Regla principal
# --------------------------------------------------------------
all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_UTILS_DIR)
	@mkdir -p $(OBJ_DEBUG_DIR)

$(NAME): $(OBJ)
	@$(MAKE) -C Libft > /dev/null
	@$(MAKE) -C pipex > /dev/null
	@$(MAKE) -C Lexer > /dev/null
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(PIPEX) $(LEXER) $(LIBFT) -lreadline -o $(NAME)
	@echo "✅ Proyecto compilado correctamente."

# --------------------------------------------------------------
# 🛠 Compilar cada archivo fuente
# --------------------------------------------------------------
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ > /dev/null
	@echo "🔧 Compilado: $<"

# --------------------------------------------------------------
# 🧹 Limpieza
# --------------------------------------------------------------

clean:
	@rm -rf $(OBJ_DIR) > /dev/null
	@$(MAKE) -C Libft clean > /dev/null
	@$(MAKE) -C pipex clean > /dev/null
	@$(MAKE) -C Lexer clean > /dev/null
	@echo "🧹 Archivos objeto y temporales eliminados."

fclean: clean
	@rm -f $(NAME) > /dev/null
	@$(MAKE) -C Libft fclean > /dev/null
	@$(MAKE) -C pipex fclean > /dev/null
	@$(MAKE) -C Lexer fclean > /dev/null
	@echo "🧼 Todo limpio."

re: fclean all

.PHONY: all clean fclean re Libft pipex Lexer