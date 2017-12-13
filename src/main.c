#include <stdio.h>
#include "radialbasis.h"
#include "lectura.h"
#include "generador.h"
int main(){
int v=180;
int nv=6;
double **test1=prueba(v);
double **test2=prueba3d(nv,-1,1,-1,1);

/*//Ejemplo 2d
double *res1=sRBFparameters(test1,0.3,sMultiquadratic,v);
double **puntos1=sgraficaMQ(0.001,4.999,400,test1,res1,v);
printMatrix(puntos1,400,2);
writeData(puntos1,400,2,"prueba.dat");
*/
//Ejemplo 3d
double *res1=RBFparameters(test2,0.3,Multiquadratic,nv*nv);
double **puntos2=graficaMQ(-0.9,0.9,-0.9,0.9,20,test2,res1,nv*nv);
writeData(puntos2,400,3,"prueba3d.dat");

for(int i=0;i<v;i++){ free(test1[i]);}
for(int i=0;i<(nv*nv);i++) free(test2[i]);
free(test1); free(res1); free(test2);
printf("Su programa ha terminado\n");
return 0;}
