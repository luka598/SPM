#include <iostream>
#include <string>
#include "lang/tokenizer.hpp"
#include "lang/lexer.hpp"

using namespace std;

int main(){
	string s = "dfjgh(){set(x) set(y) set(z 1)}\ndaklsjd()";
	Tokenizer t(s);
	cout << s << endl;
	cout << t << endl;
	return 0;
}
