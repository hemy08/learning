/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/9/1.
 */

#include "public.h"

bool isColValidSudoku(char** board, int boardSize, int* boardColSize) {
    for (int i = 0; i < 9; i++) {
        int hasTbl[10] = {0};
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                continue;
            }

            int val = board[i][j] - '0';
            if (hasTbl[val] != 0) {
                return false;
            }  else {
                hasTbl[val] = 1;
            }
        }
    }

    return true;
}

bool isRowValidSudoku(char** board, int boardSize, int* boardColSize){
    for (int i = 0; i < 9; i++) {
        int hasTbl[10] = {0};
        for (int j = 0; j < 9; j++) {
            if (board[j][i] == '.') {
                continue;
            }

            int val = board[j][i] - '0';
            if (hasTbl[val] != 0) {
                return false;
            }  else {
                hasTbl[val] = 1;
            }
        }
    }

    return true;
}

bool checkSeqValidSudoku(char** board, int boardSize, int* boardColSize, int i,int j) {
    int hasTbl[10] = {0};
    for (int m = 0; m < 3; m++) {
        for (int n = 0; n < 3; n++) {
            if (board[m+i][n+j] == '.') {
                continue;
            }

            int val = board[m+i][n+j] - '0';
            if (hasTbl[val] != 0) {
                return false;
            }  else {
                hasTbl[val] = 1;
            }
        }
    }

    return true;
}

bool isSeqValidSudoku(char** board, int boardSize, int* boardColSize){
    for (int i = 0; i < 9; i+=3) {
        for (int j = 0; j < 9; j+=3) {
            if (checkSeqValidSudoku(board,boardSize,boardColSize,i,j) == false) {
                return false;
            }
        }
    }
    return true;
}

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    bool colValid = isColValidSudoku(board,boardSize,boardColSize);
    bool rowValid = isRowValidSudoku(board,boardSize,boardColSize);
    bool seqValid = isSeqValidSudoku(board,boardSize,boardColSize);
    return colValid && rowValid && seqValid;
}
