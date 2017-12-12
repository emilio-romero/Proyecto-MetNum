#include "funciones.h"
//Normas 
double Neuclideana(double *x, int n){
  double aux=0;
  for(int i=0;i<n;i++){
    aux+=x[i]*x[i]; 
  }
  return(sqrt(aux));
}

//Single 
double Gaussian(double *r, int n, double c){
double mr=Neuclideana(r,n);
double aux; 
  aux=exp(-(c*mr)*(c*mr));
return(aux);
}

double Multiquadratic(double *r, int n, double c){
  double mr=Neuclideana(r,n);
  double aux;
  aux=1+(c*mr)*(c*mr);
  return(sqrt(aux));
}

double Invquadratic(double *r, int n, double c){
  double mr=Neuclideana(r,n);
  double aux;
  aux=1+(c*mr)*(c*mr);
  return(1/(aux));
}

double Invmultiquadratic(double *r, int n, double c){
  double mr=Neuclideana(r,n);
  double aux;
  aux=1+(c*mr)*(c*mr);
  return(1/sqrt(aux));
}

double sMultiquadratic(double xi,double xj, double c){
  double aux=c*c+(xi-xj)*(xi-xj);
  return(sqrt(aux));
 }



