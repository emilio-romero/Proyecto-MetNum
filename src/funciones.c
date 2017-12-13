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
double Gaussian(double *xi, double *xj, int n, double c){
double *aux=(double*)malloc(n*sizeof(double));
restaVec(aux,xi,xj,n);
double mr=Neuclideana(aux,n);
double saux; 
  saux=exp(-(c*mr)*(c*mr));
return(saux);
}

double Multiquadratic(double *xi, double *xj, int n, double c){
double *aux=(double*)malloc(n*sizeof(double));
restaVec(aux,xi,xj,n);
double mr=Neuclideana(aux,n);
  double saux;
  saux=1+(c*mr)*(c*mr);
  return(sqrt(saux));
}

double Invquadratic(double *xi, double *xj, int n, double c){
double *aux=(double*)malloc(n*sizeof(double));
restaVec(aux,xi,xj,n);
double mr=Neuclideana(aux,n);
  double saux;
  saux=1+(c*mr)*(c*mr);
  return(1/(saux));
}

double Invmultiquadratic(double *xi, double *xj, int n, double c){
double *aux=(double*)malloc(n*sizeof(double));
restaVec(aux,xi,xj,n);
double mr=Neuclideana(aux,n);
  double saux;
  saux=1+(c*mr)*(c*mr);
  return(1/sqrt(saux));
}

double sMultiquadratic(double xi,double xj, double c){
  double aux=c*c+(xi-xj)*(xi-xj);
  return(sqrt(aux));
 }

double **sgraficaMQ(double x0, double xf, int n, double **test, double *sol,int m){
double h=(xf-x0)/(double)n; 
double **aux=(double**)malloc(n*sizeof(double*));
double centro=test[0][0];
for(int k=0;k<n;k++) aux[k]=(double*)malloc(2*sizeof(double));
  for(int i=0;i<n;i++){
    aux[i][0]=x0+i*h;
     aux[i][1]=0;//lamb*sMultiquadratic(aux[i][0],centro,0.3); 
    for(int j=0;j<m;j++){
      aux[i][1]+=sol[j]*sMultiquadratic(aux[i][0],test[j][0],0.3);
    }
    }
return(aux);}

double **graficaMQ(double x0, double xf, double y0, double yf, int n,
  double **test, double *sol, int m){
    
  double hx=(xf-x0)/(double)n; 
  double hy=(yf-y0)/(double)n; 
  double *xi=(double*)malloc(2*sizeof(double));
  double *xj=(double*)malloc(2*sizeof(double));
  double **aux=(double**)malloc((n*n)*sizeof(double*));
  for(int k=0;k<(n*n);k++){aux[k]=(double*)malloc(3*sizeof(double));}
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      aux[j+i*n][0]=x0+i*hx;
      aux[j+i*n][1]=y0+j*hy;
      aux[j+i*n][2]=0;
      xi[0]=aux[j+i*n][0];
      xi[1]=aux[j+i*n][1];
      for(int k=0;k<m;k++){
        xj[0]=test[k][0];
        xj[1]=test[k][1];
        aux[j+i*n][2]+=sol[k]*Multiquadratic(xi,xj,2,0.3);
      }
    }
  }
  
return(aux);}

