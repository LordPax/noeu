#ifndef NOEU_H
#define NOEU_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

enum func {
	RELU,
	SIG,
	TANH
};

double ReLu(double x);
double sig(double x);
double Tanh(double x);

class Noeu{
	private :
		int nbEntree;
		double *entree;
		double *poid;
		double sortie;
		double delta;

	public :
		Noeu();
		Noeu(int nbEntree);
		Noeu(int nbEntree, double *entree, double *poid);
		void setEntree(double *entree);
		void setPoid(double *poid);
		void setNbEntree(int nbEntree);
		void setDelta(double delta);
		double getDelta();
		double *getEntree();
		double getSortie();
		double *getPoid();
		int getNbEntree();
		void calcule(func f);
		void apprend(double x);
		void affiche(int l, int c, int i, int j);
};

#endif