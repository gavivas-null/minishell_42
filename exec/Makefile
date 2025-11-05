NAME = libexec.a

AR = ar
ARFLAG = -rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../include -I ../Libft
LIBFT = ../Libft/libft.a


SRCS =	exec_core.c \
		exec_errors.c \
		exec_handle.c \
		exec_io.c \
		exec_path.c \
		exec_pipeline.c \

OBJS = $(SRCS:.c=.o)

# --------------------------------------------------------------
# 👇 Regla principal
# --------------------------------------------------------------
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ../Libft > /dev/null
	@$(AR) $(ARFLAG) $(NAME) $(LIBFT) $(OBJS)
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
	@$(MAKE) -C ../Libft fclean > /dev/null
	@echo "🧹 exec: objetos eliminados."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C ../Libft fclean > /dev/null
	@echo "🗑️ exec: lib eliminada."

re: fclean all

.PHONY: all clean fclean re libft