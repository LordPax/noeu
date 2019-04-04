#include "noeu.h"
#include "reseau.h"

int main(int argc, char **argv){
	int l = 3, c = 3; // l * c noeu
	int nbEntree = l; // nombre d'entree par noeu
	float som = 0;
	float apprend = 2;
	float poidsMax = 5;
	string type;

	float entree[l][nbEntree] = { // matrice 2D (entree seulement pour la 1ere couche de noeu)
		{1.0, -2.1, 11.4},    // 1ere ligne
		{-3.3, 1.1, 8.34},    // 2e ligne
		{6.66, 3.1415, 0.5}   // 3e ligne
	};

	/*float poid[l][c][nbEntree] = { // matrice 3D (poid pour chaque noeu)
		{
			{3.2, 2.1}, {7.4, 0.1}, {9.3, 4.7}    // 1ere ligne
		},
		{
			{5.3, 3.14}, {2, 12.01}, {6.66, 3.33} // 2e ligne
		}
	};*/

	Reseau r(l, c);
	r.genReseau();
	r.setReseau(nbEntree, &entree[0][0], poidsMax);
	r.calcule(RELU);
	r.retroPropag();
	r.affiche();
	r.apprend(apprend);

	cout << "=-=-=-=-==-=-=-=-=-= je suis une putin de séparation =-=-=-=-=-=-=-=-==-=-=-=-=-=-=-" << endl;

	r.calcule(TANH);
	r.retroPropag();
	r.affiche();
	
	cout << endl << "je suis un test " << r.getSortieR()[0] << endl;
	cout << endl << "je suis un test " << r.getSortieR()[1] << endl;
	cout << endl << "je suis un test " << r.getSortieR()[2] << endl;



	return 0;
}
