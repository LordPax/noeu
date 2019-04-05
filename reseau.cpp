#include "noeu.h"
#include "reseau.h"

float randFloat(float a, float b){
	return (rand() / (float)RAND_MAX) * (b - a) + a;
}

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
void Reseau::setReseau(int nbEntree, float *entree, float poidsMax){
	clock_t temps;
	float *e = new float[nbEntree], *p = new float[nbEntree]; // tab temporaire entree et poid
	srand(time(NULL));

	for(int i = 0; i < this->ligne; i++){ // initialisation des entrees et poids de chaque noeu
		for(int j = 0; j < this->colonne; j++){
			if(j == 0){ // seulement si on est dans la 1ere couche
				for(int k = 0; k < nbEntree; k++)
					e[k] = entree[nbEntree * i + k]; // init les entrees de la 1ere couche
			}
			else{
				for(int k = 0; k < nbEntree; k++)
					e[k] = 0; // init les autre couche à 0
			}

			for(int k = 0; k < nbEntree; k++)
				p[k] = randFloat(0, poidsMax);

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
	float som = 0;
	for(int j = this->colonne - 1; j >= 0; j--){
		for(int i = 0; i < this->ligne; i++){
			if(j == this->colonne - 1){
				this->reseau[i][j].setDelta(1 - this->reseau[i][j].getSortie()); // calcule du delta de la derniere couche 
			}
			else{
				for(int k = 0; k < this->ligne; k++)
					som += this->reseau[i][j+1].getPoid()[k]; // somme des poid a la couche j+1

				this->reseau[i][j].setDelta(this->reseau[i][j].getSortie() * (1 - this->reseau[i][j].getSortie()) * som * this->reseau[i][j+1].getDelta()); // calcule du delta pour les autres couches (parcoure décroissant)
			}
		}
	}
}
void Reseau::affiche(){
	int l = this->ligne, c = this->colonne;
	for(int i = 0; i < l; i++)
		for(int j = 0; j < c; j++)
			this->reseau[i][j].affiche(l, c, i, j); // affiche les données d'un noeu
}
void Reseau::calcule(func f){
	float *e = new float[this->ligne];
	//int *nbEntree = new int[this->ligne];
	for(int j = 0; j < this->colonne; j++){
		for(int i = 0; i < this->ligne; i++)
			this->reseau[i][j].calcule(f); // calcule de la couche courante (calcule couche par couche et non linge par ligne)
			//nbEntree[i] = this->reseau[i][j].getEntree();

		if(j < this->colonne){
			for(int i = 0; i < this->ligne; i++)
				e[i] = this->reseau[i][j].getSortie(); // sauvegarde les sorties de la couche courante

			for(int i = 0; i < this->ligne; i++)
				this->reseau[i][j+1].setEntree(e); // et les associe a la couche j+1 (couche suivante)
		}
	}
}
void Reseau::apprend(float apprend){
	for(int i = 0; i < this->ligne; i++)
		for(int j = 0; j < this->colonne; j++)
			this->reseau[i][j].apprend(apprend); // modifie les pois d'un noeu en fonction de la variable apprend
}

float *Reseau::getSortieR(){
	float *sortie = new float[this->ligne];
	
	for(int i = 0; i < this->ligne; i++)
		sortie[i] = this->reseau[i][this->colonne - 1].getSortie();
		
	return sortie;
}
