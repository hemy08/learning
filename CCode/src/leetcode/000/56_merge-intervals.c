/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 56. 合并区间
 * link: https://leetcode-cn.com/problems/merge-intervals/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** mergeIntervals(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **listIn = intervals;
    int len = intervalsSize;
    int **listOut;  
    int count;    
    int i;
    
    
    // sort by start
    qsort(listIn, len, sizeof(listIn[0]), QsortCmpTwoDimArrayAscOrder);
    
    // scan ListIn
    for (i=0,count=0,listOut=NULL; i<len; i++){
        int tailOutRow = count == 0 ? -1 : count-1;
        int tailOutEnd = count == 0 ? 0 : listOut[tailOutRow][1];
        int curInStart = listIn[i][0];
        int curInEnd = listIn[i][1];
        
        
        if (i==0 || curInStart>tailOutEnd) { // can't merge
            count++;
            tailOutRow++;
            listOut = (int **)realloc(listOut, sizeof(int *)*count);
            listOut[tailOutRow] = (int *)malloc(sizeof(int)*2);
            listOut[tailOutRow][0] = curInStart;
            listOut[tailOutRow][1] = curInEnd;            
        }
        else // can merge
            listOut[tailOutRow][1] = curInEnd > tailOutEnd ? curInEnd : tailOutEnd;                     
    }
    
    // assign col size array 
    *returnColumnSizes = (int *)malloc(sizeof(int)*count);        
    for (i=0; i<count; i++)
        (*returnColumnSizes)[i] = 2;
    
    *returnSize = count;    
    return listOut;
}