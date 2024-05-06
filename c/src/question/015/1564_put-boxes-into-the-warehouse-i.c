/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1564. 把箱子放进仓库里 I
 * link: https://leetcode-cn.com/problems/put-boxes-into-the-warehouse-i/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/1.
 */

#include "public.h"

int maxBoxesInWarehouse(int* boxes, int boxesSize, int* warehouse, int warehouseSize)
{
    int pos = warehouseSize - 1;
    int count = 0;
    // 对boxes排序，从小到大
    qsort(boxes, boxesSize, sizeof(int), QsortCmpArrayAscOrder);

    // 预处理warehouse，如果某个点之后的值比当前值大，用当前值覆盖，反正比当前值大的boxes也放不进去
    for (int i = 1; i < warehouseSize; i++) {
        if (warehouse[i] > warehouse[i - 1]) {
            warehouse[i] = warehouse[i - 1];
        }
    }

    // 遍历，从后往前推箱子
    for (int i = 0; i < boxesSize; i++) {
        for (int j = pos; j >=0; j--) {
            if (warehouse[j] >= boxes[i]) {
                count++;
                pos = j - 1;
                break;
            }
        }
    }

    return count;
}


/*
void main()
{
    int box[100] = {4,3,4,1};
    int ware[100] = {5,3,3,4,1};

    printf("%d", maxBoxesInWarehouse(box, 4, ware,5));
}*/
