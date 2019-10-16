#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>  //CLOCKS_PER_SEC


//Estructura img_data la cual tiene como objetivo almacenar los datos y
//las variables necesarias para procesar la imagen deseada

typedef struct img_data 
{
  int lim_inf_real; //  [-1,-1] x
  int lim_inf_img;

  int lim_sup_real; //  [1, 1]
  int lim_sup_img;

  float muestreo;	    
  
  //Dimensiones de la matriz compleja c
  int x;
  int y; 

  float ** M;   /*matriz*/  
	
} img_data;

//DECLARACION DE FUNCIONES
void crearMatriz(img_data* data);
void write_img(char* salida, img_data* data);
void Mandelbrot_secuencial(img_data* data, int depth);
void Mandelbrot_paralelo(img_data* data, int depth, int n_task);

//void Mandelbrot_paralelo( img_data* image);
//void ver_matriz(img_data* image, int modo);