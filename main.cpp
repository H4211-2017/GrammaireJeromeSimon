#include <iostream>

using namespace std;


#include "Automate.h"

int main(int argc, char* argv[])
{
	string a = "";

	cout << "Entrez la formule : ";
	getline(cin, a);
	Automate automate(a);

	cout << "Resultat : " << automate.value() << endl;

	return 0;
}
