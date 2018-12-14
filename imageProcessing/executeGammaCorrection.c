#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cvProgramming.h"

//
// �摜�����̗��F�Z�W�𔽓]����
//
Image *executeGammaCorrection(Image *input1) {

	unsigned char *image1 = input1->image;
	int width = input1->width;
	int height = input1->height;

	Image *output = NULL;

	int i;

	//
	// �摜�f�[�^�̃o�C�g���̒��`
	//
	int n = width * height * 3;

double g_R = 4.5;
double g_G = 2;
double g_B = 0.3;
	//
	// �V�����摜�f�[�^�̂��߂Ƀ��������m�ۂ���
	//
	unsigned char *image2 = (unsigned char *)malloc(sizeof(unsigned char) * n);

	//
	// �e�o�C�g�̒l���AR=255-R, G=255-G, B=255-B �ɂ����Ĕ��]����
	//
	for(i = 0; i < n; i++) {
		//image2[i] = 255 - image1[i];
		int R = image1[3*i];
		int G = image1[3*i+1];
		int B = image1[3*i+2];

		image2[3*i] = 255 * pow((double)R/255.0, 1.0/g_R);
		image2[3*i+1] = 255 * pow((double)G/255.0, 1.0/g_G);
		image2[3*i+2] = 255 * pow((double)B/255.0, 1.0/g_B);

	}

	//
	// �V�����摜�f�[�^���Ԃ�
	//
	output = malloc(sizeof(Image));
	output->image = image2;
	output->width = width;
	output->height = height;
	return output;

}
