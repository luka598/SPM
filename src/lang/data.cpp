#include "data.hpp"
#include <string>

namespace lang::data {
	Integer::Integer(int _value) : value(_value) {};
	Integer::Integer(std::string _value) {
		// TODO: Check for errors
		std::stoi(_value);
	};
	std::ostream & operator<<(std::ostream &os, const Integer &obj){
		os << "Integer" << obj.error << "{" << obj.value << "}";
		return os;
	}

	String::String(std::string _value) : value(_value) {};
	std::ostream & operator<<(std::ostream &os, const String &obj){
		os << "String" << obj.error << "{" << obj.value << "}";
		return os;
	}
}
