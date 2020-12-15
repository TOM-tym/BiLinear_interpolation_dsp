/*
 * custombmplib.h
 *
 *  Created on: 2020-11-23
 *      Author: ouwen
 */

#include <stdio.h>

#ifndef CUSTOMBMPLIB_H_
#define CUSTOMBMPLIB_H_

#define WIDTHBYTES(bits) (((bits)+31)/32*4) //计算图像宽所占字节数，并且取为4byte的倍数

#pragma pack(push, 1)

//match windows data format to C6000 data format
typedef unsigned char BYTE;   //1 Byte
typedef unsigned short WORD;  //2 Byte
typedef unsigned int DWORD;   //4 Byte
typedef int LONG;             //4 Byte

//define BMP format
typedef struct tagBITMAPFILEHEADER {
  WORD  bfType;         //位图文件的类型， 必须为BM 对应的16进制为0x4D42
  DWORD bfSize;         //位图文件的大小，字节单位
  WORD  bfReserved1;    //位图文件保留字，必须为0
  WORD  bfReserved2;    //位图文件保留字，必须为0
  DWORD bfOffBits;      //为从文件头到实际图像数据区域的长度，即前三个结构长度之和。
} BITMAPFILEHEADER, *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
  DWORD biSize;         //指定该信息头所占字节数，固定占40个字节
  LONG  biWidth;        //位图的宽度，单位为像素
  LONG  biHeight;       //位图的高度，单位为像素
  WORD  biPlanes;       //目标设备的位面数，必须是1
  WORD  biBitCount;     //每个像素所占的位数
  DWORD biCompression;  //位图的压缩方式，大多数情况下为0，也可能是BI_RGB
  DWORD biSizeImage;    //位图的大小，字节单位
  LONG  biXPelsPerMeter;    //水平分辨率，水平每米所占像素个数
  LONG  biYPelsPerMeter;    //垂直分辨率，垂直每米所占像素个数
  DWORD biClrUsed;          //指出该位图中实际使用的色彩数，若为0，则为2^biBitCount
  DWORD biClrImportant;     //位图显示中比较重要的颜色数,若为0，则所有颜色都是重要的。
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagRGBQUAD {
  BYTE rgbBlue;   //该颜色的蓝色分量(0-255)
  BYTE rgbGreen;  //该颜色的绿色分量(0-255)
  BYTE rgbRed;    //该颜色的红色分量(0-255)
  BYTE rgbReserved;   //保留值
} RGBQUAD, *PRGBQUAD;

#endif /* CUSTOMBMPLIB_H_ */


