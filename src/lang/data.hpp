#include <string>
#include "error.hpp"
#include "smrt.hpp"

#define PTR(x) using x##Ptr = smrt::Ptr<x>

namespace lang::data {
	enum Type {
	  INTEGER,
	  STRING,
	};

	class Data : public smrt::Base, public ErrorBase{
		virtual Type type() = 0;
	};
	PTR(Data);

	class Integer : public Data {
		public:
			inline Type type() override {return Type::INTEGER;};
			int value;
			friend std::ostream & operator<<(std::ostream &os, const Integer &obj);
			Integer(int _value);
			Integer(std::string _value);
	};
	PTR(Integer);

	class String : public Data {
		public:
			inline Type type() override {return Type::STRING;};
			std::string value;
			friend std::ostream & operator<<(std::ostream &os, const String &obj);
			String(std::string _value);
	};
	PTR(String);
}
