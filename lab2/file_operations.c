#include "formato.h"

// Funcion encargada de escribir en archivo.raw los datos de las imagenes procesadas 
void write_img(char* salida, img_data* data){
	int i;

	char filename[200] = "imagenes/";
	sprintf(filename,"imagenes/%s",salida);
	FILE* file = fopen(filename,"w");  

	for( i = 0; i < data->x; i++)
		fwrite(data->M[i], sizeof(float), data->y, file);

	fclose(file);
}
