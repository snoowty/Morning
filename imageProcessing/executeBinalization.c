#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvProgramming.h"

//
// �摜�����̗��F�Z�W�𔽓]����
//
Image *executeBinalization(Image *input1) {

	unsigned char *image1 = input1->image;
	int width = input1->width;
	int height = input1->height;

	Image *output = NULL;

	int i;
	int j;

	//
	// �摜�f�[�^�̃o�C�g���̒��`
	//
	int n = width * height * 3;

	int sum = 0;
	int s = 220;

	//
	// �V�����摜�f�[�^�̂��߂Ƀ��������m�ۂ���
	//
	unsigned char *image2 = (unsigned char *)malloc(sizeof(unsigned char) * n);

	//
	// �e�o�C�g�̒l���AR=255-R, G=255-G, B=255-B �ɂ����Ĕ��]����
	//

	for(i = 0; i < n; i++) {
		//image2[i] = 255 - image1[i];
		sum = image1[3*i] + image1[3*i+1] + image1[3*i+2];
		//printf("%d\n", sum);
		if(sum >= s) {
			image2[3*i] = 255;
			image2[3*i+1] = 255;
			image2[3*i+2] = 255;
		}else{
			image2[3*i] = 0;
			image2[3*i+1] = 0;
			image2[3*i+2] = 0;
		}
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
