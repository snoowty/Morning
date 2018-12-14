#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvProgramming.h"

//
// �摜�����̗��F�o�[�`�����X�^�W�I���̉摜����
//
Image *executeAlphaBlending(Image *input1, Image *input2, Image *input0) {

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
	// �摜�f�[�^�̃o�C�g���̒��`
	//
	int n = width * height * 3;

	//
	// �V�����摜�f�[�^�̂��߂Ƀ��������m�ۂ���
	//
	unsigned char *image3 = (unsigned char *)malloc(sizeof(unsigned char) * n);

	//
	// �V�����摜�f�[�^�̉��f�l������������
	//
	for(i = 0; i < n; i++)
		image3[i] = (unsigned char)0;

	//
	// �e�X�L�������C�����Ƃ�
	//
	for(i = 0, n = 0, n1 = 0, n2 = 0; i < height; i++) {

		//
		// �e���f���Ƃ�
		//
		for(j = 0; j < width; j++, n += 3) {
			unsigned char flag = 0;

			//
			// image1�̉��f�l���Q��
			//
			if(i < height1 && j < width1) {
				if(image0[n1] > 0 || image0[n1 + 1] > 0 || image0[n1 + 2] > 0) {

					//
					// �V�����摜��image1�̉��f�l������
					//
					if(width1 > width2 && height1 > height2){
					image3[n]     = image1[n1];
					image3[n + 1] = image1[n1 + 1];
					image3[n + 2] = image1[n1 + 2];
				}else{
					double x = 0.3;
					// アルファブレンディング処理
					image3[n] = x * image1[n1] + (1-x) * image2[n2];
					image3[n + 1] = x * image1[n1 + 1] + (1-x) * image2[n2 + 1];
					image3[n + 2] = x * image1[n1 + 2] + (1-x) * image2[n2 + 2];
				}
					//
					// flag=1�ł����΁Aimage1�̉��f�l�������ς݂ł���
					//
					flag = 1;
				}
				n1 += 3;
			}

			//
			// image2�̉��f�l���Q��
			//
			if(i < height2 && j < width2) {
				if(flag != 1) {

					//
					// �V�����摜��image2�̉��f�l������
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
	// �V�����摜�f�[�^���Ԃ�
	//
	output = malloc(sizeof(Image));
	output->image = image3;
	output->width = width;
	output->height = height;
	return output;

}
