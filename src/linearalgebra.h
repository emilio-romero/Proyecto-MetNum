#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H
#include <math.h>
#include <stdlib.h>
//#include <fstream.h>

double prodPunto(double *a, double *b, int n);
int prodMatVec(double *out, double **A, double *v, int n);
double *GradienteConjugado(double **A, double *b, int n, double tol);

#endif 
