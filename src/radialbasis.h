#ifndef RADIALBASIS_H
#define RADIALBASIS_H
#include "funciones.h"
#include "linearalgebra.h"
#include <stdio.h>
#include "solucionadores.h"
void Nula();

double *sRBFparameters(double **data,double c,double(*rfb)(double,double,double), int n);

double *RBFparameters(double **data, double c,double(*rbf)(double*,double*,int,double)
        ,int n);



int writeData(double **A, int nr, int nc, char *cfile);
#endif 
