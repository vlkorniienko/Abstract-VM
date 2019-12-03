CC=g++
FLAGS=-Wall -Wextra -Werror -std=c++11 #-fsanitize=address
SRCS=main.cpp Lexer.cpp Reader.cpp Parser.cpp Factory.cpp Operand.cpp
OFILES = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

SRC_DIR = ./src/
OBJ_DIR = ./objects/

NAME=avm

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) -o $(NAME) $(OFILES) -I ./inc
	@tput setaf 2; echo made

$(OFILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) -c $< -o $@ $(FLAGS) -I ./inc 

clean:
	rm -r $(OFILES)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all
