#pragma once

#include <string>
#include <vector>
#include <map>

namespace lang::tokenizer{
	enum TokenType {
		DATA,
		SPACE,
		TAB,
		NEWLINE,
		L_BRACKET,
		R_BRACKET,
		L_C_BRACKET,
		R_C_BRACKET
	};

	const std::map<TokenType, std::string> TokenTypeName = {
		{DATA, "Data"},
		{SPACE, "Space"},
		{TAB, "Tab"},
		{NEWLINE, "Newline"},
		{L_BRACKET, "Left bracket"},
		{R_BRACKET, "Right bracket"},
		{L_C_BRACKET, "Left curly bracket"},
		{R_C_BRACKET, "Right curly bracket"},
	};

	struct Token{
		TokenType type;
		std::string value;
	};

	const std::vector<Token> Tokens = {
		Token{TokenType::DATA, ""},
		Token{TokenType::SPACE, " "},
		Token{TokenType::TAB, "	"},
		Token{TokenType::NEWLINE, "\n"},
		Token{TokenType::L_BRACKET, "("},
		Token{TokenType::R_BRACKET, ")"},
		Token{TokenType::L_C_BRACKET, "{"},
		Token{TokenType::R_C_BRACKET, "}"},
	};
}
