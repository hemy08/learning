/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 59. 螺旋矩阵 II
 * link: https://leetcode-cn.com/problems/spiral-matrix-ii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
        int top=0,bottom=n-1;
        int left=0,right=n-1;
        int k=1;
        *returnSize = n;
        int** res = (int**)malloc(n * sizeof(int*));
        returnColumnSizes[0] = (int*)malloc(n * sizeof(int));
        for(int i = 0; i < n; i++)
        {
            res[i] = (int*)malloc(n * sizeof(int));
            memset(res[i], 0 ,n * sizeof(int));
            returnColumnSizes[0][i] = n;
        }
        while(true){
            for(int i=left;i<=right;i++) res[top][i]=k++;//向右移动直到最右
            if(++top>bottom) break;//重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for(int i=top;i<=bottom;i++) res[i][right]=k++;//向下
            if(--right<left) break;//重新设定右边界
            for(int i=right;i>=left;i--) res[bottom][i]=k++;//向左
            if(--bottom<top) break;//重新设定下边界
            for(int i=bottom;i>=top;i--) res[i][left]=k++;//向上
            if(++left>right) break;//重新设定左边界
        }
        return res;
}