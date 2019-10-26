#include "Reader.hpp"

Reader::Reader() {}
Reader::~Reader() {}

std::vector<std::string> Reader::getCommands() const { 
    return this->commands;
}

void Reader::readFromFile(const std::string argument1) {
    std::ifstream arg(argument1);

    if (arg.is_open()) {
		std::string line;
		while (getline(arg, line)) {
			this->commands.push_back(line.c_str());
		}
	}
	arg.close();
}

void Reader::readFromStdin() {

	for (std::string line; std::getline(std::cin, line);) {
		if (line == ";;") {
			break;
		}
		this->commands.push_back(line.c_str());
	}
}