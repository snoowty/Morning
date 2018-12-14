#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvProgramming.h"

//
// 空間フィルタリングを適用する配列
//
static double filter[9] = {
	0.33333,0,0,0,0.33333,0,0,0,0.33333
};


//
// 空間フィルタリングを用いた画像処理の例
//
Image *executeSpaceFiltering(Image *input1) {
	
	unsigned char *image1 = input1->image;
	int width = input1->width;
	int height = input1->height;
	
	Image *output = NULL;

	int i, j, n1, n2;

	//
	// 画像データのバイト数の定義
	//
	int n = width * height * 3;

	//
	// 新しい画像データのためにメモリを確保する
	//
	unsigned char *image2 = (unsigned char *)malloc(sizeof(unsigned char) * width * height * 3);

	//
	// 各スキャンラインごとに
	//
	for(i = 0, n1 = 0; i < height; i++) {

		//
		// 各画素ごとに
		//
		for(j = 0; j < width; j++, n1 += 3) {
			double valueR = 0.0, valueG = 0.0, valueB = 0.0;

			//
			// 左上の画素値を加算
			//
			if(i > 0 && j > 0) {
				n2 = 3 * ((i - 1) * width + (j - 1));
				valueR += (double)image1[n2 + 0] * filter[0];
				valueG += (double)image1[n2 + 1] * filter[0];
				valueB += (double)image1[n2 + 2] * filter[0];
			}

			//
			// 上の画素値を加算
			//
			if(i > 0) {
				n2 = 3 * ((i - 1) * width + j);
				valueR += (double)image1[n2 + 0] * filter[1];
				valueG += (double)image1[n2 + 1] * filter[1];
				valueB += (double)image1[n2 + 2] * filter[1];
			}

			//
			// 右上の画素値を加算
			//
			if(i > 0 && j < (width - 1)) {
				n2 = 3 * ((i - 1) * width + (j + 1));
				valueR += (double)image1[n2 + 0] * filter[2];
				valueG += (double)image1[n2 + 1] * filter[2];
				valueB += (double)image1[n2 + 2] * filter[2];
			}

			//
			// 左の画素値を加算
			//
			if(j > 0) {
				n2 = 3 * (i * width + (j - 1));
				valueR += (double)image1[n2 + 0] * filter[3];
				valueG += (double)image1[n2 + 1] * filter[3];
				valueB += (double)image1[n2 + 2] * filter[3];
			}

			//
			// 同一場所のの画素値を加算
			//
			n2 = 3 * (i * width + j);
			valueR += (double)image1[n2 + 0] * filter[4];
			valueG += (double)image1[n2 + 1] * filter[4];
			valueB += (double)image1[n2 + 2] * filter[4];
		
			//
			// 右の画素値を加算
			//
			if(j < (width - 1)) {
				n2 = 3 * (i * width + (j + 1));
				valueR += (double)image1[n2 + 0] * filter[5];
				valueG += (double)image1[n2 + 1] * filter[5];
				valueB += (double)image1[n2 + 2] * filter[5];
			}

			//
			// 左下の画素との比較
			//
			if(i < (height - 1) && j > 0) {
				n2 = 3 * ((i + 1) * width + (j - 1));
				valueR += (double)image1[n2 + 0] * filter[6];
				valueG += (double)image1[n2 + 1] * filter[6];
				valueB += (double)image1[n2 + 2] * filter[6];
			}

			//
			// 下の画素との比較
			//
			if(i < (height - 1)) {
				n2 = 3 * ((i + 1) * width + j);
				valueR += (double)image1[n2 + 0] * filter[7];
				valueG += (double)image1[n2 + 1] * filter[7];
				valueB += (double)image1[n2 + 2] * filter[7];
			}

			//
			// 右下の画素との比較
			//
			if(i < (height - 1) && j < (width - 1)) {
				n2 = 3 * ((i + 1) * width + (j + 1));
				valueR += (double)image1[n2 + 0] * filter[8];
				valueG += (double)image1[n2 + 1] * filter[8];
				valueB += (double)image1[n2 + 2] * filter[8];
			}

			// valueR, valueG, valueB の値を0～255の範囲にする
			if(valueR < 0.0) valueR = 0.0;
			if(valueR > 255.0) valueR =255.0;
			if(valueG < 0.0) valueG = 0.0;
			if(valueG > 255.0) valueG =255.0;
			if(valueB < 0.0) valueB = 0.0;
			if(valueB > 255.0) valueB =255.0;

			// image2にRGB値を代入する
			image2[n1 + 0] = (unsigned char)valueR;
			image2[n1 + 1] = (unsigned char)valueG;
			image2[n1 + 2] = (unsigned char)valueB;


		}
	}




	//
	// 新しい画像データを返す
	//
	output = malloc(sizeof(Image));
	output->image = image2;
	output->width = width;
	output->height = height;
	return output;

}