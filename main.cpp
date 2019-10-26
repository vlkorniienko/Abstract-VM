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
	else
		std::cout << "Error: too many arguments" << std::endl;

	lines = reader.getCommands();
	for (int i = 0; i < lines.size(); ++i) {
		std::cout << lines[i] << std::endl;
	}
	return (0);
}