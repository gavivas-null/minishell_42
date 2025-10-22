NAME = minishell

CC = cc
CFLAGS = -Wall -Werror -Wextra 
INCLUDES = -I include

SRC_DIR = src
OBJ_DIR = obj
TMP_DIR = tmp
SRC = $(SRC_DIR)/minishell.c \

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# --------------------------------------------------------------
# 👇 Regla principal
# --------------------------------------------------------------
all: $(OBJ_DIR) $(TMP_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(TMP_DIR):
	@mkdir -p $(TMP_DIR)
	@touch $(TMP_DIR)/minishell_history

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -lreadline -o $(NAME)
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
	@rm -rf $(TMP_DIR) > /dev/null
	@echo "🧹 Archivos objeto y temporales eliminados."

fclean: clean
	@rm -f $(NAME) > /dev/null
	@echo "🧼 Todo limpio."

re: fclean all

.PHONY: all clean fclean re