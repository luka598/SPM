#include "AST.hpp"
#include "error.hpp"
#include "data.hpp"
#include <unordered_map>
#include <vector>

namespace lang::interpreter {
class Interpreter {
public:
  AST::BlockPtr result;
  bool success;
  Error error;

  Interpreter(AST::BlockPtr _source);
  std::string repr() const;
  friend std::ostream &operator<<(std::ostream &os, const Interpreter &obj);

private:
  AST::BlockPtr interpret_block(AST::BlockPtr block);
  void interpret();
  std::unordered_map<std::string, data::DataPtr> vars;
  AST::BlockPtr source;
};
} // namespace lang::interpreter
