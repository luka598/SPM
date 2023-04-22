#define SMRT_DEBUG
#include "lang/lexer.hpp"
#include "lang/parser.hpp"
#include <ios>
#include <iostream>
#include <string>

using namespace std;

int main() {
  cout << boolalpha;
  string s = R"(print("Hello world"))";
  auto lexer = lang::lexer::Lexer(s);
  cout << lexer << " - " << lexer.error << endl;
  auto parser = lang::parser::Parser(lexer.result);
  cout << parser;
  return 0;
}
