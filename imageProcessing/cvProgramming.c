#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "cvProgramming.h"



//
// 4�`6�͂̉ۑ��Ɋւ��镔��
//
void imageProcessing1() {

	//
	// ���łɎ����Ă���BMP�摜�t�@�C���̖��O������
	//
	char *filename1 = "itot.bmp";

	//
	// ���ꂩ���쐬����BMP�摜�t�@�C���̖��O������
	//
	char *filename2 = "copy.bmp";

	//
	// �摜�f�[�^�{��
	//
	Image *image1, *image2;

	//
	// BMP�摜�t�@�C�����ǂݍ���
	//
	image1 = readBmpFile(filename1);

	//
	// �摜�����F
	// �ȉ��̊֐��̂��������ꂩ���L���ɂ��āA�c�����R�����g����
	//
	{
//	image2 = executeNegative(image1);
//	image2 = executeBinalization(image1);
	image2 = executeGammaCorrection(image1);
	//image2 = executeSpaceFiltering(image1);
	//image2 = executeScale(image1);
    //image2 = executeRotation(image1);
	}

	//
	// BMP�摜�t�@�C���������o��
	//
	writeBmpFile(filename2, image2);

}



//
// 7�͂̉ۑ��Ɋւ��镔��
//
void imageProcessing2() {

	//
	// ���łɎ����Ă���BMP�摜�t�@�C���̖��O������
	//
	char *filename1a = "itot.bmp";
	char *filename1b = "ochatop.bmp";

	//
	// ���ꂩ���쐬����BMP�摜�t�@�C���̖��O������
	//
	char *filename2 = "copy.bmp";

	//
	// �摜�f�[�^�{��
	//
	Image *image1, *image2, *image3, *image0;

	//
	// BMP�摜�t�@�C�����ǂݍ���
	//
	image1 = readBmpFile(filename1a);
	image2 = readBmpFile(filename1b);

	//
	// �摜image1a�ɑ΂��āAK-means�@�����уN���}�L�[���K�p����
	//
	{
		unsigned char *colormap;
		int *iarray;
		executeKMeans(image1, 6, &iarray, &colormap);
		image0 = executeChromakey(image1, iarray, 2);
	}

	//
	// �摜����������
	//
	//image3 = executeVirtualStudio(image1, image2, image0);
	image3 = executeAlphaBlending(image1, image2, image0);
    //image3 = executeTiling(image1, image2);


	//
	// �摜�������ʂ��t�@�C���ɏ�������
	//
	writeBmpFile(filename2, image3);

}


//
// main�֐�
//
void main(int argc, char **argv) {

	//
	// 4�`6�͂̉ۑ��ɒ��肷���Ƃ��́A���������L���ɂ���
	//
	imageProcessing1();

	//
	// 7�͂̉ۑ��ɒ��肷���Ƃ��́A���������L���ɂ���
	//
	//imageProcessing2();

}
