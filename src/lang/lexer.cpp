#include <regex>
#include <string>
#include <vector>
#include <sstream>
//#define NDEBUG
#include <cassert>
#include "buffer.hpp"
#include "lexer.hpp"
#include "error.hpp"

namespace lang::lexer {
	std::string Token::repr() const {
		std::stringstream ss;
		ss << "Token{ " << type << ", " << value << " }";
		return ss.str();
	};

	Lexer::Lexer(std::string _source)
		: success(true), error({""}), source(_source){
		lex();
	}
	
	void Lexer::lex(){
		size_t pos = 0;
		while (pos < source.size()){	
			bool found = false;
			std::smatch match;
			std::string source_substr = source.substr(pos);
			for (auto token : TokenRegex){	
				if (std::regex_search(source_substr, match, token.re)){
					if (token.type != TokenType::IGNORE)
						result.push_back(Token{token.type, match.str(0)});
					pos += match.length(0);
					assert(match.length(0) > 0 && "match.length(0) <= 0, There is error posibly in regex definitions");
					found = true;
					break;
				}
			}
			if (!found){
				std::stringstream ss;
				ss << "Invalid token at position " << pos << ": " << source[pos];
				throw std::runtime_error(ss.str());
				success = false;
				error = Error{ss.str()};
				return;
			}
		}
		return;
	}

	std::string Lexer::repr() const {
		std::stringstream ss;
		ss << "Lexer{ ";
		for (auto token : result){
			ss << token.repr() << " ";
		}
		ss << "}";
		return ss.str();
	};

	std::ostream& operator<<(std::ostream& os, const Lexer& obj){	
		return os << obj.repr();
	}
}
