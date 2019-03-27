#include "noeu.h"
#include "reseau.h"

Reseau::Reseau(int l, int c){
	this->ligne = l;
	this->colonne = c;
}
void Reseau::setLigne(int l){
	this->ligne = l;
}
void Reseau::setColonne(int c){
	this->colonne = c;
}
void Reseau::genReseau(){
	Noeu *r[this->ligne];
	for(int i = 0; i < this->ligne; i++)
		r[i] = new Noeu[this->colonne];

	this->reseau = r;
}
void Reseau::setReseau(int nbEntree, float *entree, float *poid){
	for(int i = 0; i < this->ligne; i++)
		for(int j = 0; j < this->colonne; j++)
			this->setNoeu(i, j, nbEntree, entree, poid);
}
void Reseau::setNoeu(int l, int c, int nbEntree, float *entree, float *poid){
	this->reseau[l][c].setNbEntree(nbEntree);
	this->reseau[l][c].setEntree(entree);
	this->reseau[l][c].setPoid(poid);
}
int Reseau::getLigne(){
	return this->ligne;
}
int Reseau::getColonne(){
	return this->colonne;
}
Noeu **Reseau::getReseau(){
	return this->reseau;
}
Noeu Reseau::getNoeu(int l, int c){
	return this->reseau[l][c];
}
void Reseau::retroPropag(){
	
}
void Reseau::retroPropagS(){
	
}
