#include "error.hpp"
#include <string>
#include <vector>
#define SMRT_DEBUG
#include "smrt.hpp"

#include "data.hpp"

#define PTR(x) using x##Ptr = smrt::Ptr<x>

namespace lang::AST {
enum NodeType {
  FCALL,
  BLOCK,
  IDENTIFIER,
  LITERAL,
};

// -----------------
// | Base AST node |
// -----------------
class Node : public smrt::Base, public ErrorBase {
public:
  inline virtual NodeType type() = 0;
  virtual std::string repr() const = 0;
};
PTR(Node);

// ---------------------
// | Literal AST types |
// ---------------------
class LiteralBase : public Node {
public:
  NodeType type() override { return NodeType::LITERAL; }
  virtual data::Type dataType() = 0;
};
PTR(LiteralBase);
class StringLiteral : public LiteralBase {
public:
  data::Type dataType() override { return data::Type::STRING; };
  data::String value;
  StringLiteral(std::string _value);
  std::string repr() const override;
};
PTR(StringLiteral);
class IntegerLiteral : public LiteralBase {
public:
  data::Type dataType() override { return data::Type::INTEGER; };
  data::Integer value;
  IntegerLiteral(std::string _value);
  std::string repr() const override;
};
PTR(IntegerLiteral);

// -----------------------
// | Identifier AST type |
// -----------------------
class Identifier : public Node {
public:
  NodeType type() override { return NodeType::IDENTIFIER; }
  data::String value;
  Identifier(std::string _value);
  std::string repr() const override;
};
PTR(Identifier);

// ------------------
// | Block AST type |
// ------------------
class Block : public Node {
public:
  NodeType type() override { return NodeType::BLOCK; }
  std::vector<NodePtr> nodes;
  Block(std::vector<NodePtr> _nodes);
  std::string repr() const override;
};
PTR(Block);

// ------------------
// | FCall AST type |
// ------------------
class FCall : public Node {
public:
  NodeType type() override { return NodeType::FCALL; }
  smrt::Ptr<Identifier> name;
  BlockPtr parameters;
  FCall(IdentifierPtr _name, BlockPtr _parameters);
  std::string repr() const override;
};
} // namespace lang::AST
