#include "AST.hpp"
#include "buffer.hpp"
#include "error.hpp"
#include "lexer.hpp"
#include <vector>

namespace lang::parser {
class Parser {
public:
  AST::BlockPtr result;
  bool success;
  Error error;

  Parser(std::vector<lexer::Token> _source);
  std::string repr() const;
  friend std::ostream &operator<<(std::ostream &os, const Parser &obj);

private:
  AST::NodePtr parse_block();
  AST::NodePtr parse_identifier();
  void parse();
  Buffer<lexer::Token> source;
};
} // namespace lang::parser
