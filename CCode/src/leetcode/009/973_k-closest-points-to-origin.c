/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 973. 最接近原点的 K 个点
 * link: https://leetcode-cn.com/problems/k-closest-points-to-origin/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/11/9.
 */

#include "public.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define POW_VAL(x) ((x) * (x))
#define POW_RESULT(a, b)  (POW_VAL(a) + POW_VAL(b))

int compareClosest(void *a, void *b)
{
    int *l1 = *(int**)a;
    int *l2 = *(int**)b;

    double pow1 = POW_RESULT(abs((double)(l1[0])),abs((double)(l1[1])));
    double pow2 = POW_RESULT(abs((double)(l2[0])),abs((double)(l2[1])));

    if (pow1 > pow2) {
        return 1;
    }

    return 0;
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes)
{
    qsort(points, pointsSize,sizeof(int) * (*pointsColSize), compareClosest);
    *returnSize = K;
    *returnColumnSizes = pointsColSize;
    return points;
}

/*
int main()
{
    int a[5][2] = {
            {1,3}, {-2,2}
    };

    int ret_size = 0;
    int *retColSize = NULL;
    int **b = kClosest(a, 2, 2, 1, &ret_size, &retColSize);
    return 0;
}*/
