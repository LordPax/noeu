#include "noeu.h"
#include "reseau.h"

int main(int argc, char **argv){
	int l = 3, c = 3; // l * c noeu
	int nbEntree = l; // nombre d'entree par noeu
	float som = 0;
	float apprend = 2;
	float poidsMax = 5;
	string type;

	// float **entree = new float*[l], ***poid = new float**[l];

	// float **entree, ***poid;

	// for(int i = 0; i < l; i++)
	// 	entree[i] = new float[c];

	// for(int i = 0; i < l; i++){
	// 	poid[i] = new float*[c];
	// 	for(int j = 0; j < c; j++){
	// 		poid[i][j] = new float[nbEntree];
	// 	}
	// }


	float entree[l][nbEntree] = { // matrice 2D (entree seulement pour la 1ere couche de noeu)
		{1.0, -2.1, 11.4},    // 1ere ligne
		{-3.3, 1.1, 8.34},    // 2e ligne
		{6.66, 3.1415, 0.5}   // 3e ligne
	};

	// float poid[l][c][nbEntree] = { // matrice 3D (poid pour chaque noeu)
	// 	{
	// 		{3.2, 2.1}, {7.4, 0.1}, {9.3, 4.7}    // 1ere ligne
	// 	},
	// 	{
	// 		{5.3, 3.14}, {2, 12.01}, {6.66, 3.33} // 2e ligne
	// 	}
	// };

	/*float *e = new float[nbEntree], *p = new float[nbEntree]; // tab temporaire entree et poid

	Noeu **r = new Noeu*[l];

	for(int i = 0; i < l; i++)
		r[i] = new Noeu[c];

	for(int i = 0; i < l; i++){ // initialisation des entrees et poids de chaque noeu
		for(int j = 0; j < c; j++){
			if(j == 0){ // seulement si on est dans la 1ere couche
				for(int k = 0; k < nbEntree; k++)
					e[k] = entree[i][k]; // init les entrees de la 1ere couche
			}
			else{
				for(int k = 0; k < nbEntree; k++)
					e[k] = 0; // init les autre couche à 0
			}

			for(int k = 0; k < nbEntree; k++) 
				p[k] = poid[i][j][k]; // init les poids de chaque noeu

			r[i][j].setNbEntree(nbEntree); 
			r[i][j].setEntree(e);
			r[i][j].setPoid(p);
		}
	}

	for(int j = 0; j < c; j++){
		for(int i = 0; i < l; i++)
			r[i][j].calcule(TANH); // calcule de la couche courante (calcule couche par couche et non linge par ligne)

		if(j < c){
			for(int i = 0; i < nbEntree; i++)
				e[i] = r[i][j].getSortie(); // sauvegarde les sorties de la couche courante

			for(int i = 0; i < l; i++)
				r[i][j+1].setEntree(e); // et les associe a la couche j+1 (couche suivante)
		}
	}

	for(int j = c-1; j >= 0; j--){
		for(int i = 0; i < l; i++){
			if(j == c-1){
				r[i][j].setDelta(1 - r[i][j].getSortie()); // calcule du delta de la derniere couche 
			}
			else{
				for(int k = 0; k < nbEntree; k++)
					som += r[i][j+1].getPoid()[k]; // somme des poid a la couche j+1

				r[i][j].setDelta(r[i][j].getSortie() * (1 - r[i][j].getSortie()) * som * r[i][j+1].getDelta()); // calcule du delta pour les autres couches (parcoure décroissant)
			}
		}
	}

	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			r[i][j].affiche(l, c, i, j); // affiche les données d'un noeu
		}
	}

	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			r[i][j].apprend(apprend); // modifie les pois d'un noeu en fonction de la variable apprend
		}
	}

	cout << "+-+-+-+-+-+-+-+-+-+-+--++-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+" << endl;

	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			r[i][j].affiche(l, c, i, j); // affiche les données d'un noeu
		}
	}*/

//=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-

	Reseau r(l, c);
	r.genReseau();
	r.setReseau(nbEntree, &entree[0][0], poidsMax);
	r.calcule(RELU);
	r.retroPropag();
	r.affiche();
	r.apprend(apprend);

	cout << "=-=-=-=-==-=-=-=-=-= je suis une putin de séparation =-=-=-=-=-=-=-=-==-=-=-=-=-=-=-" << endl;

	r.calcule(RELU);
	r.retroPropag();
	r.affiche();



	return 0;
}