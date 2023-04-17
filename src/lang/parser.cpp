#include "error.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
// #define NDEBUG
#include <cassert>

#define SMRT_DEBUG
#include "lexer.hpp"
#include "parser.hpp"
#include "smrt.hpp"

/*
   class Parser{
   public:
   AST::Block result;
   bool success;
   Error error;

   Parser(std::vector<lexer::Token> _source);
   std::string repr() const;
   friend std::ostream& operator<<(std::ostream& os, const Parser& obj);
   private:
   void parse();
   Buffer<lexer::Token> source;
   };
   */

namespace lang::parser {
Parser::Parser(std::vector<lexer::Token> _source)
    : result(smrt::make<AST::Block>(std::vector<AST::NodePtr>())),
      success(true), error(Error({""})), source(_source) {
  parse();
}

AST::NodePtr Parser::parse_identifier() {
  AST::IdentifierPtr i = smrt::make<AST::Identifier>(source.at().value);
  if (source.canPeek(1) && success) {
    switch (source.peek().type) {
    case lexer::TokenType::IGNORE: {
      return i.as<AST::Node>();
      break;
    }
    case lexer::TokenType::BLOCK_OPEN: {
      source.advance();
      AST::BlockPtr b = parse_block().as<AST::Block>();
      return smrt::make_as<AST::Node, AST::FCall>(i, b);
      break;
    }
    default: {
      std::stringstream ss;
      ss << "Unexpected token at " << source.getIndex() << ": "
         << source.at().repr();
      // throw std::runtime_error(ss.str());
      success = false;
      error = Error{ss.str()};
      return i.as<AST::Node>();
    }
    }
  }
  return i.as<AST::Node>();
}

AST::NodePtr Parser::parse_block() {
  lexer::Token token = source.at();
  source.advance();
  AST::BlockPtr b = smrt::make<AST::Block>(std::vector<AST::NodePtr>());
  while (!source.end() && success) {
    token = source.at();
    switch (token.type) {
    case lexer::TokenType::IGNORE:
      source.advance();
      break;
    case lexer::TokenType::BLOCK_OPEN:
      b->nodes.push_back(parse_block());
      source.advance();
      break;
    case lexer::TokenType::BLOCK_CLOSE:
      return b.as<AST::Node>();
      break;
    case lexer::TokenType::IDENTIFIER:
      b->nodes.push_back(parse_identifier());
      break;
    case lexer::TokenType::STRING:
      b->nodes.push_back(
          smrt::make_as<AST::Node, AST::StringLiteral>(token.value));
      source.advance();
      break;
    case lexer::TokenType::INTEGER:
      b->nodes.push_back(smrt::make_as<AST::Node, AST::IntegerLiteral>(
          std::stoi(token.value)));
      source.advance();
      break;
    default:;
    }
  }
  std::stringstream ss;
  ss << "Unclosed-block at position " << source.getIndex() << ": "
     << source.at().repr();
  // throw std::runtime_error(ss.str());
  success = false;
  error = Error{ss.str()};
  return b.as<AST::Node>();
}

void Parser::parse() {
  while (!source.end() && success) {
    lexer::Token token = source.at();
    switch (token.type) {
    case lexer::TokenType::IGNORE:
      source.advance();
      break;
    case lexer::TokenType::BLOCK_OPEN:
      result->nodes.push_back(parse_block());
      source.advance();
      break;
    case lexer::TokenType::IDENTIFIER:
      result->nodes.push_back(parse_identifier());
      source.advance();
      break;
    default:
      std::stringstream ss;
      ss << "Invalid token at position " << source.getIndex() << ": "
         << source.at().repr();
      success = false;
      error = Error{ss.str()};
      return;
    }
  }
}

std::string Parser::repr() const {
  std::stringstream ss;
  ss << "Parser";
  if (!success) {
    ss << "!(" << error.message << ")";
  }
  ss << "{" << result->repr() << " }";
  return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Parser &obj) {
  os << obj.repr();
  return os;
}
} // namespace lang::parser
