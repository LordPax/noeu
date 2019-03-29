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
	Noeu **r = new Noeu*[this->ligne];
	for(int i = 0; i < this->ligne; i++)
		r[i] = new Noeu[this->colonne];

	this->reseau = r;
}
void Reseau::setReseau(int nbEntree, float **entree, float ***poid){
	float *e = new float[nbEntree], *p = new float[nbEntree]; // tab temporaire entree et poid

	for(int i = 0; i < this->ligne; i++){ // initialisation des entrees et poids de chaque noeu
		for(int j = 0; j < this->colonne; j++){
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

			this->reseau[i][j].setNbEntree(nbEntree); 
			this->reseau[i][j].setEntree(e);
			this->reseau[i][j].setPoid(p);
		}
	}
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
void Reseau::affiche(){
	int l = this->ligne, c = this->colonne;
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			this->reseau[i][j].affiche(l, c, i, j); // affiche les données d'un noeu
		}
	}
}
