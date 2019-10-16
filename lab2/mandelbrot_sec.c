#include "formato.h"

void Mandelbrot_secuencial(img_data* data, int depth){

	int  i, j; 
	float n, c_real, c_img, z_0, z_real, z_img, pow_real, pow_img, modulo;

	for(i=0; i < data->x; i++){
		for(j=0; j < data->y; j++){
			c_real= data->lim_inf_real + i* data->muestreo;
			c_img= data->lim_inf_img + j* data->muestreo;

			z_0=0;	
			n=1;

			z_real= z_0 + c_real;
			z_img= z_0 + c_img;

			pow_real= pow(z_real, 2);
			pow_img= pow(z_img, 2);

			modulo= sqrt(pow_real + pow_img);

			while(modulo < 2 && n < depth){
				
				z_img= 2*z_real*z_img + c_img;
				z_real= pow_real - pow_img + c_real;
				
				pow_real= pow(z_real, 2);
				pow_img= pow(z_img, 2);
				modulo= sqrt(pow_real + pow_img);

				n++;
			}
			
			data->M[i][j]= log(n)+1;
		}

	}
}