#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <math.h>
#include <stdlib.h>
#include "linearalgebra.h"
//Normas
//Norma euclideana 
double Neuclideana(double *x, int n);

//Single value return functions 

double Gaussian(double *xi, double *xj, int n, double c);
double Multiquadratic(double *xi, double *xj, int n, double c);
double Invquadratic(double *xi, double *xj, int n, double c);
double Invmultiquadratic(double *xi, double *xj, int n, double c);

double sMultiquadratic(double xi, double xj, double c);

double **sgraficaMQ(double x0, double xf, int n,double **test,double *sol,int m);
double **graficaMQ(double x0, double xf, double y0, double yf,int n, double **test, 
double *sol,int m);

#endif 
