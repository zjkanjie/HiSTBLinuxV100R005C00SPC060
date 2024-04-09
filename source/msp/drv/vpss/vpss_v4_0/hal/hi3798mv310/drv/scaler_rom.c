/******************************************************************************

  Copyright (C), 2001-2011, Hisilicon Tech. Co., Ltd.
*******************************************************************************
  File Name     :
  Version       : Initial Draft
  Author        :
  Created       :
  Last Modified :
  Description   :
  Function List :
  History       :

  1.Date         : 2011/1/13
    Author       : y45339
    Modification : add coeff for up scale

******************************************************************************/

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#include "scaler_rom.h"
//#include <stdio.h>

#ifdef ZOOM_B1
const int Blinear_Down2[2] =
{
    32, 0
};
const int Blinear_Down4[4] =
{
    32, 0, 0, 0
};
#else
const int Blinear_Down2[2] =
{
    16, 16
};
const int Blinear_Down4[4] =
{
    8, 8, 8, 8
};
#endif

const HI_S16 coef6Tap_66M_a20[COEFF_BUTT][6] =
{
    {   -4,    7,   56,    7,   -4,    2},
    {   -4,    6,   56,    9,   -5,    2},
    {   -3,    4,   55,   11,   -5,    2},
    {   -3,    3,   55,   13,   -6,    2},
    {   -2,    1,   55,   14,   -6,    2},
    {   -2,    0,   54,   16,   -6,    2},
    {   -1,   -1,   53,   18,   -7,    2},
    {   -1,   -2,   52,   20,   -7,    2},
    {   -1,   -3,   51,   22,   -7,    2},
    {    0,   -4,   50,   24,   -8,    2},
    {    0,   -5,   49,   26,   -8,    2},
    {    0,   -6,   48,   28,   -8,    2},
    {    1,   -6,   45,   30,   -8,    2},
    {    1,   -7,   44,   32,   -8,    2},
    {    1,   -7,   42,   34,   -8,    2},
    {    1,   -8,   41,   36,   -8,    2},
    {    2,   -8,   38,   38,   -8,    2},
};  // normalize OK!
const HI_S16 coef6Tap_6M_a25[COEFF_BUTT][6] =
{
    {   -4,    9,   53,    9,   -4,    1},
    {   -4,    8,   52,   11,   -4,    1},
    {   -4,    7,   52,   13,   -5,    1},
    {   -3,    5,   52,   14,   -5,    1},
    {   -3,    4,   51,   16,   -5,    1},
    {   -3,    3,   51,   18,   -6,    1},
    {   -2,    2,   49,   20,   -6,    1},
    {   -2,    1,   49,   21,   -6,    1},
    {   -2,    0,   48,   23,   -6,    1},
    {   -1,   -1,   46,   25,   -6,    1},
    {   -1,   -2,   45,   27,   -6,    1},
    {   -1,   -3,   45,   28,   -6,    1},
    {   -1,   -3,   43,   30,   -6,    1},
    {    0,   -4,   41,   32,   -6,    1},
    {    0,   -4,   39,   34,   -6,    1},
    {    0,   -4,   38,   36,   -6,    0},
    {    0,   -5,   37,   37,   -5,    0},
};  // normalize OK!
const HI_S16 coef6Tap_5M_a25[COEFF_BUTT][6] =
{
    {   -4,   13,   46,   13,   -4,    0},
    {   -4,   12,   46,   14,   -4,    0},
    {   -4,   11,   45,   16,   -4,    0},
    {   -3,    9,   45,   17,   -4,    0},
    {   -3,    8,   45,   18,   -4,    0},
    {   -3,    7,   44,   20,   -4,    0},
    {   -3,    6,   44,   21,   -4,    0},
    {   -3,    5,   44,   22,   -4,    0},
    {   -3,    4,   43,   24,   -4,    0},
    {   -2,    3,   42,   25,   -4,    0},
    {   -2,    2,   41,   27,   -4,    0},
    {   -2,    2,   39,   28,   -3,    0},
    {   -2,    1,   39,   29,   -3,    0},
    {   -2,    0,   39,   31,   -3,   -1},
    {   -1,    0,   36,   32,   -2,   -1},
    {   -1,   -1,   36,   33,   -2,   -1},
    {   -1,   -2,   35,   35,   -2,   -1},
};  // normalize OK!
const HI_S16 coef6Tap_4M_a20[COEFF_BUTT][6] =
{
    {   -2,   15,   39,   15,   -2,   -1},
    {   -3,   15,   38,   17,   -2,   -1},
    {   -3,   14,   38,   18,   -2,   -1},
    {   -3,   13,   38,   19,   -2,   -1},
    {   -3,   13,   37,   20,   -2,   -1},
    {   -3,   12,   36,   21,   -1,   -1},
    {   -3,   11,   36,   22,   -1,   -1},
    {   -3,   10,   36,   23,   -1,   -1},
    {   -3,    9,   36,   24,   -1,   -1},
    {   -3,    8,   36,   25,    0,   -2},
    {   -3,    8,   35,   26,    0,   -2},
    {   -3,    7,   34,   27,    1,   -2},
    {   -3,    6,   34,   28,    1,   -2},
    {   -3,    5,   33,   29,    2,   -2},
    {   -3,    5,   33,   29,    2,   -2},
    {   -2,    4,   31,   30,    3,   -2},
    {   -2,    3,   31,   31,    3,   -2},
};  // normalize OK!
const HI_S16 coef6Tap_35M_a18[COEFF_BUTT][6] =
{
    {   -1,   17,   33,   17,   -1,   -1},
    {   -1,   16,   33,   17,    0,   -1},
    {   -1,   15,   33,   18,    0,   -1},
    {   -1,   15,   32,   19,    0,   -1},
    {   -1,   14,   32,   19,    1,   -1},
    {   -2,   13,   32,   21,    1,   -1},
    {   -2,   13,   32,   22,    1,   -2},
    {   -2,   12,   32,   22,    2,   -2},
    {   -2,   11,   32,   23,    2,   -2},
    {   -2,   11,   31,   24,    2,   -2},
    {   -2,   10,   31,   24,    3,   -2},
    {   -2,    9,   31,   25,    3,   -2},
    {   -2,    8,   30,   26,    4,   -2},
    {   -2,    8,   30,   26,    4,   -2},
    {   -2,    7,   29,   27,    5,   -2},
    {   -2,    7,   28,   28,    5,   -2},
    {   -2,    6,   28,   28,    6,   -2},
};  // normalize OK!
const HI_S16 coef6Tap_cubic[COEFF_BUTT][6] =
{
    {    0,    0,   64,    0,    0,    0},
    {    0,   -2,   64,    2,    0,    0},
    {    1,   -3,   63,    4,   -1,    0},
    {    1,   -4,   62,    6,   -1,    0},
    {    1,   -5,   62,    8,   -2,    0},
    {    1,   -6,   61,   10,   -2,    0},
    {    2,   -7,   60,   12,   -3,    0},
    {    2,   -7,   58,   15,   -4,    0},
    {    2,   -8,   56,   17,   -4,    1},
    {    2,   -8,   54,   20,   -5,    1},
    {    2,   -8,   52,   22,   -5,    1},
    {    2,   -9,   51,   25,   -6,    1},
    {    2,   -9,   48,   28,   -6,    1},
    {    2,   -9,   47,   30,   -7,    1},
    {    2,   -8,   43,   33,   -7,    1},
    {    2,   -8,   41,   36,   -8,    1},
    {    2,   -8,   38,   38,   -8,    2},
};  // normalize OK!



const HI_S16 coef4Tap_5M_a15[COEFF_BUTT][4] =
{
    {   12,   44,   12,   -4},
    {   11,   44,   13,   -4},
    {   10,   44,   15,   -5},
    {    9,   44,   16,   -5},
    {    8,   43,   18,   -5},
    {    7,   43,   19,   -5},
    {    6,   42,   21,   -5},
    {    5,   42,   22,   -5},
    {    4,   41,   23,   -4},
    {    3,   40,   25,   -4},
    {    2,   40,   26,   -4},
    {    1,   39,   28,   -4},
    {    0,   39,   29,   -4},
    {    0,   37,   30,   -3},
    {   -1,   36,   32,   -3},
    {   -1,   34,   33,   -2},
    {   -2,   34,   34,   -2},
};  // normalize OK!
const HI_S16 coef4Tap_4M_a15[COEFF_BUTT][4] =
{
    {   15,   36,   15,   -2},
    {   14,   36,   16,   -2},
    {   13,   36,   17,   -2},
    {   12,   36,   18,   -2},
    {   11,   36,   19,   -2},
    {   10,   35,   20,   -1},
    {    9,   35,   21,   -1},
    {    9,   35,   21,   -1},
    {    8,   35,   22,   -1},
    {    7,   34,   23,    0},
    {    6,   34,   24,    0},
    {    6,   33,   25,    0},
    {    5,   32,   26,    1},
    {    4,   32,   27,    1},
    {    4,   30,   28,    2},
    {    3,   30,   29,    2},
    {    3,   29,   29,    3},
};  // normalize OK!

const HI_S16 coef4Tap_cubic[COEFF_BUTT][4] =
{
    {    0,   64,    0,    0},
    {   -2,   63,    3,    0},
    {   -4,   63,    5,    0},
    {   -6,   63,    8,   -1},
    {   -8,   62,   11,   -1},
    {   -9,   62,   13,   -2},
    {  -10,   60,   16,   -2},
    {  -11,   59,   19,   -3},
    {  -12,   58,   22,   -4},
    {  -12,   57,   24,   -5},
    {  -12,   55,   27,   -6},
    {  -12,   52,   30,   -6},
    {  -12,   51,   32,   -7},
    {  -12,   49,   35,   -8},
    {  -12,   47,   38,   -9},
    {  -11,   45,   40,  -10},
    {  -10,   42,   42,  -10},
};  // normalize OK!

const HI_S16 vpss_coef6Tap[COEFF_BUTT][6] =
{
    {    -4,    8,   55,    8,    -4,    1},
    {    -3,    6,   55,    9,    -4,    1},
    {    -3,    5,   54,    11,   -4,    1},
    {    -3,    4,   54,    13,   -5,    1},
    {    -2,    3,   53,    14,   -5,    1},
    {    -2,    2,   53,    16,   -6,    1},
    {    -1,    -1,  52,    18,   -6,    2},
    {    -1,    -2,  51,    20,   -6,    2},
    {    -1,    -3,  50,    22,   -6,    2},
    {     0,    -3,  48,    24,   -7,    2},
    {     0,    -4,  47,    26,   -7,    2},
    {     0,    -5,  46,    28,   -7,    2},
    {     0,    -5,  45,    30,   -7,    1},
    {     1,    -6,  43,    32,   -7,    1},
    {     1,    -6,  41,    34,   -7,    1},
    {     1,    -7,  40,    36,   -7,    1},
    {     1,    -7,  38,    38,   -7,    1},
};  // normalize OK!

const HI_S16 vpss_coef4Tap[COEFF_BUTT][4] =
{
    {   12,  43,   13,   -4},
    {   11,  43,   14,   -4},
    {   10,  43,   15,   -4},
    {   9,   42,   17,   -4},
    {   8,   42,   18,   -4},
    {   7,   42,   19,   -4},
    {   6,   41,   21,   -4},
    {   5,   41,   22,   -4},
    {   4,   41,   23,   -4},
    {   4,   39,   25,   -4},
    {   3,   39,   26,   -4},
    {   2,   38,   27,   -3},
    {   1,   38,   28,   -3},
    {   0,   37,   30,   -3},
    {   0,   35,   31,   -2},
    {   -1,  35,   32,   -2},
    {   -1,  33,   33,   -1},
};  // normalize OK!

#if 0
const int *pps32OrgZoomCoeff_vpss[7][4] =
{
    //VOU_ZOOM_TAP_6LH,       VOU_ZOOM_TAP_4LV,   VOU_ZOOM_TAP_4CH,  VOU_ZOOM_TAP_4CV,
    {&coef6Tap_66M_a20[0][0], &coef4Tap_5M_a15[0][0], &coef4Tap_5M_a15[0][0], &coef4Tap_5M_a15[0][0],}, //>1
    {&coef6Tap_cubic[0][0],   &coef4Tap_cubic[0][0],  &coef4Tap_cubic[0][0],  &coef4Tap_cubic[0][0]},     //==1
    {&coef6Tap_6M_a25[0][0],  &coef4Tap_5M_a15[0][0], &coef4Tap_5M_a15[0][0], &coef4Tap_5M_a15[0][0]},         //>=0.75
    {&coef6Tap_5M_a25[0][0],  &coef4Tap_5M_a15[0][0], &coef4Tap_5M_a15[0][0], &coef4Tap_5M_a15[0][0]},  //>=0.5
    {&coef6Tap_4M_a20[0][0],  &coef4Tap_4M_a15[0][0], &coef4Tap_4M_a15[0][0], &coef4Tap_4M_a15[0][0]},  //>=0.33
    {&coef6Tap_35M_a18[0][0], &coef4Tap_4M_a15[0][0], &coef4Tap_4M_a15[0][0], &coef4Tap_4M_a15[0][0]},  //>=0.25
    {&coef6Tap_35M_a18[0][0], &coef4Tap_4M_a15[0][0], &coef4Tap_4M_a15[0][0], &coef4Tap_4M_a15[0][0]}//else
};
#endif
void Check_Coeff_Norm(int *pCoef, int butt, int tap, int norm)
{
    int i, j;

    for (i = 0; i < butt; i++)
    {
        int sum = 0;

        for (j = 0; j < tap; j++)
        {
            sum += *(pCoef + i * tap + j);
        }

        if (sum != norm)
        {
            //printk("Check Phase %d Norm = %d\n", i, sum);
        }
    }
    return;
}

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif
