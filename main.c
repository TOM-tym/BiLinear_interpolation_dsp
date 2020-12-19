// /*
//  * main.c
//  */

#include <stdio.h>
#include <math.h>
#include "custombmplib.h"

const char iFileName[] = "lena512.bmp";
const char oFileName[] = "result7.bmp";
const int output_size[2] = {768,768};	//output HEIGHT & WIDTH
const int radix_pos = 12;
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

	imresize(piColorData,poColorData, ibmih.biWidth, ibmih.biHeight, obmih.biWidth, obmih.biHeight, radix_pos);

	fwrite(poColorData, 1, obmih.biSizeImage, pofile);   //灏嗗鐞嗗畬鍥惧儚鏁版嵁鍖哄啓鍥炴枃浠�
	printf("finish.\n");
	fclose(pifile);
    fclose(pofile);
	return 0;
}
