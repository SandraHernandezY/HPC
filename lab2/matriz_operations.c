#include "formato.h"

void crearMatriz(img_data* data){
  
  int i,j,a,x,y;

  i= data->lim_sup_real - (data->lim_inf_real);
  j= data->lim_sup_img - (data->lim_inf_img);
  //int ej=3/0.00100;
  //printf("ejemplo=%d\n", ej); 
  printf("i=%d\nj=%d\n", i,j); 
  //printf("muestreo=%f\n", data->muestreo);  

  x= ceil(i/data->muestreo);
  y= ceil(j/data->muestreo);

  data->x= x+1;
  data->y= y+1;
  
  printf("data->x=%d\n data->y=%d\n", data->x,data->y );

  //Reservando memoria para la matriz M
  data->M= (float **)malloc (data->x * sizeof(float *));
  for ( a= 0; a < data->x; a++)  
    data->M[a] = (float *) malloc (data->y* sizeof(float));

}

