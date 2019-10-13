#include "formato.h"

void dilation_secuencial(img_data* image)
{
  	int x, y, i, j, suma, up, down, right, left, sum;

  //Reservando memoria
	image->img_s= (int **)malloc (image->width*sizeof(int *));
	for ( i= 0; i < image->width; i++)  
		image->img_s[i] = (int *) malloc (image->width*sizeof(int));

	//copia de la imagen original
	for( i = 0; i < image->width; i++ )
  {
      for( j = 0; j < image->width; j++ ){
        image->img_s[i][j]= image->img[i][j];
      }
  }

	for( i = 1; i < image->width-1; i++ )
    {
        for( j = 1; j < image->width-1; j++ ){
         	
         	up= image->img[i-1][j];
        	down= image->img[i+1][j];
        	right= image->img[i][j+1];
        	left= image->img[i][j-1];
        	sum= up + down + right +left +image->img[i][j];

        	image->img_s[i][j]=sum;
        }
    }
	
}


