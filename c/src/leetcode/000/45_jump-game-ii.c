/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 45. 跳跃游戏 II
 * link: https://leetcode-cn.com/problems/jump-game-ii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/1.
 */

#include "public.h"

int jump(int* nums, int numsSize)
{
    int count = 0;
    int pos = 0; // 起始位置在下标为0的位置

    while (pos < numsSize) {
        int steps = 0;
        int next = nums[pos];
        // 如果当前位置只能走一步，那么向前跳一步
        if (nums[pos] == 1) {
            count++;
            pos++;
        }

        // 最大可以走nums[pos]步数，从这些里面找到最大的值，下一次以这个位置为起点
        for (int i = pos; i < pos + nums[pos]; i++) {
            if (nums[i] > steps) {
                steps = nums[i];
                next = i;
            }
        }

        // 到新起点next，跳一步
        count++;
        pos = next;
        if (pos >= (numsSize - 1)) {
            return count;
        }

    }

    return count;
}
/*
class Solution {
        public:
        int jump(vector<int>& nums) {
            int maxPos = 0, n = nums.size(), end = 0, step = 0;
            for (int i = 0; i < n - 1; ++i) {
                if (maxPos >= i) {
                    maxPos = max(maxPos, i + nums[i]);
                    if (i == end) {
                        end = maxPos;
                        ++step;
                    }
                }
            }
            return step;
        }
};*/
