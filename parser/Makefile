NAME = parser.a

CC = cc
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra -g

SRCS = src/cmd_utils.c \
		src/free.c \
		src/handlers.c \
		src/parser_utils.c \
		src/parser.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I include -I ../Libft

#-----------------------------------------------------------
# Principal
#-----------------------------------------------------------
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "📦 Librería $(NAME) creada correctamente."

#-----------------------------------------------------------
# Compilar archivos fuente
#-----------------------------------------------------------
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "🔧 Compilado: $<"

#-----------------------------------------------------------
# Limpiar archivos
#-----------------------------------------------------------
clean:
	@rm -f $(OBJS)
	@echo "🧹 Archivos objeto eliminados."

fclean: clean
	@rm -f $(NAME)
	@echo "🧼 Todo limpio."

re: fclean all

.PHONY: all clean fclean re
