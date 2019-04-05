#include "../paxNoeud.h"

float ReLu(float x){
	if(x < 0)
		x = 0;
	return x;
}
float sig(float x){
	return 1 / (1 + exp(-x));
}
float Tanh(float x){
	return 2 / (1 + exp(-2 * x)) - 1;
}
float randFloat(float a, float b){
	return (rand() / (float)RAND_MAX) * (b - a) + a;
}
