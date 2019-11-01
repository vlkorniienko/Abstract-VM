#include "Reader.hpp"

std::vector<std::string> Reader::getCommands() const { 
	return this->commands;
}

void Reader::readFromFile(const std::string argument1) {
	std::ifstream arg;
	arg.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		arg.open(argument1);
		std::string line;
		while (!arg.eof()) {
			getline(arg, line);
			this->commands.push_back(line.c_str());
		}
		arg.close();
	} catch (const std::ifstream::failure& e) {
    	std::cerr << "Exception opening/reading/closing file\n";
	}
}

void Reader::readFromStdin() {

	for (std::string line; std::getline(std::cin, line);) {
		if (line == ";;") {
			break;
		}
		this->commands.push_back(line.c_str());
	}
}