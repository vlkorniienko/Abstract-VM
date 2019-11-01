CC=g++
FLAGS=-Wall -Wextra -Werror
SRCS=main.cpp Lexer.cpp Reader.cpp MyException.cpp
OFILES = $(SRCS:.cpp=.o)

NAME=avm

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) -o $(NAME) $(OFILES)

%.o: %.cpp
	$(CC) -c $< -o $@ $(FLAGS) -I. 

clean:
	rm -r $(OFILES) $(NAME)