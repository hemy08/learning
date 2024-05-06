/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 904. 水果成篮
 * link: https://leetcode-cn.com/problems/fruit-into-baskets/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/11/12.
 */

#include "public.h"

#define MAX_FRUIT_TYPE_NUM  40000

int totalFruit(int* tree, int treeSize)
{
    int fruits[2] = {-1};
    int max_size = 0;
    int left = 0;

    fruits[0] = tree[0];
    for (int i = 0; i < treeSize; i++) {
        // 找第二种水果
        if ((tree[i] != fruits[0]) && (fruits[1] == -1)) {
            fruits[1] = tree[i];
            continue;
        }

        // 出现第三种水果
        if ((tree[i] != fruits[0]) && (tree[i] != fruits[1])) {
            int cur = i - left + 1;
            max_size = GetMaxValue(cur, max_size);
            // 从当前位置往前，找到第二个与当前位置不一样的地方，记录新的left
            int pre_fruit = tree[i - 1];
            for (int j = i - 1; j >= 0; j--) {
                if (tree[j] != pre_fruit) {
                    left = j + 1;
                    break;
                }
            }

            // 上一个窗口，最左侧是pre_fruit
            if (fruits[0] != pre_fruit) {
                fruits[0] = fruits[1];
            }
            fruits[1] = tree[i];
        }
    }

    return max_size;
}

