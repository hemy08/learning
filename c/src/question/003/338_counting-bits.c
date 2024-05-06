/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved. 
 * Description: 338. 比特位计数
 * link: https://leetcode-cn.com/problems/counting-bits/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cover(int num)
{
    int count = 0;    
    while(num)
    {
        if(num % 2 != 0)
        {
            count++;
        }
        num /= 2;
    }
    return count;
}

int* countBits(int num, int* returnSize){
    *returnSize = num + 1;
    int* a = calloc(num + 1, sizeof(int));
    for(int i = 0; i <= num; i++)
    {
        a[i] = cover(i); 
    }
    return a;
}