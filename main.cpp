#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


#include "Automate.h"

void sansArgs();
void unArg(string un);
void deuxArgs(string un, string deux);

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		sansArgs();
	}
	else if(argc == 2)
	{
		unArg(argv[1]);
	}
	else if(argc == 3)
	{
		deuxArgs(argv[1], argv[2]);
	}
	else
	{
		cout << "trop d'arguments" << endl;
	}

	return 0;
}

void sansArgs()
{
	while(true)
	{
		string a = "";

		cout << "Entrez la formule (Q pour quitter) : ";
		getline(cin, a);
        if(a == "Q" || a == "q") break;
		try
		{
			Automate automate(a);
			cout << "Resultat : " << automate.value() << endl;
		}
		catch(string const& chaine)
		{
			cout << chaine << endl;
		}
	}
}

void unArg(string un)
{
	deuxArgs(un, "resultats.txt");
}

void deuxArgs(string un, string deux)
{
	string nomFichier(un);
	ifstream fichier(nomFichier);
	if(fichier)
	{
		string ligne;
		stringstream sortie;
		while(getline(fichier, ligne))
		{
			try
			{

				Automate automate(ligne);
				sortie << "Resultat : " << automate.value() << endl << endl;
			}
			catch(string const& chaine)
			{
				sortie << chaine << endl << endl;
			}
		}

		ofstream ecriture(deux, ios::out | ios::trunc);
		if(ecriture)
		{
			ecriture << sortie.str();
			ecriture.close();
		}

		fichier.close();
	}
}
