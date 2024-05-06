/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 66. 加一
 * link: https://leetcode-cn.com/problems/plus-one/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int *res = NULL;
    int i,j = 0;
    int reslen = digitsSize + 1;

    res = (int*)malloc(reslen * sizeof(int));
    if (res == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // 为空，则返回1
    if ((digitsSize == 0) || (digits == NULL)) {
        *returnSize = 1;
        res[0] = 1;
        return res;
    }
    
    // 先给最后一位加1，赋值
    digits[digitsSize - 1]++;
    // 从后往前，赋值其他的，如果为9，前一位加1，不为9，则不变
    for (i = digitsSize - 1; i > 0; i--) {
        if (digits[i] > 9) {
            digits[i] = digits[i] % 10;
            digits[i - 1]++;
        }
    }
    
    // 如果首位大于9，则需要后移一位赋值
    if (digits[0] > 9) {
        j = 1;
        *returnSize = reslen;
        res[0] = 1;
    } else {
        *returnSize = reslen - 1;
    }

    // 赋值
    for (i = 0; i < digitsSize; i++) {
        res[j] = digits[i] % 10;
        j++;
    }

    return res;
}

int* plusOneArray(int* digits, int digitsSize, int* returnSize)
{
    int flag = 0;
    for (int i = (digitsSize - 1); i >=0 ; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
            flag = 1;
        } else {
            if (i != (digitsSize - 1)) {
                digits[i] += flag;
            } else {
                digits[i] += 1;
            }
            flag = 0;
            break;
        }
    }

    if (flag == 1) {
        int resLen = digitsSize + 1;

        int* res = (int*)malloc(resLen * sizeof(int));
        if (res == NULL) {
            *returnSize = 0;
            return NULL;
        }

        res[0] = 1;
        memset(&res[1], 0, digitsSize*sizeof(int));
        memcpy(&res[1], digits, digitsSize*sizeof(int));
        *returnSize = digitsSize + 1;
        return res;
    } else {
        *returnSize = digitsSize;
        return digits;
    }
}


int* plusOneArray2(int* digits, int digitsSize, int* returnSize)
{
    int flag9 = 1;
    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] != 9) {
            flag9 = 0;
            break;
        }
    }

    // 全是9，单独处理，因为增加了一位，不能使用源数组，要重新申请内存
    if (flag9 == 1) {
        int resLen = digitsSize + 1;

        int* res = (int*)malloc(resLen * sizeof(int));
        if (res == NULL) {
            *returnSize = 0;
            return NULL;
        }

        res[0] = 1;
        memset(&res[1], 0, digitsSize*sizeof(int));
        *returnSize = digitsSize + 1;
        return res;
    }

    int flag = 0;
    for (int i = (digitsSize - 1); i >=0 ; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
            flag = 1;
        } else {
            if (i != (digitsSize - 1)) {
                digits[i] += flag;
            } else {
                digits[i] += 1;
            }
            break;
        }
    }

    *returnSize = digitsSize;
    return digits;
}

int* plusOneArray3(int* digits, int digitsSize, int* returnSize)
{
    int flag9 = 1;
    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] != 9) {
            flag9 = 0;
            break;
        }
    }

    // 全是9，单独处理，因为增加了一位，不能使用源数组，要重新申请内存
    if (flag9 == 1) {
        int resLen = digitsSize + 1;

        int* res = (int*)malloc(resLen * sizeof(int));
        if (res == NULL) {
            *returnSize = 0;
            return NULL;
        }

        res[0] = 1;
        memset(&res[1], 0, digitsSize*sizeof(int));
        *returnSize = digitsSize + 1;
        return res;
    }

    // 最后一位不是9，直接加一返回
    if (digits[digitsSize - 1] != 9) {
        digits[digitsSize - 1] += 1;
        *returnSize = digitsSize;
        return digits;
    }

    // 最后一位是9
    for (int i = (digitsSize - 1); i >=0 ; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i] += 1;
            break;
        }
    }

    *returnSize = digitsSize;
    return digits;
}