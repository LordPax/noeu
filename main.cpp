#include "noeu.h"
#include "reseau.h"

int main(int argc, char **argv){
	int nbEntree = 2; // nombre d'entree par noeu
	int l = nbEntree, c = 3; // l x c noeu
	float som = 0;

	float entree[l][nbEntree] = { // matrice 2D (entree seulement pour la 1ere couche de noeu)
		{1.0, 2.1}, 
		{3.3, 1.1}
	};

	float poid[l][c][nbEntree] = { // matrice 3D (poid pour chaque noeu)
		{
			{3.2, 2.1}, {7.4, 0.1}, {9.3, 4.7}
		},
		{
			{5.3, 3.14}, {2, 12.01}, {6.66, 3.33}
		}
	};

	float *e = new float[nbEntree], *p = new float[nbEntree]; // tab temporaire entree et poid

	Noeu *r[l]; // matrice 2D de noeu

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
			r[i][j].calcule(); // calcule de la couche courante (calcule couche par couche et non linge par ligne)

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

	for(int i = 0; i < l; i++){ // test
		for(int j = 0; j < c; j++){
			cout << "l          : " << i << endl;
			cout << "c          : " << j << endl;
			cout << "nb entree  : " << r[i][j].getNbEntree() << endl;
			for (int k = 0; k < r[i][j].getNbEntree(); k++)
				cout << "entree   " << k << " : " << r[i][j].getEntree()[k] << endl;
			for (int k = 0; k < r[i][j].getNbEntree(); k++)
				cout << "poid     " << k << " : " << r[i][j].getPoid()[k] << endl;
			cout << "sortie     : " << r[i][j].getSortie() << endl;
			cout << "delta      : " << r[i][j].getDelta() << endl;
			cout << endl << "=-=-=-=-=-=-=-=-=-=-=--==-=-=-=-=-=-=-=-=-=-=-" << endl << endl;
		}
	}

//=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

	//Noeu n(nbEntree, entree, poid), n2(nbEntree, entree2, poid), n3(nbEntree), n4(nbEntree);

	// n.calcule();
	// n2.calcule();

	// entree3[0] = n.getSortie();
	// entree3[1] = n2.getSortie();

	// n3.setEntree(entree3);
	// n3.setPoid(poid);

	// n4.setEntree(entree3);
	// n4.setPoid(poid);

	// n3.calcule();
	// n4.calcule();
	
	// cout << "n resultat : " << n.getSortie() << endl;
	// cout << "n2 resultat : " << n2.getSortie() << endl;
	// cout << "n3 resultat : " << n3.getSortie() << endl;
	// cout << "n4 resultat : " << n4.getSortie() << endl;

	// n4.setDelta(1 - n4.getSortie());
	// n3.setDelta(1 - n3.getSortie());
	// n2.setDelta(n2.getSortie() * (1 - n2.getSortie()) * n3.getPoid()[1] * n3.getDelta());
	// n.setDelta(n.getSortie() * (1 - n.getSortie()) * n3.getPoid()[0] * n3.getDelta());

	// cout << "delta 4 resultat : " << n4.getDelta() << endl;
	// cout << "delta 3 resultat : " << n3.getDelta() << endl;
	// cout << "delta 2 resultat : " << n2.getDelta() << endl;
	// cout << "delta 1 resultat : " << n.getDelta() << endl;

//=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-

	// Reseau r(l, c);
	// r.genReseau();
	// r.setReseau(nbEntree, entree, poid);
	// r.setNoeu(0, 0, 2, entree, poid);
	// r.setNoeu(0, 1, 2, entree, poid);
	// r.calcule();

	// r.getNoeu(0, 0).setNbEntree(2);
	// r.getReseau()[0][0].setNbEntree(2);
	// r.getNoeu(0, 0).setEntree(entree);
	// r.getReseau()[0][0].setEntree(entree);

	// r.setNoeu(0, 0, 2, entree, poid);
	// cout << r.getNoeu(0, 0).getEntree()[0] << endl;
	// cout << r.getNoeu(0, 0).getPoid()[0] << endl;
	// cout << r.getReseau()[0][0].getNbEntree() << endl;

	return 0;
}