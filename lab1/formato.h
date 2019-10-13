#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <time.h>  //CLOCKS_PER_SEC
#include <pmmintrin.h>
#include <mmintrin.h> /*  MMX instrinsics __m64 integer type */
#include <xmmintrin.h> /* SSE __m128 float */
#include <emmintrin.h>

//Estructura img_data la cual tiene como objetivo almacenar los datos y
//las variables necesarias para procesar la imagen deseada

typedef struct img_data 
{
  int width;        /* Ancho de la imagen */
  int ** img;       /* imagen en pixeles */
  int ** img_s;     /* imagen luego de aplicar dilatacion en forma secuencial */
  int ** img_p;		/* imagen luego de aplicar dilatacion en forma paralela */
	
} img_data;



//Declaracion de funciones
void read_load_img(char* filename, img_data* image);
void write_img(char* salida, img_data* image, int modo);
void dilation_secuencial(img_data* image);
void dilation_paralela_SIMD( img_data* image);
void ver_matriz(img_data* image, int modo);