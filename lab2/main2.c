
#include "formato.h"


int main(int argc, char** argv)
{

  char* salida=(char*)malloc(sizeof(char)*25);
  int n_task, depth, lim_inf_real, lim_inf_img, lim_sup_real, lim_sup_img=0;
  float muestreo=0; 

  int c;
  opterr=0;
  while((c= getopt(argc,argv, "i:a:b:c:d:s:f:t:")) != -1)
    {
      switch(c)
      {
        case 'i':
          sscanf(optarg, "%d", &depth);
          break;
        case 'a':
          sscanf(optarg, "%d", &lim_inf_real);
          break;
        case 'b':
          sscanf(optarg, "%d", &lim_inf_img);
          break;
        case 'c':
          sscanf(optarg, "%d", &lim_sup_real);
          break;
        case 'd':
          sscanf(optarg, "%d", &lim_sup_img);
          break;
        case 's':
          sscanf(optarg, "%f", &muestreo);
          break;
        case 'f':
          sscanf(optarg, "%s", salida);
          break;
        case 't':
          sscanf(optarg, "%d", &n_task);
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
   
   img_data data;

   data.lim_inf_real= lim_inf_real;
   data.lim_inf_img= lim_inf_img;
   data.lim_sup_real= lim_sup_real;
   data.lim_sup_img= lim_sup_img; 
   data.muestreo= muestreo; 

   crearMatriz(&data);
   
   Mandelbrot_paralelo(&data, depth, n_task);

   write_img(salida, &data);
   
  return 0;
}

