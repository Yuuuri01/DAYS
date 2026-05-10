CC = gcc
FLAGS = -Wall -Wextra -Werror
SRCS := display_file.c error.c main.c
OBJ := $(SRCS:.c=.o)
RM = rm -f
NAME = program

.PHONY: all clean fclean re

all: $(NAME)
$(NAME): $(OBJ)
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)
re: fclean all