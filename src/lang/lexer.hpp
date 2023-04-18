#pragma once
#include "error.hpp"
#include <regex>
#include <string>
#include <vector>

namespace lang::lexer {
enum TokenType {
  IGNORE,
  IDENTIFIER,
  BLOCK_OPEN,
  BLOCK_CLOSE,
  STRING,
  INTEGER,
};

struct TokenRe {
  TokenType type;
  std::regex re;
};

struct Token {
  TokenType type;
  std::string value;
  std::string repr() const;
};

const std::vector<TokenRe> TokenRegex = {
    {TokenType::IGNORE, std::regex(R"#(^\s)#")},
    {TokenType::IDENTIFIER, std::regex(R"#(^[a-zA-Z][a-zA-Z0-9_]*)#")},
    {TokenType::BLOCK_OPEN, std::regex(R"#(^[\(\[\{])#")},
    {TokenType::BLOCK_CLOSE, std::regex(R"#(^[\)\]\}])#")},
    {TokenType::STRING, std::regex(R"#(^"[^"]*")#")},
    {TokenType::INTEGER, std::regex(R"#(^[0-9]+)#")},
};

class Lexer : public ErrorBase {
public:
  std::vector<Token> result;

  Lexer(std::string _source);
  std::string repr() const;
  friend std::ostream &operator<<(std::ostream &os, const Lexer &obj);

private:
  void lex();
  std::string source;
};
} // namespace lang::lexer
