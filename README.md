# Image bilinear interpolation implementation on C6000
### Author: Ouwzhong, TOM-tym.

#### Abstract

This is a implementation of bilinear interpolation for image resize operation, coding for TMS320C6000 series DPS from Texas Instruments.

We implement bilinear algorithm using linear assembly language.

This implementation is one part of homework of course `Principles and Applications of DSP Devices` , SEIT, SYSU.

#### Useage:

1. Define your filename in `main.c`, modify variables `iFileName` and `oFileName`.
2. Define your output resolution in `main.c`. (variable `output_size`)
3. RUN THE PROGRAM!
4. (optional) Since we've only got integer that is  32-bit long in C64xx DSPs, for fix-point numbers, we actually define the length of decimal part is 12 (variable `pos`). You can enlarge it if you want more precise numbers. However, if your output size is 1024x1024,  which means your final result is approximately 2^20-bit long in memory, you must guarantee  that `pos` is small than (32-20 = 12). 

#### Update log:

- 2020.12.19 bug fixed, using LDBU instead of LDB. Results seem fine.
- 2020.12.17 TODO: 20bit integer part and 12bit dicimal part.
- 2020.12.16 Radix point position now can be adjusted. (parameters 'point_pos')
- 2020.12.15 Update 32bit fix-point division.

#### Example:

Below, we show a resized lena photo from 512x512 px to 1024x1024 px. 

![lena512](D:\Learning Material\Finished\dsp\ccs\mine\BiLinear_interpolation_dsp\Debug\lena512.bmp)



![result6](D:\Learning Material\Finished\dsp\ccs\mine\BiLinear_interpolation_dsp\Debug\result6.bmp)
