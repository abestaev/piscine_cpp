CFLAGS = -Werror -Wall -Wextra -std=c++98
CC = c++
SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)

NAME = Harl

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re	