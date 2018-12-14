#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cvProgramming.h"


//
// 関数の使い方に関する表示
//
void usage(char *cmdname)
{
  fprintf(stderr,
          "\n"
          "ビットマップファイル ---> テキストダンプ プログラム\n"
          "Usage : %s bmp_file [text_file]\n"
          "  bmp_file  : ビットマップファイル\n"
          "              (無圧縮 4, 8, 24, 32bit のみ対応)\n"
          "  text_file : 指定しない場合 \"bmp_file.txt\" が出力されます\n"
          "\n"
          "  出力形式 : 各色 0～255\n"
          "\tRed Green Blue\n"
          "\tRed Green Blue\n"
          "\t :    :    :\n"
          "\n"
          "  画像のサイズによってダンプファイルがかなり大きくなるので\n"
          "  注意してください\n" "\n", cmdname);
  exit(1);
}


//
// ファイル名取得
//
int getbasename(char *dest, char *src)
{
  int i, start, end, ret;

  i = -1;
  start = 0;
  end = 0;

  //
  // ファイル名のはじめと終わりを検出
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
  // ファイル名が有る場合
  //
  if (start < end) {
    for (i = 0; i < end; i++) {
      dest[i] = src[i];
    }
    dest[i] = '\0';
    ret = 1;
  } 

  //
  // ファイル名が無い場合
  //
  else {
    dest[0] = '\0';
    ret = 0;
  }

  return ret;
}


//
// ファイルヘッダ部(14 Byte)の読み込み
//
int fileheader(FILE * fp, int *offset)
{
  int count = 0;
  int var_long;
  short var_short;
  char s[10];
  unsigned char c1, c2, c3, c4;

  //
  // BITMAP 認識文字 "BM"
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
  // ファイルサイズ
  //
  if (fread(&var_long, 4, 1, fp) == 1) {
    //printf("  Size          : %ld [Byte]\n", var_long);
    count += 4;
  }

  //
  // 予約領域 0
  //
  if (fread(&var_short, 2, 1, fp) == 1) {
    count += 2;
  }

  //
  // 予約領域 0
  //
  if (fread(&var_short, 2, 1, fp) == 1) {
    count += 2;
  }

  //
  // ファイルの先頭から画像データまでの位置
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
  // バイト数を返す
  //
  return count;
}


//
// 情報ヘッダ部(40Byte)の読み込み
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
  // BITMAPINFOHEADER のサイズ
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
  // 画像データの幅 
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
  // 画像データの高さ
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
  // プレーン数 (1のみ) 
  //
  if (fread(&var_short, 2, 1, fp) == 1) {
      count += 2;
  }

  //
  // 1画素あたりのビット数 (1, 4, 8, 24, 32) 
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
  // 圧縮方式  0 : 無圧縮 
  //           1 : BI_RLE8 8bit RunLength 圧縮 
  //           2 : BI_RLE4 4bit RunLength 圧縮 
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
  // 画像データのサイズ 
  //
  if (fread(&var_long, 4, 1, fp) == 1) {
      //printf("  SizeImage     : %ld [Byte]\n", var_long);
      count += 4;
  }
 



  //
  // 横方向解像度 (Pixel/meter) 
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
  // 縦方向解像度 (Pixel/meter) 
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
  // 使用色数 
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
  // 重要な色の数 0の場合すべての色 
  //
  if (fread(&var_long, 4, 1, fp) == 1) {
      count += 4;
  }
 
  //
  // 不適切な数値を検出したときのエラー表示
  //
  if (compress != 0) {
    fprintf(stderr, "圧縮ビットマップには対応していません\n");
    exit(1);
  }
  if (*BitCount == 4 || *BitCount == 8 || *BitCount == 24 || *BitCount == 32) {
    ;
  } 
  else {
    fprintf(stderr, "%d ビット色には対応していません\n", *BitCount);
    exit(1);
  }

  //
  // バイト数を返す
  //
  return count;
}

//
// 使用色数のカウント
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
// カラーテーブルの読み込み
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
  // ビットの並びは B G R 予約 
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
// 画像データ本体部の読み込み
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
  // 4byte 境界にあわせる 
  //
  line = (width * bits) / 8;
  if ((line % 4) != 0) {
    line = ((line / 4) + 1) * 4;
  }

  //
  // 各スキャンラインごとに
  //
  for (i = 0; i < height; i++) {

	//
	// スキャンラインの先頭位置 
	//
    position = offset + line * (height - (i + 1));
    fseek(bmp, position, SEEK_SET);

	//
    // 各画素ごとに：値の読み込み
	//
    for (j = 0; j < width; j++) {

	  //
	  // 32 bit 色 
      //
	  if (bits == 32) {
        b = fgetc(bmp);
        g = fgetc(bmp);
        r = fgetc(bmp);
        alpha = fgetc(bmp);
      }

	  //
      // 24 bit 色 
	  //
      else if (bits == 24) {
        b = fgetc(bmp);
        g = fgetc(bmp);
        r = fgetc(bmp);
      }

	  //
      // 8 bit 色 
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
  // 画素数を返す
  //
  return count;
}



//
// BMP画像ファイルを読む：
// 別のソースファイルからは、この関数を呼び出すこと
//
Image *readBmpFile(char *filename)
{
  short infosize, bits;
  int used = 0, color = 0, offset, xreso, yreso, width, height;
  unsigned char red[256], green[256], blue[256], *output;
  FILE *fp1;
  Image *image;

  //
  // ファイルオープン
  //
  if ((fp1 = fopen(filename, "rb")) == NULL) {
    fprintf(stderr, "Cannot open file : %s\n", filename);
    exit(1);
  }

  //
  // ファイルヘッダ部を読み込む
  //
  fileheader(fp1, &offset);
  
  //
  // 情報ヘッダ部を読み込む
  //
  infoheader(fp1, &infosize, &width, &height, &xreso, &yreso, &bits, &color);

  //
  // 色の使い方を定義する
  //
  color = usedcolor(bits, color);

  //
  // 情報ヘッダ部が40バイトである場合のみをサポート
  //
  if (infosize == 40) {
    if (bits == 1 || bits == 4 || bits == 8) {
      used = rgbquad(fp1, color, red, green, blue);
    }
    printf("[Windows bitmap] --- %d bit %ld color\n", bits, used);
  } 

  //
  // 画像データ本体を格納するメモリを確保
  //
  output = malloc(sizeof(unsigned char) * width * height * 3);

  //
  // 画像データ本体を読み込む
  //
  if (bits == 32 || bits == 24 || bits == 8) {
    printf("%ld [pixels]\n",
           dump32(fp1, offset, width, height, bits, red, green, blue, output));
  }
  else {
    fprintf(stderr, "%d bit 色には対応していません\n", bits);
    exit(1);
  }

  //
  // ファイルクローズ
  //
  fclose(fp1);

  //
  // 画像データ本体のポインタを返す
  //
  image = malloc(sizeof(Image));
  image->image = output;
  image->width = width;
  image->height = height;
  return image;
}


