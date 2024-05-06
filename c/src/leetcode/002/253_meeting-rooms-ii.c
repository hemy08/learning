/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 253. 会议室 II
 * link: https://leetcode-cn.com/problems/meeting-rooms-ii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00226060 on 2020/6/15.
 */

#include "public.h"

#define MAX_TIME  0xfffff
int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize)
{
    int i,j,s1,s2,max;
    max = 0;
    int res = 0;
    int *g_ulCount = 0;
    g_ulCount = malloc(MAX_TIME*4);
    if(g_ulCount == 0)
    {
        return 0;
    }
    memset(g_ulCount,0,MAX_TIME*4);
    for(i = 0;i < intervalsSize;i++)
    {

        s1 = intervals[i][0];
        max = max > s1 ? max : s1;
        s2 = intervals[i][1];
        max = max > s2 ? max : s2;
        //  printf("loop %d,s1 = %d,s2 = %d.max = %d.\n", i,s1,s2,max);

        for(;s1 < s2 ;s1++)
        {
            g_ulCount[s1] = g_ulCount[s1] + 1;
            // printf("g_ulCount[%d] %d\n", s1,g_ulCount[s1]);
        }
    }
    for(i = 0;i < max;i++)
    {
        res = res > g_ulCount[i] ? res : g_ulCount[i];
        //  printf("g_ulCount[%d] %d\n", i,g_ulCount[i]);

    }
    // printf("res %d\n", res);
    return res;
}