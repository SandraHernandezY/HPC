#include "formato.h"

// Funcion encargada de leer y cargar los datos entregados por el archivo .raw 
// de un nombre dado y guardalo en image
void read_load_img(char* name, img_data* image){
	int i,j,pixel;
	FILE * file;
								// filas * 
	image->img = (int **)malloc (image->width*sizeof(int *));

	for ( i= 0; i < image->width; i++)  // columnas
	image->img[i] = (int *) malloc (image->width*sizeof(int));

	char filename[200] = "imagenes/";
	sprintf(filename,"imagenes/%s",name);
	file = fopen(filename,"r"); 

	if (file == NULL)
    {
        printf("\nError de apertura del archivo. \n\n");
    }
    else
       {
	 	for( i = 0; i < image->width; i++)
        	fread(image->img[i], sizeof(int), image->width , file);
    }
	fclose(file);
}

// Funcion encargada de escribir en archivo.raw los datos de las imagenes procesadas 
void write_img(char* salida, img_data* image){
	int i,j;

	char filename[200] = "imagenes/";
	sprintf(filename,"imagenes/%s",salida);
	FILE* file = fopen(filename,"wd");  

	for( i = 0; i < image->width; i++)
		fwrite(image->img_c[i], sizeof(int), image->width , file);

	fclose(file);
}
