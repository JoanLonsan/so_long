NAME =		so_long
LIBFT =		libft
CFLAGS =	-Wall -Wextra -Werror
SRC =		so_long.c ¿?.c
OBJ = 		$(SRC:.c=.o)
LINKS =		-lmlx -framework OpenGL -framework AppKit
INCLUDES =	-I ./includes

NONE =		'\033[0m'
GREEN =		'\033[32m'
GRAY =		'\033[2;37m'
CURSIVE =	'\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@echo $(CURSIVE)$(GRAY) "Compiling $(NAME)" $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)
	@echo $(GREEN)"Compiled"$(NONE)
	@rm $(OBJ)
	@echo $(CURSIVE)$(GRAY) "Deleted object files" $(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "Making $(OBJ)" $(NONE)
	@gcc $(FLAGS) -c $(SRC)

exe: all
	@echo "Executing $(NAME)\n"
	@./$(NAME)
	@echo $(GREEN)"Done"$(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) "Removing $(OBJ)" $(NONE)
	@rm -rf $(OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "$(NAME) Removed" $(NONE)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all exe clean fclean re
