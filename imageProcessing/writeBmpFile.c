#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvProgramming.h"


static int reverseInteger(int origin) {
	int ret;
	if( origin < 256 ) {
		ret = 16777216 * origin;
	}
	else if( origin < 65536 ) {
		int r1 = origin / 256;
		int r2 = origin % 256;
		ret = 16777216 * r2 + 65536 * r1;
	}
	else if( origin < 16777216 ) {
		int r1 = origin / 65536;
		int r2 = (origin - r1) / 256;
		int r3 = origin % 256;
		ret = 16777216 * r3 + 65536 * r2 + 256 * r1;
	}
	else {
		int r1 = origin / 16777216;
		int r2 = (origin - r1) / 65536;
		int r3 = (origin - r1 - r2) / 256;
		int r4 = origin % 256;
		ret = 16777216 * r4 + 65536 * r3 + 256 * r2 + r1;
	}

	return ret;
}






//
// ファイル名、画像データ、幅、高さを与えられたとき、
// BMP形式で画像データをファイルに保存する
//
void writeBmpFile(char *filename, Image *input) {
	FILE *fp;
	int i, j, count1, count2;
	
	char bfType[2] = {'B', 'M'};
	short bfReserved1 = 0, bfReserved2 = 0;
	int   bfSize; 
#ifdef _INTEL
	int   bfOffBits = 54;
	int   biSize = 40;
	unsigned short biPlanes = 1;
    unsigned short biBitCount = 24;
#else
	int   bfOffBits = 905969664; //54
	int   biSize = 671088640; //40
	unsigned short biPlanes = 256; //1
    unsigned short biBitCount = 6144; //24
#endif
	int biCompression = 0;
    int biSizeImage = 0;
    int biXPixPerMeter = 0;
    int biYPixPerMeter = 0;
    int biClrUsed = 0;
    int biCirImportant = 0;
	int bfSize2, biWidth2, biHeight2;

	unsigned char *image = input->image;
	int biWidth = input->width;
	int biHeight = input->height;


	//
	// ファイルサイズの算出
	//
	if(biWidth % 4 == 0)
		bfSize = biWidth * biHeight * 3 + 54;
	else {
		count1 = biWidth * 3 - (biWidth * 3 % 4) + 4;
		bfSize = count1 * biHeight + 54;
	}

#ifdef _INTEL
	bfSize2 = bfSize;  biWidth2 = biWidth;  biHeight2 = biHeight;
#else
    bfSize2 = reverseInteger(bfSize);
	biWidth2 = reverseInteger(biWidth);
	biHeight2 = reverseInteger(biHeight);
#endif	

	//
	// ファイルオープン
	//
	if ((fp = fopen(filename, "wb"))==NULL) {
		printf("writeBmp: Open error!\n");
		exit(1);
	}

	//
	// ヘッダー情報のファイルへの保存
	//
	fwrite(&bfType, sizeof(bfType), 1, fp);
	fwrite(&bfSize2, sizeof(bfSize2), 1, fp);
	fwrite(&bfReserved1, sizeof(bfReserved1), 1, fp);
	fwrite(&bfReserved2, sizeof(bfReserved2), 1, fp);
	fwrite(&bfOffBits, sizeof(bfOffBits), 1, fp);

	fwrite(&biSize, sizeof(biSize), 1, fp);
	fwrite(&biWidth2, sizeof(biWidth2), 1, fp);
	fwrite(&biHeight2, sizeof(biHeight2), 1, fp);
	fwrite(&biPlanes, sizeof(biPlanes), 1, fp);
	fwrite(&biBitCount, sizeof(biBitCount), 1, fp);
	fwrite(&biCompression, sizeof(biCompression), 1, fp);
	fwrite(&biSizeImage, sizeof(biSizeImage), 1, fp);
	fwrite(&biXPixPerMeter, sizeof(biXPixPerMeter), 1, fp);
	fwrite(&biYPixPerMeter, sizeof(biYPixPerMeter), 1, fp);
	fwrite(&biClrUsed, sizeof(biClrUsed), 1, fp);
	fwrite(&biCirImportant, sizeof(biCirImportant), 1, fp);

	//
	// 画像データ本体のファイルへの保存
	//
	for (i = biHeight - 1; i >= 0; i--) {
	  count1 = i * biWidth * 3;
	  for (j = 0, count2 = 0; j < biWidth; j++) {
		  fwrite(&image[count1 + 2], 1, 1, fp);
		  fwrite(&image[count1 + 1], 1, 1, fp);
		  fwrite(&image[count1 + 0], 1, 1, fp);
		  count1 += 3;   count2 += 3;
	  }
	  if(count2 % 4 != 0) {
		unsigned char dummy = (unsigned char)0;
		while(count2 % 4 != 0) {  
		  fwrite(&dummy, 1, 1, fp);  count2++;
		}
	  }
	}
	
	//
	// ファイルクローズ
	//
	fclose(fp);

}

