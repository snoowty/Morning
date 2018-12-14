#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvProgramming.h"

//
// 画像処理の例：濃淡を反転する
//
Image *executeNegative(Image *input1) {

	unsigned char *image1 = input1->image;
	int width = input1->width;
	int height = input1->height;
	
	Image *output = NULL;

	int i;

	//
	// 画像データのバイト数の定義
	//
	int n = width * height * 3;

	//
	// 新しい画像データのためにメモリを確保する
	//
	unsigned char *image2 = (unsigned char *)malloc(sizeof(unsigned char) * n);

	//
	// 各バイトの値を、R=255-R, G=255-G, B=255-B によって反転する
	//
	for(i = 0; i < n; i++) {
		image2[i] = 255 - image1[i];
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

