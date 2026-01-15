NAME = parser.a

AR = ar
ARFLAG = -rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I include -I ../Libft

SRCS = 

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
	@echo "🧹 parser: objetos eliminados."

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️ parser: lib eliminada."

re: fclean all

.PHONY: all clean fclean re