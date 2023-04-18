// #include "interpreter.hpp"
// #include "smrt.hpp"
// #include <vector>
//
// /*
//  - Interpreter
// public:
// 	AST::BlockPtr result;
// 	bool success;
// 	Error error;
//
// 	Interpreter(AST::BlockPtr _source);
// 	std::string repr() const;
// 	friend std::ostream &operator<<(std::ostream &os, const Interpreter &obj);
//
// private:
// 	void interpret();
// 	inline void eval() {return interpret();};
// 	AST::BlockPtr source;
// */
//
// namespace lang::interpreter {
// 	Interpreter::Interpreter(AST::BlockPtr _source)
// 	: result(smrt::make<AST::Block>(std::vector<AST::NodePtr>())),
// 	success(true),
// 	error(lang::Error({""})),
// 	source(_source)
// 	{
// 		interpret();
// 	};
//
// 	// AST::BlockPtr Interpreter::interpret_block(AST::BlockPtr block){
// 	// 	auto local_result = smrt::make<AST::Block>(std::vector<AST::NodePtr>());
// 	// 	for(auto node : block->nodes){
// 	// 		switch(node->type()){
// 	// 			case AST::NodeType::FCALL: 
// 	// 				// Call function
// 	// 				local_result->nodes.push_back(smrt::make_as<AST::Node, AST::IntegerLiteral>(0));
// 	// 				break;
// 	// 			case AST::NodeType::BLOCK:
// 	// 				local_result->nodes.push_back(interpret_block(node.as<AST::Block>()).as<AST::Node>());
// 	// 				break;
// 	// 			case AST::NodeType::IDENTIFIER:
// 	// 				// Resolve identifier
// 	// 				break;
// 	// 			case AST::NodeType::LITERAL:
// 	// 				//
// 	// 				break;
// 	// 		}
// 	// 	}
// 	// 	return local_result;
// 	// }
//
// 	void Interpreter::interpret(){
// 		result = interpret_block(source);
// 	}
// }
