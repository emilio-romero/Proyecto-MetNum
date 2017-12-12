#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "math.h"
//Normas
//Norma euclideana 
double Neuclideana(double *x, int n);

//Single value return functions 

double Gaussian(double *r, int n, double c);
double Multiquadratic(double *r, int n, double c);
double Invquadratic(double *r, int n, double c);
double Invmultiquadratic(double *r, int n, double c);

double sMultiquadratic(double xi, double xj, double c);


#endif 
