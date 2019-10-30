#include <vector>
#include <string>
#include "Lexer.hpp"
#include "Reader.hpp"

int		main(int argc, char **argv)
{
	Reader 	reader;
	Lexer 	lexer;

	if (argc == 2)
		reader.readFromFile(argv[1]);
	else if (argc == 1)
		reader.readFromStdin();
	else {
		std::cout << "Usage error: too many arguments" << std::endl;
		std::cout << "./avm [filename]" << std::endl;
		return (-1);
	}
	lexer.RegularResult(reader.getCommands());
	
	return (0);
}