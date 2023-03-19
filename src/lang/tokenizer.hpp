#pragma once

#include <string>
#include <vector>
#include "tokens.hpp"

namespace lang::tokenizer{
	class Tokenizer{
		public:
			Tokenizer(std::string s);
			std::vector<Token> tokens;
		private:
			std::string input;
			std::string buffer="";
			void tokenize();
	};
}
using namespace lang::tokenizer;

std::ostream& operator<< (std::ostream &out, Tokenizer const& t);
