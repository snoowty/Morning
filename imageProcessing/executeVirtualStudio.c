#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvProgramming.h"

//
// 画像処理の例：バーチャルスタジオ風の画像合成
//
Image *executeVirtualStudio(Image *input1, Image *input2, Image *input0) { 

	unsigned char *image1 = input1->image;
	unsigned char *image2 = input2->image;
	unsigned char *image0 = input0->image;
	int width1 = input1->width;
	int width2 = input2->width;
	int height1 = input1->height;
	int height2 = input2->height;
	
	Image *output = NULL;

	int width  = (width1  > width2)  ? width1  : width2;
	int height = (height1 > height2) ? height1 : height2;
	int i, j, n1, n2;



	//
	// 画像データのバイト数の定義
	//
	int n = width * height * 3;

	//
	// 新しい画像データのためにメモリを確保する
	//
	unsigned char *image3 = (unsigned char *)malloc(sizeof(unsigned char) * n);

	//
	// 新しい画像データの画素値を初期化する
	//
	for(i = 0; i < n; i++) 
		image3[i] = (unsigned char)0;

	//
	// 各スキャンラインごとに
	//
	for(i = 0, n = 0, n1 = 0, n2 = 0; i < height; i++) {

		//
		// 各画素ごとに
		//
		for(j = 0; j < width; j++, n += 3) {
			unsigned char flag = 0;

			//
			// image1の画素値を参照
			//
			if(i < height1 && j < width1) {
				if(image0[n1] > 0 || image0[n1 + 1] > 0 || image0[n1 + 2] > 0) {

					//
					// 新しい画像にimage1の画素値を代入
					//
					image3[n]     = image1[n1];
					image3[n + 1] = image1[n1 + 1];
					image3[n + 2] = image1[n1 + 2];

					//
					// flag=1であれば、image1の画素値を代入済みである
					//
					flag = 1;
				}
				n1 += 3;
			}

			//
			// image2の画素値を参照
			//
			if(i < height2 && j < width2) {
				if(flag != 1) {

					//
					// 新しい画像にimage2の画素値を代入
					//
					image3[n]     = image2[n2];
					image3[n + 1] = image2[n2 + 1];
					image3[n + 2] = image2[n2 + 2];

				}
				n2 += 3;
			}
		}
	}


	//
	// 新しい画像データを返す
	//
	output = malloc(sizeof(Image));
	output->image = image3;
	output->width = width;
	output->height = height;
	return output;

}