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

bool Lexer::RegularRes(std::vector<std::string> lines) {

}