#include "lang/lexer.hpp"
#include <ios>
#include <iostream>
#include <string>

using namespace std;

int main(){
	cout << boolalpha;
	string s = R"(print("Hello world"))";
	auto lexer = lang::lexer::Lexer(s);
	cout << lexer << " - " << lexer.success << " - " << lexer.error.message << endl; 
	return 0;
}
