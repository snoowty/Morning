#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cvProgramming.h"

//
// このdefine行で、横方向、縦方向、の倍率を定義する
//
#define SCALEX (2.0)
#define SCALEY (3.0)



//
// 元画像の対応するX座標値を算出する
//
static double calcX(int x2, int y2, int width1, int height1) {
	double x = 0.0;

	//
	// 逆変換なので、画像の倍率の逆数を求める
	//
	x = x2 / SCALEX;

	//
	// 元画像の範囲内に収まっているかどうか確認する
	//
	if(x < 0.0 || x > (double)width1) {
		printf("EXIT!  x=%f\n", x);
		exit(-1);
	}

	return x;
}


//
// 元画像の対応するY座標値を算出する
//
static double calcY(int x2, int y2, int width1, int height1) {
	double y = 0.0;

	//
	// 逆変換なので、画像の倍率の逆数を求める
	//
	y = y2 / SCALEY;

	//
	// 元画像の範囲内に収まっているかどうか確認する
	//
	if(y < 0.0 || y > (double)height1) {
		printf("EXIT!  y=%f\n", y);
		exit(-1);
	}

	return y;
}


//
// 元画像の位置(x1,y1)におけるRGB値を算出する
// （このプログラムでは Nearest Neighbor を採用する）
//
static void calcRGB(unsigned char *image1, double x1, double y1,
		    int width1, int height1,
		    double *r, double *g, double *b) {

	int xx = (int)(x1 + 0.5);
	if(xx < 0) xx = 0;
	if(xx >= width1) xx = width1 - 1;
	int yy = (int)(y1 + 0.5);
	if(yy < 0) yy = 0;
	if(yy >= height1) yy = height1 - 1;

	int n = 3 * ((yy * width1) + xx);

	*r = (double)image1[n + 0];
	*g = (double)image1[n + 1];
	*b = (double)image1[n + 2];

}

//
// 画像の拡大縮小を行う
//
Image *executeScale(Image *input1) {

	unsigned char *image1 = input1->image;
	int width = input1->width;
	int height = input1->height;
	
	Image *output = NULL;

	int width1, height1, width2, height2, n, i, j;
	unsigned char *image2;


	//
	// 元画像と新画像のサイズを定義する
	//
	width1 = width;
	height1 = height;
	width2 = width = (int)(width1 * SCALEX);
	height2 = height = (int)(height1 * SCALEY);

	//
	// 新しい画像データのバイト数の定義
	//
	n = width2 * height2 * 3;

	//
	// 新しい画像データのためにメモリを確保する
	//
	image2 = (unsigned char *)malloc(sizeof(unsigned char) * n);

	//
	// 新しい画像の各スキャンラインごとに
	//
	for(i = 0, n = 0; i < height2; i++) {

		//
		// 新しい画像の各画素ごとに
		//
		for(j = 0; j < width2; j++, n += 3) {
			double x1, y1, r, g, b;
			
			//
			// 元画像の対応するx,y座標値を計算する
			//
			x1 = calcX(j, i, width1, height1);
			y1 = calcY(j, i, width1, height1);

			//
			// 元画像からRGB値を算出する
			//
			calcRGB(image1, x1, y1, width1, height1, &r, &g, &b);

			//
			// 新しい画像にRGB値を代入する
			//
			image2[n + 0] = (unsigned char)r;
			image2[n + 1] = (unsigned char)g;
			image2[n + 2] = (unsigned char)b;

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
