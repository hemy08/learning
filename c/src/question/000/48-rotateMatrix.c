/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/9/2.
 */

#include "public.h"

void rotateMatrix(int** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 1) {
        return;
    }

    // 竖行变横行，交换对应值
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i; j < matrixSize; j++) {
            int val = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = val;
        }
    }

    // 新数组，每行进行反转
    int n = (matrixSize + 1) / 2;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < n; j++) {
            int val = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize-1-j];
            matrix[i][matrixSize-1-j] = val;
        }
    }
}