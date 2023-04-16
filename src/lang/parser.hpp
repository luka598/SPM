#include <vector>
#include "AST.hpp"
#include "buffer.hpp"
#include "lexer.hpp"
#include "error.hpp"

namespace lang::parser {
	class Parser{
		public:
			AST::BlockPtr result;
			bool success;
			Error error;

			Parser(std::vector<lexer::Token> _source);
			std::string repr() const;
			friend std::ostream& operator<<(std::ostream& os, const Parser& obj);
		private:
			AST::NodePtr parse_block();
			AST::NodePtr parse_identifier();
			void parse();
			Buffer<lexer::Token> source;
	};
}
