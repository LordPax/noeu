#ifndef PAX_H
#define PAX_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <math.h>
#include <time.h>

using namespace std;

float randFloat(float a, float b);
float ReLu(float x);
float sig(float x);
float Tanh(float x);

enum func{
	RELU,
	SIG,
	TANH
};

#include "libs/noeu.h"
#include "libs/reseau.h"

#endif
