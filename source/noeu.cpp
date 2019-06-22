#include "../paxNoeud.h"

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
void Noeu::calcule(func f){
	float som = 0;

	for(int i = 0; i < this->nbEntree; i++)
		som += this->entree[i] * this->poid[i];

	switch(f){
		case RELU :
			som = ReLu(som);
			break;
		case SIG :
			som = sig(som);
			break;
		case TANH :
			som = Tanh(som);
			break;
	}

	this->sortie = som;
}
void Noeu::apprend(float x){
	for(int i = 0; i < this->nbEntree; i++)
		this->poid[i] = this->poid[i] + x * this->entree[i] * this->delta;
}
void Noeu::affiche(int l, int c, int i, int j){
	string type;

	if(j == 0)
		type = "Entree";
	else if(j == c-1)
		type = "Sortie";
	else
		type = "Couche caché";

	cout << "type       : " << type << endl;
	cout << "l          : " << i << endl;
	cout << "c          : " << j << endl;
	cout << "nb entree  : " << this->getNbEntree() << endl;

	for (int k = 0; k < this->getNbEntree(); k++)
		cout << "entree   " << k << " : " << this->getEntree()[k] << endl;
	for (int k = 0; k < this->getNbEntree(); k++)
		cout << "poid     " << k << " : " << this->getPoid()[k] << endl;
	
	cout << "sortie     : " << this->getSortie() << endl;
	cout << "delta      : " << this->getDelta() << endl;
	cout << endl << "=-=-=-=-=-=-=-=-=-=-=--==-=-=-=-=-=-=-=-=-=-=-" << endl << endl;
	
}

