#include <vector>
#include <sstream>
//#define NDEBUG
#include <cassert>
#include "buffer.hpp"
#include "error.hpp"
#include "lexer.hpp"

#include "parser.hpp"

namespace lang::parser {

	Parser::Parser(std::vector<lexer::Token> _tokens)
		: success(true), error(Error{""}), buffer(_tokens)
	{
		parse();
	}

	void Parser::parse(){
		
	}
}
