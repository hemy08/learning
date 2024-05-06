/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved. 
 * Description: 287. 寻找重复数
 * link: https://leetcode-cn.com/problems/find-the-duplicate-number/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int findDuplicate(int* nums, int numsSize){
    int i =0;
    qsort(nums, numsSize, sizeof(int), QsortCmpArrayAscOrder);
    for(int j = 1; j < numsSize; j++)
    {
        if(nums[j] == nums[i])
        {
            return nums[j];
        }
        i++;
    }
    return 0;
}