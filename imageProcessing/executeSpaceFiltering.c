#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvProgramming.h"

//
// ��ԃt�B���^�����O��K�p����z��
//
static double filter[9] = {
	0.33333,0,0,0,0.33333,0,0,0,0.33333
};


//
// ��ԃt�B���^�����O��p�����摜�����̗�
//
Image *executeSpaceFiltering(Image *input1) {
	
	unsigned char *image1 = input1->image;
	int width = input1->width;
	int height = input1->height;
	
	Image *output = NULL;

	int i, j, n1, n2;

	//
	// �摜�f�[�^�̃o�C�g���̒�`
	//
	int n = width * height * 3;

	//
	// �V�����摜�f�[�^�̂��߂Ƀ��������m�ۂ���
	//
	unsigned char *image2 = (unsigned char *)malloc(sizeof(unsigned char) * width * height * 3);

	//
	// �e�X�L�������C�����Ƃ�
	//
	for(i = 0, n1 = 0; i < height; i++) {

		//
		// �e��f���Ƃ�
		//
		for(j = 0; j < width; j++, n1 += 3) {
			double valueR = 0.0, valueG = 0.0, valueB = 0.0;

			//
			// ����̉�f�l�����Z
			//
			if(i > 0 && j > 0) {
				n2 = 3 * ((i - 1) * width + (j - 1));
				valueR += (double)image1[n2 + 0] * filter[0];
				valueG += (double)image1[n2 + 1] * filter[0];
				valueB += (double)image1[n2 + 2] * filter[0];
			}

			//
			// ��̉�f�l�����Z
			//
			if(i > 0) {
				n2 = 3 * ((i - 1) * width + j);
				valueR += (double)image1[n2 + 0] * filter[1];
				valueG += (double)image1[n2 + 1] * filter[1];
				valueB += (double)image1[n2 + 2] * filter[1];
			}

			//
			// �E��̉�f�l�����Z
			//
			if(i > 0 && j < (width - 1)) {
				n2 = 3 * ((i - 1) * width + (j + 1));
				valueR += (double)image1[n2 + 0] * filter[2];
				valueG += (double)image1[n2 + 1] * filter[2];
				valueB += (double)image1[n2 + 2] * filter[2];
			}

			//
			// ���̉�f�l�����Z
			//
			if(j > 0) {
				n2 = 3 * (i * width + (j - 1));
				valueR += (double)image1[n2 + 0] * filter[3];
				valueG += (double)image1[n2 + 1] * filter[3];
				valueB += (double)image1[n2 + 2] * filter[3];
			}

			//
			// ����ꏊ�̂̉�f�l�����Z
			//
			n2 = 3 * (i * width + j);
			valueR += (double)image1[n2 + 0] * filter[4];
			valueG += (double)image1[n2 + 1] * filter[4];
			valueB += (double)image1[n2 + 2] * filter[4];
		
			//
			// �E�̉�f�l�����Z
			//
			if(j < (width - 1)) {
				n2 = 3 * (i * width + (j + 1));
				valueR += (double)image1[n2 + 0] * filter[5];
				valueG += (double)image1[n2 + 1] * filter[5];
				valueB += (double)image1[n2 + 2] * filter[5];
			}

			//
			// �����̉�f�Ƃ̔�r
			//
			if(i < (height - 1) && j > 0) {
				n2 = 3 * ((i + 1) * width + (j - 1));
				valueR += (double)image1[n2 + 0] * filter[6];
				valueG += (double)image1[n2 + 1] * filter[6];
				valueB += (double)image1[n2 + 2] * filter[6];
			}

			//
			// ���̉�f�Ƃ̔�r
			//
			if(i < (height - 1)) {
				n2 = 3 * ((i + 1) * width + j);
				valueR += (double)image1[n2 + 0] * filter[7];
				valueG += (double)image1[n2 + 1] * filter[7];
				valueB += (double)image1[n2 + 2] * filter[7];
			}

			//
			// �E���̉�f�Ƃ̔�r
			//
			if(i < (height - 1) && j < (width - 1)) {
				n2 = 3 * ((i + 1) * width + (j + 1));
				valueR += (double)image1[n2 + 0] * filter[8];
				valueG += (double)image1[n2 + 1] * filter[8];
				valueB += (double)image1[n2 + 2] * filter[8];
			}

			// valueR, valueG, valueB �̒l��0�`255�͈̔͂ɂ���
			if(valueR < 0.0) valueR = 0.0;
			if(valueR > 255.0) valueR =255.0;
			if(valueG < 0.0) valueG = 0.0;
			if(valueG > 255.0) valueG =255.0;
			if(valueB < 0.0) valueB = 0.0;
			if(valueB > 255.0) valueB =255.0;

			// image2��RGB�l��������
			image2[n1 + 0] = (unsigned char)valueR;
			image2[n1 + 1] = (unsigned char)valueG;
			image2[n1 + 2] = (unsigned char)valueB;


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