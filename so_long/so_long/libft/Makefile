LIBFT		= libft
N_TEMP		= temp.a
NAME		= libft.a
CC			= gcc
CFLAGS		= -c -Wall -Wextra -Werror
INCLUDES	= -I ./includes
RM			= rm -rf
AR			= ar rcs
SRCS		= ft_printf.c \
			./srcs/ft_sp_c.c \
			./srcs/ft_sp_id.c \
			./srcs/ft_sp_p.c \
			./srcs/ft_sp_s.c \
			./srcs/ft_sp_u.c \
			./srcs/ft_sp_x.c

OBJS = $(SRCS:.c=.o)

NONE =		'\033[0m'
GREEN =		'\033[32m'
GRAY =		'\033[2;37m'
CURSIVE =	'\033[3m'

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@echo $(CURSIVE)$(GRAY) "Compiling $(NAME)" $(NONE)
	@$(AR) $(NAME) $(OBJS)
	@echo $(GREEN)"Compiled"$(NONE)
	@rm $(OBJ)
	@echo $(CURSIVE)$(GRAY) "Deleted object files" $(NONE)

clean:
	@echo $(CURSIVE)$(GRAY) "Removing $(OBJ)" $(NONE)
	@$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "$(NAME) Removed" $(NONE)
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re