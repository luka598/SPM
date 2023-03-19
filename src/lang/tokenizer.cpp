#include <string>
#include <vector>
#include "tokens.hpp"
#include "tokenizer.hpp"
using namespace lang;

namespace lang::tokenizer{
		Tokenizer::Tokenizer(std::string s) : input(s) {
				tokenize();
		}
		void Tokenizer::tokenize(){
				for (size_t i=0; i < input.size(); i++){
					buffer.push_back(input.at(i));
					for (auto const &t : Tokens){
						if (t.type == TokenType::DATA) continue;
						if (buffer.find(t.value) != std::string::npos){
							// cout << "Found" << i << " " << 
							size_t delta = buffer.size() - t.value.size(); 
							if (delta)
								tokens.push_back(Token{TokenType::DATA, buffer.substr(0, delta)});
							tokens.push_back(t);
							buffer.clear();
						}
					}
				}
				if (!buffer.empty()) tokens.push_back(Token{TokenType::DATA, buffer});;
			}
}
using namespace lang::tokenizer;

std::ostream& operator<< (std::ostream &out, Tokenizer const& t) {
	out << std::string("Tokenizer { ");
	for (auto &tkn : t.tokens){
		out << std::string("{ ") << TokenTypeName.at(tkn.type);
		if (tkn.type == TokenType::DATA)
			out << std::string(", \"") << tkn.value << std::string("\"");
		out <<  std::string(" } ");
	}
	out << std::string("}");
	return out;
}
