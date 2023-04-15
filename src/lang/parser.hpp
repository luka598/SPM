#include <vector>
#include "buffer.hpp"
#include "lexer.hpp"
#include "error.hpp"

namespace lang::parser {
	class Parser{
		public:
			Parser(std::vector<lexer::Token> tokens);
			bool success;
			Error error;
		private:
			void parse();
			Buffer<lexer::Token> buffer;
	};
}
