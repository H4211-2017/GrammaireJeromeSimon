#include <iostream>

#include "Lexer.h"

using namespace std;

int main(int argc, char* argv[])
{
	string a = "";
	getline(cin, a);
	Lexer l(a);
	
	while(l.readNext().type != ENDOF)
	{
		l.printInput();
		Token t = l.consume();
		cout << "type : " << t.type << "valeur : " << t.value << "strvaleur : " << t.strValue << endl;
		
	}
	
	return 0;
}
