#include "radialbasis.h"

void Nula(){
  printf("Hola, no hago nada, como estas?\n");
}



double *sRBFparameters(double **data,double c,double(*rbf)(double,double,double), int n){
  double *fi=(double*)malloc(n*sizeof(double));
  for(int i=0;i<n;i++) fi[i]=data[i][1];
  double **A=(double**)malloc(n*sizeof(double*));
  for(int i=0;i<n;i++){
    A[i]=(double*)malloc(n*sizeof(double));
    for(int j=0;j<n;j++){
      A[i][j]=rbf(data[i][0],data[j][0],c); 
    }  
    A[i][i]+=0.00000000005;
  }

  //double *param=GradienteConjugado(A,fi,n,0.0001);
  double *param=factLU(A,fi,n);

for(int i=0;i<n;i++){
  free(A[i]);
}
free(fi); free(A);
return(param);}

double *RBFparameters(double **data, double c, double(*rbf)(double*,double*,int,double)
      ,int n){
  double *fi=(double*)malloc(n*sizeof(double));
  for(int i=0;i<n;i++) fi[i]=data[i][2];
  double **A=(double**)malloc(n*sizeof(double*));
  double **ndat=(double**)malloc(n*sizeof(double*));
  for(int i=0;i<n;i++){
    A[i]=(double*)malloc(n*sizeof(double));
    ndat[i]=(double*)malloc(2*sizeof(double));
    ndat[i][0]=data[i][0];
    ndat[i][1]=data[i][1];
  }
 
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      A[i][j]=rbf(ndat[i],ndat[j],2,c); 
    }
    A[i][i]+=0.000000001;
  }
   
  double *param=GradienteConjugado(A,fi,n,0.000001);
  //double *param=factLU(A,fi,n);
  

for(int i=0;i<n;i++){
  free(A[i]); free(ndat[i]);
}
free(fi); free(A); free(ndat);
return(param);}


int writeData(double **A, int nr, int nc, char *cfile){
  FILE *out; 
  out=fopen(cfile,"w");
  for(int i=0;i<nr;i++){
    for(int j=0;j<nc;j++){
      fprintf(out,"%lf ",A[i][j]);
    }
    fprintf(out,"\n");
  }

  fclose(out);
return 1;}

