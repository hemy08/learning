/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 349. 两个数组的交集
 * link: https://leetcode-cn.com/problems/intersection-of-two-arrays/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */

#include "public.h"

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int retSize = MIN_VAL(nums1Size, nums2Size);
    int *result = NULL;
    int count = 0;

    if ((nums1 == NULL) || (nums1Size == 0) || (nums2 == NULL) || (nums2Size == 0)) {
        *returnSize = 0;
        return NULL;
    }

    result = (int*)malloc(sizeof(int) * (retSize + 1));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // 获取值
    for (int i = 0; i < nums1Size; i++) {
        int flag = 0;
        // result中已经有的，就不再检查
        for (int k = 0; k < count; k++) {
            if (nums1[i] == result[k]) {
                flag = 1;
                break;
            }
        }

        if (flag) {
            continue;
        }

        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                result[count] = nums1[i];
                count++;
                break;
            }
        }
    }

    *returnSize = count;

    return result;
}