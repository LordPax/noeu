#ifndef NOEU_H
#define NOEU_H

#include "../paxNoeud.h"

class Noeu{
	private :
		int nbEntree;
		float *entree;
		float *poid;
		float sortie;
		float delta;

	public :
		Noeu();
		Noeu(int nbEntree);
		Noeu(int nbEntree, float *entree, float *poid);
		void setEntree(float *entree);
		void setPoid(float *poid);
		void setNbEntree(int nbEntree);
		void setDelta(float delta);
		float getDelta();
		float *getEntree();
		float getSortie();
		float *getPoid();
		int getNbEntree();
		void calcule(func f);
		void apprend(float x);
		void affiche(int l, int c, int i, int j);
};

#endif
