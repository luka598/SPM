#include <string>
#include <vector>
#include "tokens.hpp"
#include "lexemes.hpp"
#include "tokenizer.hpp"

using namespace lang;
namespace lang::lexer{
	class Lexer {
		public:
			Lexer(std::vector<tokenizer::Token> _tokens);
			std::vector<Lexeme> lexemes;
		private:
			std::vector<tokenizer::Token> tokens;
			std::vector<tokenizer::Token> buffer;
			void tokenize();
	};
}
