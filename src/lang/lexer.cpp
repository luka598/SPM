#include <string>
#include <vector>
#include <vector>
#include "tokens.hpp"
#include "lexemes.hpp"
#include "lexer.hpp"
#include "tokenizer.hpp"

using namespace lang;
namespace lang::lexer{
	Lexer::Lexer(std::vector<tokenizer::Token> _tokens) : tokens(_tokens){
		tokenize();
	};

	void Lexer::tokenize(){
		for (auto &t : tokens){
			buffer.push_back(t);
		}
	}
};

