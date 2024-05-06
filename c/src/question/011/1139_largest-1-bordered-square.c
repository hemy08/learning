/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 1139. 最大的以 1 为边界的正方形
 * link: https://leetcode-cn.com/problems/largest-1-bordered-square/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/7/13.
 */

#include "public.h"

int getLagestNum(int **grid, int row, int col)
{
    int i;
    // 只有一列
    if (col == 1) {
        for (i = 0; i < row; i++) {
            if (grid[i][0] == 1) {
                return 1;
            }
        }

        return 0;
    }

    // 只有一行
    if (row == 1) {
        qsort((int*)grid[0], col, sizeof(int), QsortCmpArrayDescOrder);
        return grid[0][0];
    }

    // 从对角线找max
    int max = MIN_VAL(col, row);
    int pos = max;
    int flag = true;
    while (pos) {
        flag = true;
        // up 行上找到第一个为0的
        for (i = 0; i < pos; i++) {
            //上边界
            if (grid[0][i] == 0) {
                flag = false;
                break;
            }
            //左边界
            if (grid[i][0] == 0) {
                flag = false;
                break;
            }
            //下边界
            if (grid[pos - 1][i] == 0) {
                flag = false;
                pos--;
                break;
            }
            //右边界
            if (grid[i][pos - 1] == 0) {
                flag = false;
                pos--;
                break;
            }
        }

        if (!flag) {
            continue;
        } else {
            break;
        }
    }

    while (max) {
        if (grid[max][max] == 1) {
            max = pos + 1;
            return max;
        }
        max--;
    }

    return max;
}

int largest1BorderedSquare(int grid[3][3], int gridSize, int *gridColSize)
{
    int i,j,cur;
    int max = 0;
    int col = *gridColSize; // 列
    int row = gridSize; //行

    // 只有一行
    if (gridSize == 1) {
        qsort((int*)grid[0], gridColSize[0], sizeof(int), QsortCmpArrayDescOrder);
        return grid[0][0];
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (grid[i][j] != 1) {
                continue;
            }

            if (((i + max) > row) || ((j + max) > col)) {
                break;
            }

            cur = getLagestNum(grid[i][j], row - i, col - j);
            max = GetMaxValue(max, cur);
        }
    }

    return max * max;
}


int largest1BorderedSquare2(int** grid, int gridSize, int* gridColSize){
    if(gridSize==0||gridColSize[0]==0)
        return 0;
    int m=gridSize,n=gridColSize[0];
    int max=0,flag1,flag2,cur;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==1)
            {
                flag1=true;
                cur=max;
                while((i+cur)<m&&(j+cur)<n)
                {
                    flag2=true;
                    for(int x=0;x<cur+1;x++)
                    {
                        //上边界
                        if(grid[i][j+x]==0) {
                            flag1 = false;
                            break;
                        }
                        //左边界
                        if(grid[i+x][j]==0) {
                            flag1 = false;
                            break;
                        }
                        //右边界
                        if(grid[i+x][j+cur] == 0) {
                            flag2=false;
                            cur+=1;
                            break;
                        }
                        //下边界
                        if(grid[i+cur][j+x]==0) {
                            flag2=false;
                            cur+=1;
                            break;
                        }
                    }
                    if(!flag1)
                        break;
                    if(!flag2)
                        continue;
                    cur+=1;
                    max=cur;
                }
            }
        }
    }
    return max*max;
}