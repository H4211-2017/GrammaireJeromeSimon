#include <iostream>

using namespace std;


#include "Automate.h"

int main(int argc, char* argv[])
{
	string a = "";
	getline(cin, a);
	Automate automate(a);
	
	cout << "Calcul : " << automate.value() << endl;
	
	return 0;
}
