/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 562. 矩阵中最长的连续1线段
 * link: https://leetcode-cn.com/problems/longest-line-of-consecutive-one-in-matrix/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */
#include "public.h"

/*
RecordMatrix {
    int maxInRow; // 横
    int maxInLine; // 竖
    int maxInX; // 对角
    int maxInY; // 反对角
};
*/

int g_max;
void longestLineRow(int** M, int i, int j, RecordMatrix** g_record){
    if (j == 0) {
        g_record[i][j].maxInRow = 1;
    } else {
        g_record[i][j].maxInRow = g_record[i][j - 1].maxInRow + 1;
    }

    if (g_max < g_record[i][j].maxInRow) {
        g_max = g_record[i][j].maxInRow;
    }
}

void longestLineLine(int** M, int i, int j, RecordMatrix** g_record){
    if (i == 0) {
        g_record[i][j].maxInLine = 1;
    } else {
        g_record[i][j].maxInLine = g_record[i - 1][j].maxInLine + 1;
    }

    if (g_max < g_record[i][j].maxInLine) {
        g_max = g_record[i][j].maxInLine;
    }
}
void longestLineX(int** M, int i, int j, RecordMatrix** g_record){
    if (i == 0 || j == 0) {
        g_record[i][j].maxInX = 1;
    } else {
        g_record[i][j].maxInX = g_record[i - 1][j - 1].maxInX + 1;
    }

    if (g_max < g_record[i][j].maxInX) {
        g_max = g_record[i][j].maxInX;
    }
}

void longestLineY(int** M, int i, int j, int maxJ, RecordMatrix** g_record){
    if (i == 0 || j == (maxJ - 1)) {
        g_record[i][j].maxInY = 1;
    } else {
        g_record[i][j].maxInY = g_record[i - 1][j + 1].maxInY + 1;
    }

    if (g_max < g_record[i][j].maxInY) {
        g_max = g_record[i][j].maxInY;
    }
}

int longestLine(int** M, int MSize, int* MColSize){
    int i;
    int j;

    RecordMatrix** g_record = (RecordMatrix**)malloc(MSize * sizeof(RecordMatrix*));

    for (i = 0; i < MSize; i++) {
        g_record[i] = malloc(sizeof(RecordMatrix) * MColSize[i]);
        memset(g_record[i], 0, sizeof(RecordMatrix) * MColSize[i]);
    }

    g_max = 0;
    for (i = 0; i < MSize; i++) {
        for (j = 0; j < MColSize[i]; j++) {
            if (M[i][j] == 1) {
                longestLineRow(M, i, j, g_record);
                longestLineLine(M, i, j, g_record);
                longestLineX(M, i, j, g_record);
                longestLineY(M, i, j, MColSize[i], g_record);
            }
        }
    }

    return g_max;
}