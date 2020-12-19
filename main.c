// /*
//  * main.c
//  */

#include <stdio.h>
#include <math.h>
#include "custombmplib.h"

const char iFileName[] = "lena512.bmp";
const char oFileName[] = "result6.bmp";
const int output_size[2] = {1024,1024};	//output HEIGHT & WIDTH
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
	int oWidthByte = WIDTHBYTES(obmih.biWidth*obmih.biBitCount);	//输出图像每行像素应占字节
	obmih.biSizeImage = oWidthByte * obmih.biHeight;		//整幅输出图像像素所占字节
	obmfh.bfSize = obmfh.bfOffBits + obmih.biSizeImage;		//输出图像文件的字节（包括文件头和数据）
	fwrite(&obmfh, 1, sizeof(BITMAPFILEHEADER), pofile);
	fwrite(&obmih, 1, sizeof(BITMAPINFOHEADER), pofile);

	//save palette
	size_t Offbit_File_Info = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	BYTE *pPale = (BYTE *)malloc(ibmfh.bfOffBits-Offbit_File_Info);	//pointer palette
	fread(pPale, 1, ibmfh.bfOffBits-Offbit_File_Info, pifile);
	fwrite(pPale, 1, ibmfh.bfOffBits-Offbit_File_Info, pofile);

	//read color data
	unsigned int iWidthByte = WIDTHBYTES(ibmih.biWidth * ibmih.biBitCount);	//输入图像每行像素应占字节
	BYTE *piColorData = (BYTE *)malloc(ibmih.biSizeImage);	//分配存储输入图像数据的空间
	fread(piColorData, 1, ibmih.biSizeImage, pifile);

	//bilinear interpolation resize
	BYTE *poColorData = (BYTE *)malloc(obmih.biSizeImage);	//分配存储输出图像数据的空间
	memset(poColorData, 0, obmih.biSizeImage);

	imresize(piColorData,poColorData, ibmih.biWidth, ibmih.biHeight, obmih.biWidth, obmih.biHeight, radix_pos);

	fwrite(poColorData, 1, obmih.biSizeImage, pofile);   //将处理完图像数据区写回文件
	printf("finish.\n");
	fclose(pifile);
    fclose(pofile);
	return 0;
}
