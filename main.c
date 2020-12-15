// /*
//  * main.c
//  */
// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <math.h>
// // #include "custombmplib.h"

// // int division(int a, int b);
// // int main(void){
// // 	int a = 11, b = 3;
// // 	int sum = division(a,b);
// // 	printf("sum=%d",sum);
// // 	return 0;
// // }


// #include <stdio.h>
// #include <math.h>
// #include "custombmplib.h"

// const char iFileName[] = "lena128.bmp";
// const char oFileName[] = "result3.bmp";
// const int output_size[2] = {256, 256};	//output HEIGHT & WIDTH

// void imresize(BYTE* psrc, BYTE* pdst, int iWidth, int iHeight, float ratiow, float ratioh);

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
// 	int oWidthByte = WIDTHBYTES(obmih.biWidth*obmih.biBitCount);	//输出图像每行像素应占字节
// 	obmih.biSizeImage = oWidthByte * obmih.biHeight;		//整幅输出图像像素所占字节
// 	obmfh.bfSize = obmfh.bfOffBits + obmih.biSizeImage;		//输出图像文件的字节（包括文件头和数据）
// 	fwrite(&obmfh, 1, sizeof(BITMAPFILEHEADER), pofile);
// 	fwrite(&obmih, 1, sizeof(BITMAPINFOHEADER), pofile);
	
// 	//save palette
// 	size_t Offbit_File_Info = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
// 	BYTE *pPale = (BYTE *)malloc(ibmfh.bfOffBits-Offbit_File_Info);	//pointer palette
// 	fread(pPale, 1, ibmfh.bfOffBits-Offbit_File_Info, pifile);
// 	fwrite(pPale, 1, ibmfh.bfOffBits-Offbit_File_Info, pofile);

// 	//read color data
// 	unsigned int iWidthByte = WIDTHBYTES(ibmih.biWidth * ibmih.biBitCount);	//输入图像每行像素应占字节
// 	BYTE *piColorData = (BYTE *)malloc(ibmih.biSizeImage);	//分配存储输入图像数据的空间
// 	fread(piColorData, 1, ibmih.biSizeImage, pifile);

// 	//bilinear interpolation resize
// 	BYTE *poColorData = (BYTE *)malloc(obmih.biSizeImage);	//分配存储输出图像数据的空间
// 	memset(poColorData, 0, obmih.biSizeImage);

// 	float ratiow = (float)ibmih.biWidth / obmih.biWidth;
// 	float ratioh = (float)ibmih.biHeight / obmih.biHeight;

// 	imresize(piColorData, poColorData, ibmih.biWidth, ibmih.biHeight, ratiow, ratioh);

// 	fwrite(poColorData, 1, obmih.biSizeImage, pofile);   //将处理完图像数据区写回文件
// 	printf("finish.\n");
// 	fclose(pifile);
//     fclose(pofile);
// 	return 0;
// }

// // void imresize(BYTE *piColorData, BYTE *poColorData, int iWidth, int iHeight, float ratiow, float ratioh){
// // 	int oWidth = iWidth * ratiow;
// // 	int oHeight = iHeight * ratioh;
	
// // 	int y, x;						//y:output img y, x: output img x
// // 	float ori_y, ori_x;				//origin_y, origin_x (目标图像放缩对应原图坐标)
// // 	float ori_a, ori_b, ori_c, ori_d;	//坐标周围的左下点(ori_a, ori_b)，坐标周围的右上点(ori_c, ori_d)
// // 	int position1, position2, position3, position4;	//原图像的四个数组位置,左下、右下、左上、右上
// // 	float gray_level1, gray_level2;	//双线性算法对应的两个中间值
// // 	// float ratiow = (float)iWidth / oWidth;
// // 	// float ratioh = (float)iHeight / oHeight;
// // 	for (y = 0; y < oHeight; y++){
// // 		printf("y=%d\n",y);
// // 		for (x = 0; x < oWidth; x++){
// // 			ori_y = y * (1/ratioh);
// // 			ori_x = x * (1/ratiow);
// // 			ori_a = floor(ori_x);
// // 			ori_b = floor(ori_y); 
// // 			ori_c = ceil(ori_x);
// // 			ori_d = ceil(ori_y);

// // 			position1 = ori_a + ori_b * iWidth;
// // 			position2 = ori_c + ori_b * iWidth;
// // 			position3 = ori_a + ori_d * iWidth;
// // 			position4 = ori_c + ori_d * iWidth;

// // 			gray_level1 = piColorData[position1] + (piColorData[position2] - piColorData[position1])*(ori_x - ori_a);
// // 			gray_level2 = piColorData[position3] + (piColorData[position4] - piColorData[position3])*(ori_x - ori_a);

// // 			poColorData[x+y*oWidth] = gray_level1 + (gray_level2 - gray_level1)*(ori_y-ori_b);
// // 		}
// // 	}
// // 	return;
// // }
#include <stdio.h>
#include <math.h>
extern int division(int a, int b);
float show_fix_point(int);
int main(){
	int dividend[] = {0x000B8000,0x00048000,0x00010000,0x00010000,0x00641000,0x00010000,0x02000000};
	int divisor[] = {0x00038000,0x00018000,0x00020000,0x00031000,0x00021000,0x00030000,0x03000000};
	int i = 0;
	for (;i<7;i++){
		int a = dividend[i];
		int b = divisor[i];
		int res = division(a,b);
		float s_a = show_fix_point(a);
		float s_b = show_fix_point(b);
		float s_res = show_fix_point(res);
		printf("%f / %f = %f\n",s_a,s_b,s_res);
	}
}
float show_fix_point(int a){
	int integer = a>>16;
	int i =16;
	float result = 0;
	for (; i>0; i--){
		if (a % 2 ==1)
			result += pow(2,-i);
		a = a >> 1;
	}
	float res = (float)integer + result;
	//printf("%f",res);
	return res;
}

