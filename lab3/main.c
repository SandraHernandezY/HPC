
#include "formato.h"

// Funcion que muestra la imagen resultante en ceros (0) y unos(255) por consola
void ver_matriz( img_data* image)
{
  int i,j;
  for( i = 0; i < image->width; i++ )
  {
    for( j = 0; j < image->width; j++ ){
      if(image->img_c[i][j] >= 255){
         printf( "1 " );
      }
      else
        printf( "0 " );
      }
    printf( "\n ");
  }
}

int main(int argc, char** argv)
{

  char* img_entrada=(char*)malloc(sizeof(char)*25);//• 
  char* img_salida=(char*)malloc(sizeof(char)*25);//• nombre del archivo resultante del proceso secuencial
  int ancho_img=0;      
  int c, n_task, debug;
  opterr=0;
  while((c= getopt(argc,argv, "i:s:N:H:D:")) != -1)
    {
      switch(c)
      {
        case 'i':
          sscanf(optarg, "%s", img_entrada);
          break;
        case 's':
          sscanf(optarg, "%s", img_salida);
          break;
        case 'N':
          sscanf(optarg, "%d", &ancho_img);
          break;
        case 'H':
          sscanf(optarg, "%d", &n_task);
          break;
        case 'D':
          sscanf(optarg, "%d", &debug);
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
   printf("img_entrada=%s , img_salida=%s, ancho_img=%d, hebras=%d,opcion_debug=%d\n", img_entrada, img_salida, ancho_img,n_task,debug);
   
   img_data image;
   image.width= ancho_img;
   read_load_img(img_entrada, &image); 
   dilatation_paralela(&image,n_task);
   write_img(img_salida, &image);

  if(debug==1){ 
    printf("\n Imagen resultante de forma paralela \n");
    ver_matriz(&image);
   }

   
  return 0;
}

