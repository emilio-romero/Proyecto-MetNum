#include "linearalgebra.h"

double prodPunto(double *a, double *b, int n){
  double suma=0;
  for(int i=0;i<n;i++){
    suma+=a[i]*b[i];
  }
  return(suma);
}

int prodMatVec(double *out, double **A, double *v, int n){
  double suma;
  for(int i=0;i<n;i++){
    suma=0;
    for(int k=0;k<n;k++){
      suma+=A[i][k]*v[k];
    }
    out[i]=suma;
  }
return 1;}

int restaVec(double *out, double *a, double *b, int n){
  for(int i=0;i<n;i++){
    out[i]=a[i]-b[i];
  }
return 1;}
int sumaVec(double *out, double *a, double *b, int n){
  for(int i=0;i<n;i++){
    out[i]=a[i]+b[i];
  }
return 1;}

int escalarVec(double *out, double a, double *b, int n){
  for(int i=0;i<n;i++){
    out[i]=a*b[i];
  }
return 1;}

double *GradienteConjugado(double **A, double *b, int n, double tol){
double *r=(double*)malloc(n*sizeof(double));
double *p=(double*)malloc(n*sizeof(double));
double *x=(double*)calloc(n,sizeof(double));
double *q=(double*)calloc(n,sizeof(double));
double *aux=(double*)calloc(n,sizeof(double));
double err,dk,ak,bk;
  for(int i=0;i<n;i++){
    r[i]=b[i]; p[i]=b[i];
  }
  err=sqrt(prodPunto(r,r,n)/(double)n);
  int cont=0;
  while(tol<err){
    prodMatVec(q,A,p,n);
    dk=prodPunto(r,r,n);// printf("dk: %lf\n",dk);
    ak=dk/(prodPunto(p,q,n));//printf("ak: %lf\n",ak);
    for(int k=0;k<n;k++){
     x[k]=x[k]+ak*p[k];
     r[k]=r[k]-ak*q[k];
    }
   // prodMatVec();
    
    bk=prodPunto(r,r,n)/dk;
    for(int k=0;k<n;k++) p[k]=r[k]+bk*p[k];
    err=sqrt(prodPunto(r,r,n)/(double)n);
    cont++;
  }
 // printf("El tamanio de la matriz es de: %d x %d\n",n,n);
 // printf("Se realizaron <%d> iteraciones\n",cont);
 // printf("error: %g\n",err);

free(q); free(r); free(p); free(aux);
return(x);
}
