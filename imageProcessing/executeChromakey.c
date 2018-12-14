#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvProgramming.h"

//
// �摜�����̗�F�N���}�L�[����
//
Image *executeChromakey(Image *input1, int *iarray, int id) {

	unsigned char *image1 = input1->image;
	int width = input1->width;
	int height = input1->height;
	
	Image *output = NULL;

	int i, j, n3;

	//
	// �摜�f�[�^�̃o�C�g���̒�`
	//
	int n = width * height * 3;

	//
	// �V�����摜�f�[�^�̂��߂Ƀ��������m�ۂ���
	//
	unsigned char *image2 = (unsigned char *)malloc(sizeof(unsigned char) * n);
	
	//
	// �e�X�L�������C�����Ƃ�
	//
	for(i = 0, n = 0, n3 = 0; i < height; i++) {

		//
		// �e��f���Ƃ�
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
	// �V�����摜�f�[�^��Ԃ�
	//
	output = malloc(sizeof(Image));
	output->image = image2;
	output->width = width;
	output->height = height;
	return output;

}
