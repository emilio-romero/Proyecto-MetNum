#ifndef GENERADOR_H
#define GENERADOR_H
#include <math.h>


double **prueba(int n){
  double **aux=(double**)malloc(n*sizeof(double*));
  for(int i=0;i<n;i++) aux[i]=(double*)malloc(2*sizeof(double));
  
  for(int i=0;i<n;i++){
    aux[i][0]=5.0*i/(double)n; 
    aux[i][1]=1.0/(5+aux[i][0]*aux[i][0]*exp(cos(aux[i][0])));
    //aux[i][1]=1/sinh(aux[i][0]);
    //aux[i][1]=2+sin(aux[i][0]*exp(aux[i][0]));
  }
  return(aux);
}


double **prueba3d(int n, double x0,double xf, double y0, double yf){ 
  double **aux=(double**)malloc((n*n)*sizeof(double*));
  for(int i=0;i<(n*n);i++) aux[i]=(double*)malloc(3*sizeof(double));
  double hx=(xf-x0)/(double)n; 
  double hy=(yf-y0)/(double)n; 
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      aux[j+i*n][0]=x0+(double)i*hx;
      aux[j+i*n][1]=y0+(double)j*hy;
    }
  }
  for(int i=0;i<(n*n);i++){
    aux[i][2]=aux[i][0]*aux[i][1]/(0.1+aux[i][0]*aux[i][0]+aux[i][1]*aux[i][1]);
  } 

return(aux);}


#endif 
