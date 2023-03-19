#pragma once

#include <string>
#include <vector>
#include <map>
#include "tokens.hpp"

namespace lang::lexer {
	enum LexemeType {
		SEPARATOR,
		STRING,
		FUNCTION,
		BLOCK,
	};

	const std::map<LexemeType, std::string> LexemeTypeName = {
		{SEPARATOR, "Separator"},
		{STRING, "String"},
		{FUNCTION, "Function"},
		{BLOCK, "Block"},
	};

	struct Lexeme{
		LexemeType type;
		std::vector<tokenizer::Token> tokenizer_tokens;
	};
}
using namespace lang;
