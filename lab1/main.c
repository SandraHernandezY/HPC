
#include "formato.h"

// Funcion que muestra la imagen resultante en ceros (0) y unos(255) por consola
void ver_matriz( img_data* image, int op)
{
   int i,j;
   if(op == 0){
    for( i = 0; i < image->width; i++ )
    {
      for( j = 0; j < image->width; j++ ){
        if(image->img_s[i][j] >= 255){
          printf( "1 " );
        }
        else
          printf( "0 " );
        }
      printf( "\n ");
    }
   }
   else{
    for( i = 0; i < image->width; i++ )
    {
      for( j = 0; j < image->width; j++ ){
        if(image->img_p[i][j] >= 255){
          printf( "1 " );
        }
        else
          printf( "0 " );
        }
        printf( "\n ");
    }    
   }
}

int main(int argc, char** argv)
{
  clock_t start_sec, end_sec, start_SIMD, end_SIMD;
  double cpu_time_used_sec, cpu_time_used_SIMD;

  char* img_entrada=(char*)malloc(sizeof(char)*25);//• 
  char* img_salida1=(char*)malloc(sizeof(char)*25);//• nombre del archivo resultante del proceso secuencial
  char* img_salida2=(char*)malloc(sizeof(char)*25);//• nombre del archivo resultante del proceso SIMD
  int ancho_img=0;      
  int opcion_debug=0;
  int c;
  opterr=0;
  while((c= getopt(argc,argv, "i:s:p:N:D:")) != -1)
    {
      switch(c)
      {
        case 'i':
          sscanf(optarg, "%s", img_entrada);
          break;
        case 's':
          sscanf(optarg, "%s", img_salida1);
          break;
        case 'p':
          sscanf(optarg, "%s", img_salida2);
          break;
        case 'N':
          sscanf(optarg, "%d", &ancho_img);
          break;
        case 'D':
          sscanf(optarg, "%d", &opcion_debug);
          break;
        case '?':
          if(optopt == 'b')
            fprintf(stderr, "Opcion -%c requiere un argumento\n", optopt);
          else if(isprint(optopt))
            fprintf(stderr, "Opcion desconocida -%c\n", optopt);
          else
            fprintf(stderr, "Opcion con caracter desconocido ' \\x%x ' \n", optopt);
          return 1;
        default:
          abort();
      }
    } 
   //printf("img_entrada=%s , img_salida1=%s , img_salida2=%s , ancho_img=%d, opcion_debug=%d\n", img_entrada, img_salida1, img_salida2, ancho_img, opcion_debug);
   
   img_data image;
   image.width= ancho_img;
   read_load_img(img_entrada, &image); 

   start_sec = clock();
   dilation_secuencial(&image);
   end_sec= clock();
   cpu_time_used_sec = ((double) (end_sec - start_sec)) / CLOCKS_PER_SEC;

   printf("\ncpu_time_used_modo_secuencial= %f\n",cpu_time_used_sec);

   start_SIMD = clock();
   dilation_paralela_SIMD(&image);
   end_SIMD= clock();
   cpu_time_used_SIMD= ((double) (end_SIMD - start_SIMD)) / CLOCKS_PER_SEC;

   printf("cpu_time_used_modo_SIMD= %f\n",cpu_time_used_SIMD);

   write_img(img_salida1, &image, 0);
   write_img(img_salida2, &image, 1);

   if(opcion_debug==1){ // si la opcion debug es igual a uno mostrar la matriz resultante en ceros y uno
    printf("\n Imagen resultante de forma secuencial \n");
    ver_matriz(&image ,0);
    printf("\n Imagen resultante de forma paralela SIMD \n");
    ver_matriz(&image ,1);
   }
   
  return 0;
}

