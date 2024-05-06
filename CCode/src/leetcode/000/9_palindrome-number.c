/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 9. 回文数
 * link: https://leetcode-cn.com/problems/palindrome-number/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

bool intToChar(int x, char *acBuf, int  len)
{
    for (int i = 0; i < len; ++i) {
        acBuf[i] = x%10 + 0x30;
        x /= 10;
        if (x == 0) {
            return true;
        }
    }

    return false;
}

bool isPalindrome(int x){
    char acDig[12] = {0};
    char  *ret = NULL;
    int nDigNum = 0;
    int maxForTim = 0; // 控制最大循环次数

    // 回文数必须是正整数
    if (x < 0) {
        return false;
    }

    if (intToChar(x,acDig,12) == false) {
        return  false;
    }

    // 循环，进行判断
    nDigNum = strlen(acDig);
    maxForTim = nDigNum/2;
    for (int j = 0; j <= maxForTim; ++j) {
        if (acDig[j] != acDig[nDigNum-j-1]) {
            return false;
        }
    }

    return true;
}


bool isPalindromeTwo(int x)
{

    if (x < 0) {
        return false;
    }

    char nums[32] = {0};

    int numsSize = 0;
    while(x != 0) {
        nums[numsSize++] = x % 10 + 0x30;
        x = x / 10;
    }

    int max = numsSize / 2;
    for (int i = 0; i < max; i++){
        if (nums[i] != nums[numsSize - i - 1]) {
            return false;
        }
    }

    return true;
}