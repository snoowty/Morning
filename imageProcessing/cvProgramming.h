#ifndef _CVPROGRAMMING_H_
#define _CVPROGRAMMING_H_

//
// �摜��RGB�l���i�[����z��A����щ��E�c�̉�f���A���i�[����\����
//
typedef struct Image 
{
  unsigned char *image;
  int width;
  int height;
} Image;




//
// ���炩���ߊ֐���ϐ����`���Ă���
//
void writeBmpFile(char *filename, Image *image);
Image *readBmpFile(char *filename);

Image *executeNegative(Image *image1);
Image *executeBinalization(Image *image1);
Image *executeGammaCorrection(Image *image1);
Image *executeSpaceFiltering(Image *image1);

Image *executeScale(Image *image1);
Image *executeRotation(Image *image1);

Image *executeKMeans(Image *image1, int num,
		     int **iarray, unsigned char **colormap);
Image *executeChromakey(Image *image1, int *iarray, int id);
Image *executeVirtualStudio(Image *image1, Image *image2, Image *image3);
Image *executeAlphaBlending(Image *image1, Image *image2, Image *image3);
Image *executeTiling(Image *image1, Image *image2);

#endif
