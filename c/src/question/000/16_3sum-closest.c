/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 16. 最接近的三数之和
 * link: https://leetcode-cn.com/problems/3sum-closest/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/24.
 */

#include "public.h"

#define TARGET_MAX  10000

int threeSumClosest(int nums[], int numsSize, int target)
{
    int min = TARGET_MAX;
    int i, abs_result, ret;
    for (i = 0; i < numsSize; i++) {
        if (target != nums[i]){
            ret = nums[i] + threeSumClosest(&nums[i + 1], numsSize - i - 1, target - nums[i]);
        } else {
            ret = nums[i];
        }
        abs_result = abs(ret - target);
        if (abs_result < min) {
            return ret;
        }
    }

    return 0;
}

/*
void main()
{
    int nums[256] = {1, 1, -1, -1, 3};

    int result = threeSumClosest(nums, 5, 3);

    printf("%d\n", result);
}*/
