#include "formato.h"

void dilation_paralela_SIMD(img_data* image){
    int i,j,k;

	//Reservando memoria
	image->img_p= (int **)malloc (image->width*sizeof(int *));
	for ( i= 0; i < image->width; i++)  // columnas
		image->img_p[i] = (int *) malloc (image->width*sizeof(int));

	//copia de la imagen original
	for( i = 0; i < image->width; i++ )
  	{
      for( j = 0; j < image->width; j++ ){
        image->img_p[i][j]= image->img[i][j];
      }
  	}

  	//dilation
    __m128i up,down,left,right,center,sum, pixel;
    for(i = 1; i< image->width-1; i++){

        for(j = 1; j < image->width-4; j= j+4){
            up = _mm_loadu_si128((__m128i*)&image->img[i-1][j]);
            down = _mm_loadu_si128((__m128i*)&image->img[i+1][j]);
            left = _mm_loadu_si128((__m128i*)&image->img[i][j-1]);
            right = _mm_loadu_si128((__m128i*)&image->img[i][j+1]);
            pixel=_mm_loadu_si128((__m128i*)&image->img[i][j]);
            //sum = _mm_loadu_si128((__m128i*)&image->img[i][j]);
            sum = _mm_max_epi16(up,down);
            sum = _mm_max_epi16(sum,right);
            center = _mm_max_epi16(sum,left);
            center= _mm_max_epi16(center,pixel);
            _mm_storeu_si128((__m128i*)&image->img_p[i][j],center);
            
        }
    }
}