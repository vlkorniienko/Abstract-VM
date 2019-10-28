#include <vector>
#include <string>
#include "Lexer.hpp"
#include "Reader.hpp"

int		main(int argc, char **argv)
{
	Reader reader;
	Lexer lexer;
	std::vector<std::string> lines;
	std::vector<std::string> newlines;

	if (argc == 2)
		reader.readFromFile(argv[1]);
	else if (argc == 1)
		reader.readFromStdin();
	else
		std::cout << "Error: too many arguments" << std::endl;

	lines = reader.getCommands();
	lexer.RegularResult(lines);
	
	return (0);
}