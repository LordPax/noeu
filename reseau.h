#ifndef RESEAU_H
#define RESEAU_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Reseau{
	private :
		int ligne;
		int colonne;
		Noeu **reseau;

	public :
		Reseau(int l, int c);
		void setLigne(int l);
		void setColonne(int c);
		void setReseau(int nbEntree, float **entree, float ***poid);
		void genReseau();
		void setNoeu(int l, int c, int nbEntree, float *entrees, float *poid);
		int getLigne();
		int getColonne();
		void calcule();
		Noeu **getReseau();
		Noeu getNoeu(int l, int c);
		void retroPropag();
		void retroPropagS();
		void affiche();
};

#endif
