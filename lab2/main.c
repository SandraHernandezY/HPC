
#include "formato.h"


int main(int argc, char** argv)
{
  clock_t start_sec, end_sec, start_SIMD, end_SIMD;
  double cpu_time_used_sec, cpu_time_used_SIMD;

  char* salida=(char*)malloc(sizeof(char)*25);
  int depth, lim_inf_real, lim_inf_img, lim_sup_real, lim_sup_img=0;
  float muestreo=0; 

  int c;
  opterr=0;
  while((c= getopt(argc,argv, "i:a:b:c:d:s:f:")) != -1)
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

   // start_sec = clock();
   
    Mandelbrot_secuencial(&data, depth);

   //end_sec= clock();
   //cpu_time_used_sec = ((double) (end_sec - start_sec)) / CLOCKS_PER_SEC;

   //printf("\ncpu_time_used_modo_secuencial= %f\n",cpu_time_used_sec);

   write_img(salida, &data);
   
  return 0;
}

