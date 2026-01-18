NAME = lexer.a

CC = cc
AR = ar rcs
CFLAGS = -Wall -Werror -Wextra -g

SRCS = src/crud.c \
       src/free.c \
       src/operators_utils.c \
       src/segments_utils.c \
       src/words_utils.c \
       src/states/handle_dquote_state.c \
       src/states/handle_squote_state.c \
       src/states/handle_normal_state.c \
       src/states/state_machine.c

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
