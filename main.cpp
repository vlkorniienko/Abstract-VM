#include <vector>
#include <string>
#include "Lexer.hpp"
#include "Reader.hpp"

int		main(int argc, char **argv)
{
	Reader 	reader;
	Lexer 	lexer;

	try {
		if (argc == 2)
			reader.readFromFile(argv[1]);
		else if (argc == 1)
			reader.readFromStdin();
		else {
			throw MyException("Usage error: too many arguments\n./avm [filename]");
		}
	} catch(MyException &e) {
		std::cout << e.getMessage() << std::endl;
		return (-1);
	}
	lexer.RegularResult(reader.getCommands());
	
	return (0);
}