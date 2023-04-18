#include "AST.hpp"
#include "error.hpp"
#include <vector>
#include <map>

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
inline void eval() {return interpret();};
// TODO: this should map either AST::Identifier to AST::Literal
// or as I would prefer it type::String to type::*
std::map<std::string, AST::LiteralBasePtr> vars;
AST::BlockPtr source;
};
} // namespace lang::parser
