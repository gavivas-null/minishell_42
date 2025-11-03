NAME = libexec.a

AR = ar
ARFLAG = -rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../include

SRCS =	exec/exec_core.c \
		exec/exec_errors.c \
		exec/exec_handle.c \
		exec/exec_io.c \
		exec/exec_path.c \
		exec/exec_pipeline.c \

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
	@echo "🧹 exec: objetos eliminados."

fclean: clean
	@rm -f $(NAME)
	@echo "🗑️ exec: lib eliminada."

re: fclean all

.PHONY: all clean fclean re