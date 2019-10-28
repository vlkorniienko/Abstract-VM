#include <vector>
#include <string>
#include "Lexer.hpp"
#include "Reader.hpp"

int		main(int argc, char **argv)
{
	Reader reader;
	Lexer lexer;
	std::vector<std::string> lines;

	if (argc == 2)
		reader.readFromFile(argv[1]);
	else if (argc == 1)
		reader.readFromStdin();
	else {
		std::cout << "Usage error: too many arguments" << std::endl;
		return (-1);
	}

	//lines = reader.getCommands();
	lexer.RegularResult(reader.getCommands());
	
	return (0);
}