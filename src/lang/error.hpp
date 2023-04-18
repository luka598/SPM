#pragma once
#include <ostream>
#include <sstream>
#include <string>
// #define ERROR_FATAL // Throws runtime error when error is raised

namespace lang {
	class END;

	class Error {
		public:
			bool thrown = false;
			
			std::string message() const;
			operator bool() const;
			template<typename T>
				friend Error & operator<<(Error &obj, const T &value);
			friend Error & operator<<(Error &obj, const END &_);
			friend Error & operator<<(Error &obj, const Error &e);
			friend std::ostream & operator<<(std::ostream &os, const Error &obj);
			Error();

		private:
			std::stringstream ss;
	};

	class ErrorBase {
		public:
			Error error;
	};
} // namespace lang
