CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS := main.c ft_putstr.c error.c ft_cat.c
OBJ := $(SRCS:.c=.o)
RM = rm -f
NAME = cat_it

.PHONY:all clean fclean re

all:$(NAME)
$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
clean :
	@$(RM) $(OBJ)
fclean : clean
	@$(RM) $(NAME)
re : fclean all