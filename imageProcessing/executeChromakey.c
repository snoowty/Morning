#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvProgramming.h"

//
// 画像処理の例：クロマキー処理
//
Image *executeChromakey(Image *input1, int *iarray, int id) {

	unsigned char *image1 = input1->image;
	int width = input1->width;
	int height = input1->height;
	
	Image *output = NULL;

	int i, j, n3;

	//
	// 画像データのバイト数の定義
	//
	int n = width * height * 3;

	//
	// 新しい画像データのためにメモリを確保する
	//
	unsigned char *image2 = (unsigned char *)malloc(sizeof(unsigned char) * n);
	
	//
	// 各スキャンラインごとに
	//
	for(i = 0, n = 0, n3 = 0; i < height; i++) {

		//
		// 各画素ごとに
		//
		for(j = 0; j < width; j++, n++, n3 += 3) {
		
			if(iarray[n] == id)
				image2[n3] = image2[n3 + 1] = image2[n3 + 2] = (unsigned char)0;
			else {
				image2[n3] = image2[n3 + 1] = image2[n3 + 2] = (unsigned char)255;
			}

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
