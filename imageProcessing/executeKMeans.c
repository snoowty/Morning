#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvProgramming.h"

#define SIZE_RGB (256 * 256 * 256)


//
// num個の中心点の初期値を算出する
//
static void initCenters(unsigned char *centers, int num) {

	int i, r, g, b, value, ii;

	for(i = 1, ii = 0; i <= num; i++) {
		value = SIZE_RGB * i / (num + 1);
		r = value / (256 * 256);
		value -= r * 256 * 256;
		g = value / 256;
		value -= g * 256;
		b = value;
		printf("i=%d r=%d g=%d b=%d\n", i, r, g, b);
		centers[ii++] = (unsigned char)r;
		centers[ii++] = (unsigned char)g;
		centers[ii++] = (unsigned char)b;
	}

}


//
// 各画素を最も近い色のクラスタに当てはめる
//
void assignPixels(unsigned char *image1, unsigned char *image2, int *idarray,
				  int width, int height, unsigned char *centers, int num) {

	int wh3 = width * height * 3;
	int r1, g1, b1, r2, g2, b2, i, ii, j, k;
	double dist, mind;

	//
	// 各画素ごとに
	//
	for(i = 0, ii = 0; ii < wh3; i++, ii += 3) {
		
		//
		// 入力画像からRGB値をとってくる
		//
		r1 = (int)image1[ii + 0];
		g1 = (int)image1[ii + 1];
		b1 = (int)image1[ii + 2];

		//
		// 各中心点ごとに
		//
		for(j = 0, k = -1, mind = (double)SIZE_RGB; j < (3 * num); j += 3) {

			//
			// 中心点のRGB値をとってくる
			//
			r2 = (int)centers[j + 0];
			g2 = (int)centers[j + 1];
			b2 = (int)centers[j + 2];

			//
			// この中心点が最も近かったら、その中心点を記録する
			//
			dist = (double)(r2 - r1) * (double)(r2 - r1)
				 + (double)(g2 - g1) * (double)(g2 - g1)
				 + (double)(b2 - b1) * (double)(b2 - b1);
			if(dist < mind) {
				mind = dist;   k = j;
			}
		}
		idarray[i] = k / 3;

		//
		// 出力画像中の当該画素に、選ばれた中心点のRGB値を代入する
		//
		image2[ii + 0] = centers[k + 0];
		image2[ii + 1] = centers[k + 1];
		image2[ii + 2] = centers[k + 2];

	}

}



//
// 新しいRGB中心値群を算出する
//
double calcNewCenter(unsigned char *image1, unsigned char *image2,
				  int *idarray, int width, int height,
				  unsigned char *centers, unsigned char *pcenters, int num){

	int wh3 = width * height * 3;
	int *rgbsum = (int *)malloc(sizeof(int) * 3 * num);
	int *rgbcount = (int *)malloc(sizeof(int) * num);
	int r1, g1, b1, r2, g2, b2, i, ii, k;
	double dist;

	//
	// 初期化
	//
	for(i = 0; i < num; i++) {
		rgbsum[3 * i] = rgbsum[3 * i + 1] = rgbsum[3 * i + 2] = rgbcount[i] = 0;
	}


	//
	// 各画素ごとに
	//
	for(i = 0, ii = 0; ii < wh3; i++, ii += 3) {

		//
		// 出力画像からRGB値をとってくる
		//
		r1 = (int)image2[ii + 0];
		g1 = (int)image2[ii + 1];
		b1 = (int)image2[ii + 2];
		k = idarray[i];

		//
		// 入力画像のRGB値を加算する
		//
		rgbcount[k] += 1;
		rgbsum[k * 3 + 0] += (int)image1[ii + 0];
		rgbsum[k * 3 + 1] += (int)image1[ii + 1];
		rgbsum[k * 3 + 2] += (int)image1[ii + 2];

	}

	//
	// 各中心点ごとに
	//
	for(i = 0, ii = 0, dist = 0.0; i < num; i++, ii += 3) {

		//
		// RGB値の中心点を算出する
		//
		if(rgbcount[i] > 0) {
			rgbsum[ii + 0] /= rgbcount[i];
			rgbsum[ii + 1] /= rgbcount[i];
			rgbsum[ii + 2] /= rgbcount[i];
		}
		r1 = rgbsum[ii + 0];
		g1 = rgbsum[ii + 1];
		b1 = rgbsum[ii + 2];
		pcenters[ii + 0] = (unsigned char)r1;
		pcenters[ii + 1] = (unsigned char)g1;
		pcenters[ii + 2] = (unsigned char)b1;

		//
		// 本来の中心点との距離を算出する
		//
		r2 = (int)centers[ii + 0];
		g2 = (int)centers[ii + 1];
		b2 = (int)centers[ii + 2];

		dist += (double)(r2 - r1) * (double)(r2 - r1)
			 +  (double)(g2 - g1) * (double)(g2 - g1)
			 +  (double)(b2 - b1) * (double)(b2 - b1);

		//printf("    i=%d (%d, %d, %d) (%d, %d, %d)\n", i, r1, g1, b1, r2, g2, b2);

	}

	return dist;
}




//
// 画像処理の例：k-means法による画素クラスタリング
//
Image *executeKMeans(Image *input1, int num, int **iarray, unsigned char **colormap) {
	unsigned char *image1 = input1->image;
	int width = input1->width;
	int height = input1->height;
	
	Image *output = NULL;

	int counter;
    double distance;
	unsigned char *centers = (unsigned char *)malloc(3 * num);
	unsigned char *pcenters = (unsigned char *)malloc(3 * num);

	//
	// 画像データのバイト数の定義
	//
	int n = width * height * 3;

	//
	// 新しい画像データのためにメモリを確保する
	//
	unsigned char *image2 = (unsigned char *)malloc(sizeof(unsigned char) * width * height * 3);
	int *idarray = (int *)malloc(sizeof(int) * width * height);

	//
	// num個の中心点の初期値を算出する
	//
	initCenters(centers, num);

	//
	// 収束するまでクラスタリングを反復する
	//
	for(counter = 1; ; counter++) {
		assignPixels(image1, image2, idarray, width, height, centers, num);
		distance = calcNewCenter(image1, image2, idarray, width, height, centers, pcenters, num);
		printf("### counter=%d  distance=%f\n", counter, distance);
		if(distance <= num * 1.0 || counter > 100) break;
		memcpy(centers, pcenters, (sizeof(unsigned char) * 3 * num));
	}

	//
	// 新しい画像データを返す
	//
	*iarray = idarray;
    *colormap = centers;
	output = malloc(sizeof(Image));
	output->image = image2;
	output->width = width;
	output->height = height;
	return output;


}


