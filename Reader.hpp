#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Reader {
public:
    Reader() = default;
    ~Reader() = default;
    void readFromFile(const std::string);
    void readFromStdin();
    std::vector<std::string> getCommands() const;

private:
    std::vector<std::string> commands;
};