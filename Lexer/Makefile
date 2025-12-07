NAME = liblexer.a

AR = ar
ARFLAG = -rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../Lexer -I ../Libft

SRCS =	crud.c \
		free.c \
		operators_utils.c \
		words_utils.c \
		handle_dquote_state.c \
		handle_normal_state.c \
		handle_squote_state.c \
		state_machine.c \

OBJS = $(SRCS:.c=.o)

# --------------------------------------------------------------
# 👇 Regla principal
# --------------------------------------------------------------
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(ARFLAG) $(NAME) $(OBJS)
	@echo "📦 Librería creada: $(NAME)"

# --------------------------------------------------------------
# 🛠 Compilar cada archivo fuente
# --------------------------------------------------------------
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "🔧 Compilado: $<"

# --------------------------------------------------------------
# 🧹 Limpieza
# --------------------------------------------------------------
clean:
	@rm -f $(OBJS)
	@echo "🧹 lexer: objetos eliminados."

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️ lexer: lib eliminada."

re: fclean all

.PHONY: all clean fclean re