#include "noeu.h"
#include "reseau.h"

Noeu::Noeu(){}
Noeu::Noeu(int nbEntree){
	this->nbEntree = nbEntree;
}
Noeu::Noeu(int nbEntree, float *entree, float *poid){
	this->setEntree(entree);
	this->setPoid(poid);
	this->poid = poid;
}
void Noeu::setEntree(float *entree){
	float *e = new float[this->nbEntree];
	for (int i = 0; i < this->nbEntree; i++) {
		e[i] = entree[i];
	}
	this->entree = e;
}
void Noeu::setPoid(float *poid){
	float *p = new float[this->nbEntree];
	for (int i = 0; i < this->nbEntree; i++) {
		p[i] = poid[i];
	}
	this->poid = p;
}
void Noeu::setNbEntree(int nbEntree){
	this->nbEntree = nbEntree;
}
void Noeu::setDelta(float delta){
	this->delta = delta;
}
float *Noeu::getEntree(){
	return this->entree;
}
float *Noeu::getPoid(){
	return this->poid;
}
float Noeu::getSortie(){
	return this->sortie;
}
int Noeu::getNbEntree(){
	return this->nbEntree;
}
float Noeu::getDelta(){
	return this->delta;
}
void Noeu::calcule(){
	float som = 0;
	for(int i = 0; i < this->nbEntree; i++)
		som += this->entree[i] * this->poid[i];
	this->sortie = som;
}

