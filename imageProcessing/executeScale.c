#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cvProgramming.h"

//
// ����define�s�ŁA�������A�c�����A�̔{�����`����
//
#define SCALEX (2.0)
#define SCALEY (3.0)



//
// ���摜�̑Ή�����X���W�l���Z�o����
//
static double calcX(int x2, int y2, int width1, int height1) {
	double x = 0.0;

	//
	// �t�ϊ��Ȃ̂ŁA�摜�̔{���̋t�������߂�
	//
	x = x2 / SCALEX;

	//
	// ���摜�͈͓̔��Ɏ��܂��Ă��邩�ǂ����m�F����
	//
	if(x < 0.0 || x > (double)width1) {
		printf("EXIT!  x=%f\n", x);
		exit(-1);
	}

	return x;
}


//
// ���摜�̑Ή�����Y���W�l���Z�o����
//
static double calcY(int x2, int y2, int width1, int height1) {
	double y = 0.0;

	//
	// �t�ϊ��Ȃ̂ŁA�摜�̔{���̋t�������߂�
	//
	y = y2 / SCALEY;

	//
	// ���摜�͈͓̔��Ɏ��܂��Ă��邩�ǂ����m�F����
	//
	if(y < 0.0 || y > (double)height1) {
		printf("EXIT!  y=%f\n", y);
		exit(-1);
	}

	return y;
}


//
// ���摜�̈ʒu(x1,y1)�ɂ�����RGB�l���Z�o����
// �i���̃v���O�����ł� Nearest Neighbor ���̗p����j
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
// �摜�̊g��k�����s��
//
Image *executeScale(Image *input1) {

	unsigned char *image1 = input1->image;
	int width = input1->width;
	int height = input1->height;
	
	Image *output = NULL;

	int width1, height1, width2, height2, n, i, j;
	unsigned char *image2;


	//
	// ���摜�ƐV�摜�̃T�C�Y���`����
	//
	width1 = width;
	height1 = height;
	width2 = width = (int)(width1 * SCALEX);
	height2 = height = (int)(height1 * SCALEY);

	//
	// �V�����摜�f�[�^�̃o�C�g���̒�`
	//
	n = width2 * height2 * 3;

	//
	// �V�����摜�f�[�^�̂��߂Ƀ��������m�ۂ���
	//
	image2 = (unsigned char *)malloc(sizeof(unsigned char) * n);

	//
	// �V�����摜�̊e�X�L�������C�����Ƃ�
	//
	for(i = 0, n = 0; i < height2; i++) {

		//
		// �V�����摜�̊e��f���Ƃ�
		//
		for(j = 0; j < width2; j++, n += 3) {
			double x1, y1, r, g, b;
			
			//
			// ���摜�̑Ή�����x,y���W�l���v�Z����
			//
			x1 = calcX(j, i, width1, height1);
			y1 = calcY(j, i, width1, height1);

			//
			// ���摜����RGB�l���Z�o����
			//
			calcRGB(image1, x1, y1, width1, height1, &r, &g, &b);

			//
			// �V�����摜��RGB�l��������
			//
			image2[n + 0] = (unsigned char)r;
			image2[n + 1] = (unsigned char)g;
			image2[n + 2] = (unsigned char)b;

		}
	}

	//
	// �V�����摜�f�[�^��Ԃ�
	//
	output = malloc(sizeof(Image));
	output->image = image2;
	output->width = width;
	output->height = height;
	return output;

}
