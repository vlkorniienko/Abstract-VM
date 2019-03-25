#include <iostream>
#include <fstream>
#include <vector>
#include <string>

typedef enum {
	Int8,
	Int16,
	Int32,
	Float,
	Double
} operand;

void	readFromStdin()
{
	std::vector<std::string> lines;

	for (std::string line; std::getline(std::cin, line);) {
		if (line == ";;") {
			break ;
		}
		lines.push_back(line.c_str());
	}
	// for (int i = 0; i < lines.size(); ++i) {
	// 	std::cout << lines[i] << std::endl;
	// }
}

void readFromFile(std::string argv)
{
	std::ifstream argument(argv);
	std::vector<std::string> lines;

	if (argument.is_open()) {
		std::string line;
		while (getline(argument, line)) {
			lines.push_back(line.c_str());
		}
	}
	argument.close();
	for (int i = 0; i < lines.size(); ++i) {
		std::cout << lines[i] << std::endl;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2) {
		readFromFile(argv[1]);
	}
	else if (argc == 1) {
		readFromStdin();
	}
	else {
		std::cout << "Too many arguments" << std::endl;
	}
	return (0);
}