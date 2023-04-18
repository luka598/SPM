#include "AST.hpp"
#include <sstream>

namespace lang::AST {
// ---------------------
// | Literal AST types |
// ---------------------
StringLiteral::StringLiteral(std::string _value) : value(_value) {
	error << value.error;
}
std::string StringLiteral::repr() const {
  std::stringstream ss;
  ss << "StrinLiteral{ " << value << " }";
  return ss.str();
}
IntegerLiteral::IntegerLiteral(std::string _value) : value(_value) {
	error << value.error;
}
std::string IntegerLiteral::repr() const {
  std::stringstream ss;
  ss << "IntegerLiteral{ " << value << " }";
  return ss.str();
}

// -----------------------
// | Identifier AST type |
// -----------------------
Identifier::Identifier(std::string _value) : value(_value) {}
std::string Identifier::repr() const {
  std::stringstream ss;
  ss << "Identifier{ " << value << " }";
  return ss.str();
}
// ------------------
// | Block AST type |
// ------------------
Block::Block(std::vector<NodePtr> _nodes) : nodes(_nodes) {}
std::string Block::repr() const {
  std::stringstream ss;
  ss << "Block"
     << "[" << nodes.size() << "]"
     << "{";
  for (auto node : nodes) {
    switch (node->type()) {
    case NodeType::FCALL:
      ss << node.as<FCall>()->repr();
      break;
    case NodeType::BLOCK:
      ss << node.as<Block>()->repr();
      break;
    case NodeType::IDENTIFIER:
      ss << node.as<Identifier>()->repr();
      break;
    case NodeType::LITERAL:
      switch (node.as<LiteralBase>()->dataType()) {
      case data::STRING:
        ss << node.as<StringLiteral>()->repr();
        break;
      case data::INTEGER:
        ss << node.as<IntegerLiteral>()->repr();
        break;
      }
    }
  }
  ss << " }";
  return ss.str();
}

// ------------------
// | FCall AST type |
// ------------------
FCall::FCall(IdentifierPtr _name, BlockPtr _parameters)
    : name(_name), parameters(_parameters) {}
std::string FCall::repr() const {
  std::stringstream ss;
  ss << "FCall{ " << name->repr() << ", " << parameters->repr() << " }";
  return ss.str();
}
} // namespace lang::AST
