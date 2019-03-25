#include "Lexer.hpp"

typedef enum {
    push,
    pop,
    dump,
    assert,
    add,
    sub,
    mul,
    div,
    mod,
    print,
    exit
} instructions;

Lexer::Lexer() {
    this->result = false;
}

bool Lexer::RegularResult(std::vector<std::string> line) {
    
    return this->result;
}