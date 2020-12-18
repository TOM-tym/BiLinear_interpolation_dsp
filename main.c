/*
 * main.c
 */

#include <stdio.h>
#include <math.h>
#include "custombmplib.h"

const char iFileName[] = "lena128.bmp";
const char oFileName[] = "result4.bmp";
const int output_size[2] = {192,192};	//output HEIGHT & WIDTH

void imresize(BYTE* psrc, BYTE* pdst, int iWidth, int iHeight, int oWidth, int oHeight, int pos);

int main(void) {
	BITMAPFILEHEADER ibmfh, obmfh;	//inBitmapFileHead, outBitmapFileHead
    BITMAPINFOHEADER ibmih, obmih;	//inBitmapInfoHead, outBitmapInfoHead
    FILE* pifile = fopen(iFileName, "rb");	//pointer input file
    FILE* pofile = fopen(oFileName, "wb");	//pointer output file

	//judge file format
	WORD fileType;
	fread(&fileType, 1, sizeof(WORD), pifile);
    if (fileType != 0x4d42)
    {
        printf("This file is not a .bmp file!");
        return -1;
    }

	//read input file head
	rewind(pifile);
	fread(&ibmfh, sizeof(BITMAPFILEHEADER), 1, pifile);
	fread(&ibmih, sizeof(BITMAPINFOHEADER), 1, pifile);

	//write output file head
	obmfh = ibmfh;
	obmih = ibmih;
	obmih.biHeight = output_size[0];
	obmih.biWidth = output_size[1];
	int oWidthByte = WIDTHBYTES(obmih.biWidth*obmih.biBitCount);	//杈撳嚭鍥惧儚姣忚鍍忕礌搴斿崰瀛楄妭
	obmih.biSizeImage = oWidthByte * obmih.biHeight;		//鏁村箙杈撳嚭鍥惧儚鍍忕礌鎵�崰瀛楄妭
	obmfh.bfSize = obmfh.bfOffBits + obmih.biSizeImage;		//杈撳嚭鍥惧儚鏂囦欢鐨勫瓧鑺傦紙鍖呮嫭鏂囦欢澶村拰鏁版嵁锛�
	fwrite(&obmfh, 1, sizeof(BITMAPFILEHEADER), pofile);
	fwrite(&obmih, 1, sizeof(BITMAPINFOHEADER), pofile);
	
	//save palette
	size_t Offbit_File_Info = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	BYTE *pPale = (BYTE *)malloc(ibmfh.bfOffBits-Offbit_File_Info);	//pointer palette
	fread(pPale, 1, ibmfh.bfOffBits-Offbit_File_Info, pifile);
	fwrite(pPale, 1, ibmfh.bfOffBits-Offbit_File_Info, pofile);

	//read color data
	unsigned int iWidthByte = WIDTHBYTES(ibmih.biWidth * ibmih.biBitCount);	//杈撳叆鍥惧儚姣忚鍍忕礌搴斿崰瀛楄妭
	BYTE *piColorData = (BYTE *)malloc(ibmih.biSizeImage);	//鍒嗛厤瀛樺偍杈撳叆鍥惧儚鏁版嵁鐨勭┖闂�
	fread(piColorData, 1, ibmih.biSizeImage, pifile);

	//bilinear interpolation resize
	BYTE *poColorData = (BYTE *)malloc(obmih.biSizeImage);	//鍒嗛厤瀛樺偍杈撳嚭鍥惧儚鏁版嵁鐨勭┖闂�
	memset(poColorData, 0, obmih.biSizeImage);

	imresize(piColorData,poColorData, ibmih.biWidth, ibmih.biHeight, obmih.biWidth, obmih.biHeight, 16);

	fwrite(poColorData, 1, obmih.biSizeImage, pofile);   //灏嗗鐞嗗畬鍥惧儚鏁版嵁鍖哄啓鍥炴枃浠�
	printf("finish.\n");
	fclose(pifile);
    fclose(pofile);
	return 0;
}

// int main(void) {
// 	BITMAPFILEHEADER ibmfh, obmfh;	//inBitmapFileHead, outBitmapFileHead
//     BITMAPINFOHEADER ibmih, obmih;	//inBitmapInfoHead, outBitmapInfoHead
//     FILE* pifile = fopen(iFileName, "rb");	//pointer input file
//     FILE* pofile = fopen(oFileName, "wb");	//pointer output file

// 	//judge file format
// 	WORD fileType;
// 	fread(&fileType, 1, sizeof(WORD), pifile);
//     if (fileType != 0x4d42)
//     {
//         printf("This file is not a .bmp file!");
//         return -1;
//     }

// 	//read input file head
// 	rewind(pifile);
// 	fread(&ibmfh, sizeof(BITMAPFILEHEADER), 1, pifile);
// 	fread(&ibmih, sizeof(BITMAPINFOHEADER), 1, pifile);

// 	//write output file head
// 	obmfh = ibmfh;
// 	obmih = ibmih;
// 	obmih.biHeight = output_size[0];
// 	obmih.biWidth = output_size[1];
// 	int oWidthByte = WIDTHBYTES(obmih.biWidth*obmih.biBitCount);	//杈撳嚭鍥惧儚姣忚鍍忕礌搴斿崰瀛楄妭
// 	obmih.biSizeImage = oWidthByte * obmih.biHeight;		//鏁村箙杈撳嚭鍥惧儚鍍忕礌鎵�崰瀛楄妭
// 	obmfh.bfSize = obmfh.bfOffBits + obmih.biSizeImage;		//杈撳嚭鍥惧儚鏂囦欢鐨勫瓧鑺傦紙鍖呮嫭鏂囦欢澶村拰鏁版嵁锛�
// 	fwrite(&obmfh, 1, sizeof(BITMAPFILEHEADER), pofile);
// 	fwrite(&obmih, 1, sizeof(BITMAPINFOHEADER), pofile);
	
// 	//save palette
// 	size_t Offbit_File_Info = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
// 	BYTE *pPale = (BYTE *)malloc(ibmfh.bfOffBits-Offbit_File_Info);	//pointer palette
// 	fread(pPale, 1, ibmfh.bfOffBits-Offbit_File_Info, pifile);
// 	fwrite(pPale, 1, ibmfh.bfOffBits-Offbit_File_Info, pofile);

// 	//read color data
// 	unsigned int iWidthByte = WIDTHBYTES(ibmih.biWidth * ibmih.biBitCount);	//杈撳叆鍥惧儚姣忚鍍忕礌搴斿崰瀛楄妭
// 	BYTE *piColorData = (BYTE *)malloc(ibmih.biSizeImage);	//鍒嗛厤瀛樺偍杈撳叆鍥惧儚鏁版嵁鐨勭┖闂�
// 	fread(piColorData, 1, ibmih.biSizeImage, pifile);

// 	//bilinear interpolation resize
// 	BYTE *poColorData = (BYTE *)malloc(obmih.biSizeImage);	//鍒嗛厤瀛樺偍杈撳嚭鍥惧儚鏁版嵁鐨勭┖闂�
// 	memset(poColorData, 0, obmih.biSizeImage);

// 	imresize(piColorData, poColorData, ibmih.biWidth, ibmih.biHeight, obmih.biWidth, obmih.biHeight, 12);

// 	fwrite(poColorData, 1, obmih.biSizeImage, pofile);   //灏嗗鐞嗗畬鍥惧儚鏁版嵁鍖哄啓鍥炴枃浠�
// 	printf("finish.\n");
// 	fclose(pifile);
//     fclose(pofile);
// 	return 0;
// }

// void imresize(BYTE *piColorData, BYTE *poColorData, int iWidth, int iHeight, int oWidth, int oHeight){
	
// 	int y, x;						//y:output img y, x: output img x
// 	float ori_y, ori_x;				//origin_y, origin_x (鐩爣鍥惧儚鏀剧缉瀵瑰簲鍘熷浘鍧愭爣)
// 	float ori_a, ori_b, ori_c, ori_d;	//鍧愭爣鍛ㄥ洿鐨勫乏涓嬬偣(ori_a, ori_b)锛屽潗鏍囧懆鍥寸殑鍙充笂鐐�ori_c, ori_d)
// 	int position1, position2, position3, position4;	//鍘熷浘鍍忕殑鍥涗釜鏁扮粍浣嶇疆,宸︿笅銆佸彸涓嬨�宸︿笂銆佸彸涓�
// 	float gray_level1, gray_level2;	//鍙岀嚎鎬х畻娉曞搴旂殑涓や釜涓棿鍊�
// 	float ratiow = (float)iWidth / oWidth;
//  float ratioh = (float)iHeight / oHeight;
// 	for (y = 0; y < oHeight; y++){
// 		printf("y=%d\n",y);
// 		for (x = 0; x < oWidth; x++){
// 			ori_y = y * ratioh;
// 			ori_x = x * ratiow;
// 			ori_a = floor(ori_x);
// 			ori_b = floor(ori_y); 
// 			ori_c = ceil(ori_x);
// 			ori_d = ceil(ori_y);

// 			position1 = ori_a + ori_b * iWidth;
// 			position2 = ori_c + ori_b * iWidth;
// 			position3 = ori_a + ori_d * iWidth;
// 			position4 = ori_c + ori_d * iWidth;

// 			gray_level1 = piColorData[position1] + (piColorData[position2] - piColorData[position1])*(ori_x - ori_a);
// 			gray_level2 = piColorData[position3] + (piColorData[position4] - piColorData[position3])*(ori_x - ori_a);

// 			poColorData[x+y*oWidth] = gray_level1 + (gray_level2 - gray_level1)*(ori_y-ori_b);
// 		}
// 	}
// 	return;
// }

