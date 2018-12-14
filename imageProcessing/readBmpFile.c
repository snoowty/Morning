#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvProgramming.h"


//
// �֐��̎g�����Ɋւ���\��
//
void usage(char *cmdname)
{
  fprintf(stderr,
          "\n"
          "�r�b�g�}�b�v�t�@�C�� ---> �e�L�X�g�_���v �v���O����\n"
          "Usage : %s bmp_file [text_file]\n"
          "  bmp_file  : �r�b�g�}�b�v�t�@�C��\n"
          "              (�����k 4, 8, 24, 32bit �̂ݑΉ�)\n"
          "  text_file : �w�肵�Ȃ��ꍇ \"bmp_file.txt\" ���o�͂���܂�\n"
          "\n"
          "  �o�͌`�� : �e�F 0�`255\n"
          "\tRed Green Blue\n"
          "\tRed Green Blue\n"
          "\t :    :    :\n"
          "\n"
          "  �摜�̃T�C�Y�ɂ���ă_���v�t�@�C�������Ȃ�傫���Ȃ�̂�\n"
          "  ���ӂ��Ă�������\n" "\n", cmdname);
  exit(1);
}


//
// �t�@�C�����擾
//
int getbasename(char *dest, char *src)
{
  int i, start, end, ret;

  i = -1;
  start = 0;
  end = 0;

  //
  // �t�@�C�����̂͂��߂ƏI�������o
  //
  while (src[++i]) {
    if (src[i] == '\\' || src[i] == ':') {
      start = i + 1;
      end = 0;
    }
    if (src[i] == '.') {
      end = i;
    }
  }
  if (end == 0) {
    end = i;
  }

  //
  // �t�@�C�������L��ꍇ
  //
  if (start < end) {
    for (i = 0; i < end; i++) {
      dest[i] = src[i];
    }
    dest[i] = '\0';
    ret = 1;
  } 

  //
  // �t�@�C�����������ꍇ
  //
  else {
    dest[0] = '\0';
    ret = 0;
  }

  return ret;
}


//
// �t�@�C���w�b�_��(14 Byte)�̓ǂݍ���
//
int fileheader(FILE * fp, int *offset)
{
  int count = 0;
  int var_long;
  short var_short;
  char s[10];
  unsigned char c1, c2, c3, c4;

  //
  // BITMAP �F������ "BM"
  //
  if (fread(s, 2, 1, fp) == 1) {
    if (memcmp(s, "BM", 2) == 0) {
      printf("[BM] BITMAP file\n");
    } 
    else {
      fprintf(stderr, "%s : Not a BITMAP file\n", s);
      exit(1);
    }
    count += 2;
  }
  printf("  [BITMAPFILEHEADER]\n");

  //
  // �t�@�C���T�C�Y
  //
  if (fread(&var_long, 4, 1, fp) == 1) {
    //printf("  Size          : %ld [Byte]\n", var_long);
    count += 4;
  }

  //
  // �\��̈� 0
  //
  if (fread(&var_short, 2, 1, fp) == 1) {
    count += 2;
  }

  //
  // �\��̈� 0
  //
  if (fread(&var_short, 2, 1, fp) == 1) {
    count += 2;
  }

  //
  // �t�@�C���̐擪����摜�f�[�^�܂ł̈ʒu
  //
#ifdef _WIN32
  if (fread(&var_long, 4, 1, fp) == 1) {
    printf("  OffBits       : %ld [Byte]\n", var_long);
    *offset = var_long;
    count += 4;
  }
#else
  fread(&c1, 1, 1, fp);
  fread(&c2, 1, 1, fp);
  fread(&c3, 1, 1, fp);
  fread(&c4, 1, 1, fp);
  *offset = 256 * (256 * (256 * (int)c4 + (int)c3) + (int)c2) + (int)c1;
  printf("  OffBits       : %ld [Byte]\n", *offset);
  count += 4;
#endif

  //
  // �o�C�g����Ԃ�
  //
  return count;
}


//
// ���w�b�_��(40Byte)�̓ǂݍ���
//
int infoheader(FILE * fp,
               short *infosize,
               int *width, int *height,
               int *x_coodinate, int *y_coodinate,
               short *BitCount, 
               int *ClrUsed)
{
  int count = 0;
  int var_long, compress = 0;
  short var_short;
  unsigned char c1, c2, c3, c4;

  //
  // BITMAPINFOHEADER �̃T�C�Y
  //
  if (fread(&var_long, 4, 1, fp) == 1) {
    count += 4;
    *infosize = (short)var_long;
  }
  printf("  [BITMAPINFOHEADER]\n");

  if (*infosize =! 40) {
    fprintf(stderr, "Bitmap Info Header error\n");
    return -1;
  }

  //
  // �摜�f�[�^�̕� 
  //
#ifdef _WIN32
  if (fread(&var_long, 4, 1, fp) == 1) {
    printf("  Width         : %ld [pixel]\n", var_long);
    *width = var_long;
    count += 4;
  }
#else
  fread(&c1, 1, 1, fp);
  fread(&c2, 1, 1, fp);
  fread(&c3, 1, 1, fp);
  fread(&c4, 1, 1, fp);
  *width = 256 * (256 * (256 * (int)c4 + (int)c3) + (int)c2) + (int)c1;
  printf("  Width         : %d [pixel]\n", *width);
  count += 4;
#endif  

  //
  // �摜�f�[�^�̍���
  //
#ifdef _WIN32
  if (fread(&var_long, 4, 1, fp) == 1) {
      printf("  Height        : %ld [pixel]\n", var_long);
      *height = var_long;
      count += 4;
  }
#else
  fread(&c1, 1, 1, fp);
  fread(&c2, 1, 1, fp);
  fread(&c3, 1, 1, fp);
  fread(&c4, 1, 1, fp);
  *height = 256 * (256 * (256 * (int)c4 + (int)c3) + (int)c2) + (int)c1;
  printf("  Heght        : %d [pixel]\n", *height);
  count += 4;
#endif

  //
  // �v���[���� (1�̂�) 
  //
  if (fread(&var_short, 2, 1, fp) == 1) {
      count += 2;
  }

  //
  // 1��f������̃r�b�g�� (1, 4, 8, 24, 32) 
  //
#ifdef _WIN32
  if (fread(&var_short, 2, 1, fp) == 1) {
      printf("  BitCount      : %d [bit]\n", var_short);
      *BitCount = var_short;
      count += 2;
  }
#else
  fread(&c1, 1, 1, fp);
  fread(&c2, 1, 1, fp);
  *BitCount = 256 * (int)c2 + (int)c1;
  printf("  BitCount      : %d [bit]\n", *BitCount);
  count += 2;
#endif

  //
  // ���k����  0 : �����k 
  //           1 : BI_RLE8 8bit RunLength ���k 
  //           2 : BI_RLE4 4bit RunLength ���k 
  //
#ifdef _WIN32
  if (fread(&var_long, 4, 1, fp) == 1) {
      printf("  Compression   : %ld\n", var_long);
      compress = var_long;
      count += 4;
  }
#else
  fread(&c1, 1, 1, fp);
  fread(&c2, 1, 1, fp);
  fread(&c3, 1, 1, fp);
  fread(&c4, 1, 1, fp);
  compress = 256 * (256 * (256 * (int)c4 + (int)c3) + (int)c2) + (int)c1;
  printf("  Compression   : %ld\n", compress);
  count += 4;
#endif

  //
  // �摜�f�[�^�̃T�C�Y 
  //
  if (fread(&var_long, 4, 1, fp) == 1) {
      //printf("  SizeImage     : %ld [Byte]\n", var_long);
      count += 4;
  }
 



  //
  // �������𑜓x (Pixel/meter) 
  //
#ifdef _WIN32
  if (fread(&var_long, 4, 1, fp) == 1) {
      printf("  XPelsPerMeter : %ld [pixel/m]\n", var_long);
      *x_coodinate = var_long;
      count += 4;
  }
#else
  fread(&c1, 1, 1, fp);
  fread(&c2, 1, 1, fp);
  fread(&c3, 1, 1, fp);
  fread(&c4, 1, 1, fp);
  *x_coodinate = 256 * (256 * (256 * (int)c4 + (int)c3) + (int)c2) + (int)c1;
  printf("  XPelsPerMeter : %ld [pixel/m]\n", *x_coodinate);
  count += 4;
#endif

  //
  // �c�����𑜓x (Pixel/meter) 
  //
#ifdef _WIN32
  if (fread(&var_long, 4, 1, fp) == 1) {
      printf("  YPelsPerMeter : %ld [pixel/m]\n", var_long);
      *y_coodinate = var_long;
      count += 4;
  }
#else
  fread(&c1, 1, 1, fp);
  fread(&c2, 1, 1, fp);
  fread(&c3, 1, 1, fp);
  fread(&c4, 1, 1, fp);
  *y_coodinate = 256 * (256 * (256 * (int)c4 + (int)c3) + (int)c2) + (int)c1;
  printf("  YPelsPerMeter : %ld [pixel/m]\n", *y_coodinate);
  count += 4;
#endif

  //
  // �g�p�F�� 
  //
#ifdef _WIN32
  if (fread(&var_long, 4, 1, fp) == 1) {
      printf("  ClrUsed       : %ld [color]\n", var_long);
      *ClrUsed = var_long;
      count += 4;
  }
#else
  fread(&c1, 1, 1, fp);
  fread(&c2, 1, 1, fp);
  fread(&c3, 1, 1, fp);
  fread(&c4, 1, 1, fp);
  *ClrUsed = 256 * (256 * (256 * (int)c4 + (int)c3) + (int)c2) + (int)c1;
  printf("  ClrUsed       : %ld [color]\n", *ClrUsed);
  count += 4;
#endif

  //
  // �d�v�ȐF�̐� 0�̏ꍇ���ׂĂ̐F 
  //
  if (fread(&var_long, 4, 1, fp) == 1) {
      count += 4;
  }
 
  //
  // �s�K�؂Ȑ��l�����o�����Ƃ��̃G���[�\��
  //
  if (compress != 0) {
    fprintf(stderr, "���k�r�b�g�}�b�v�ɂ͑Ή����Ă��܂���\n");
    exit(1);
  }
  if (*BitCount == 4 || *BitCount == 8 || *BitCount == 24 || *BitCount == 32) {
    ;
  } 
  else {
    fprintf(stderr, "%d �r�b�g�F�ɂ͑Ή����Ă��܂���\n", *BitCount);
    exit(1);
  }

  //
  // �o�C�g����Ԃ�
  //
  return count;
}

//
// �g�p�F���̃J�E���g
//
int usedcolor(short bits, int color)
{
  if (color != 0) {
    return color;
  } 
  else {
    return 1 << bits;
  }
}


//
// �J���[�e�[�u���̓ǂݍ���
//
int rgbquad(FILE * fp,
            int used,
            unsigned char *red, 
            unsigned char *green, 
            unsigned char *blue)
{
  int i;
  int receive, count = 0;

  //
  // �r�b�g�̕��т� B G R �\�� 
  //
  for (i = 0; i < used; i++) {
    blue[i] = fgetc(fp);
    green[i] = fgetc(fp);
    red[i] = fgetc(fp);
    receive = fgetc(fp);
    count++;
  }
  return count;
}


//
// �摜�f�[�^�{�̕��̓ǂݍ���
//
int dump32(FILE * bmp,
           int offset,
           int width,
           int height,
            short bits,
            unsigned char *red, 
            unsigned char *green, 
            unsigned char *blue,
			unsigned char *output)
{
  char r, g, b, alpha;
  int i, j, line, position, count = 0, size, size2;
  
  size = width * height;
  size2 = size * 2;

  //
  // 4byte ���E�ɂ��킹�� 
  //
  line = (width * bits) / 8;
  if ((line % 4) != 0) {
    line = ((line / 4) + 1) * 4;
  }

  //
  // �e�X�L�������C�����Ƃ�
  //
  for (i = 0; i < height; i++) {

	//
	// �X�L�������C���̐擪�ʒu 
	//
    position = offset + line * (height - (i + 1));
    fseek(bmp, position, SEEK_SET);

	//
    // �e��f���ƂɁF�l�̓ǂݍ���
	//
    for (j = 0; j < width; j++) {

	  //
	  // 32 bit �F 
      //
	  if (bits == 32) {
        b = fgetc(bmp);
        g = fgetc(bmp);
        r = fgetc(bmp);
        alpha = fgetc(bmp);
      }

	  //
      // 24 bit �F 
	  //
      else if (bits == 24) {
        b = fgetc(bmp);
        g = fgetc(bmp);
        r = fgetc(bmp);
      }

	  //
      // 8 bit �F 
	  //
      else if (bits == 8) {
        int index;
        index = fgetc(bmp);
        r = red[index];
		g = green[index];
		b = blue[index];
      }

	   output[count * 3] = r;
	   output[count * 3 + 1] = g;
	   output[count * 3 + 2] = b;
	   count++;
	}
  }

  //
  // ��f����Ԃ�
  //
  return count;
}



//
// BMP�摜�t�@�C����ǂށF
// �ʂ̃\�[�X�t�@�C������́A���̊֐����Ăяo������
//
Image *readBmpFile(char *filename)
{
  short infosize, bits;
  int used = 0, color = 0, offset, xreso, yreso, width, height;
  unsigned char red[256], green[256], blue[256], *output;
  FILE *fp1;
  Image *image;

  //
  // �t�@�C���I�[�v��
  //
  if ((fp1 = fopen(filename, "rb")) == NULL) {
    fprintf(stderr, "Cannot open file : %s\n", filename);
    exit(1);
  }

  //
  // �t�@�C���w�b�_����ǂݍ���
  //
  fileheader(fp1, &offset);
  
  //
  // ���w�b�_����ǂݍ���
  //
  infoheader(fp1, &infosize, &width, &height, &xreso, &yreso, &bits, &color);

  //
  // �F�̎g�������`����
  //
  color = usedcolor(bits, color);

  //
  // ���w�b�_����40�o�C�g�ł���ꍇ�݂̂��T�|�[�g
  //
  if (infosize == 40) {
    if (bits == 1 || bits == 4 || bits == 8) {
      used = rgbquad(fp1, color, red, green, blue);
    }
    printf("[Windows bitmap] --- %d bit %ld color\n", bits, used);
  } 

  //
  // �摜�f�[�^�{�̂��i�[���郁�������m��
  //
  output = malloc(sizeof(unsigned char) * width * height * 3);

  //
  // �摜�f�[�^�{�̂�ǂݍ���
  //
  if (bits == 32 || bits == 24 || bits == 8) {
    printf("%ld [pixels]\n",
           dump32(fp1, offset, width, height, bits, red, green, blue, output));
  }
  else {
    fprintf(stderr, "%d bit �F�ɂ͑Ή����Ă��܂���\n", bits);
    exit(1);
  }

  //
  // �t�@�C���N���[�Y
  //
  fclose(fp1);

  //
  // �摜�f�[�^�{�̂̃|�C���^��Ԃ�
  //
  image = malloc(sizeof(Image));
  image->image = output;
  image->width = width;
  image->height = height;
  return image;
}


