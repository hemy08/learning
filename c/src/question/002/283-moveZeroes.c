/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/9/1.
 */

#include "public.h"

void moveZeroes(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            continue;
        }

        for (int j = i+1; j < numsSize; j++) {
            if (nums[j] != 0) {
                nums[i] = nums[j];
                nums[j] = 0;
                break;
            }
        }
    }
}


void moveZeroes2(int* nums, int numsSize){
    int end = numsSize - 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            continue;
        }

        int j = end;
        int tmp = nums[j];
        while(j > i) {
            int tmp2 = nums[j - 1];
            nums[j - 1] = tmp;
            tmp = tmp2;
            j--;
        }

        nums[end] = 0;
        end--;
        if (end <= i) {
            break;
        }
    }
}