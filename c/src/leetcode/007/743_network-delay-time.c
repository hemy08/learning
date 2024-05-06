/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 743. 网络延迟时间
 * link: https://leetcode-cn.com/problems/network-delay-time/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/8/8.
 */

#include "public.h"

#define MAX_NET_NUM 100
#define MAX_INF 0x3F3F3F3F  // 定义一个相对的无穷大
int dijkstraMap[MAX_NET_NUM + 1][MAX_NET_NUM + 1] = {{0}};

void DijkstraInit()
{
    memset(dijkstraMap, MAX_INF, sizeof(dijkstraMap));
    for(int i = 0; i < MAX_NET_NUM; i++) {
        dijkstraMap[i][i] = 0;
    }
}

// 给定一个列表 times，表示信号经过有向边的传递时间。 
// times[i] = (u, v, w)，其中 u 是源节点，v 是目标节点， w 是一个信号从源节点传递到目标节点的时间。
// 无向图
void DijkstraCreateNoDirection(int** times, int timesSize)
{
    int u, v, w;
    for (int i = 0; i < timesSize; i++)  {
        u = times[i][0];
        v = times[i][1];
        w = times[i][2];
        if (dijkstraMap[u][v] > w) {
            dijkstraMap[u][v] = w;
            dijkstraMap[v][u] = w;
        }
    }
}

// 有向图
void DijkstraCreateDirection(int** times, int timesSize)
{
    int u, v, w;
    for (int i = 0; i < timesSize; i++)  {
        u = times[i][0];
        v = times[i][1];
        w = times[i][2];
        if (dijkstraMap[u][v] > w) {
            dijkstraMap[u][v] = w;
        }
    }
}

int DijkstraGet(int num, int key)
{
    int vis[MAX_NET_NUM + 1] = {0};
    int dis[MAX_NET_NUM + 1] = {0};

    memset(vis, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));

    // 顶点K到其他各个顶点的初始路程，顶点N的范围在 [1, 100] 之间
    for (int i = 1; i <= num; i++) {
        dis[i] = dijkstraMap[key][i];
    }

    // 记录顶点是否访问过
    vis[key] = 1;
    for (int i = 1; i <= num; i++) {
        int minn = MAX_INF;
        int temp = 0;

        // 下一个与Key相连的没访问的顶点
        for (int j = 1; j <= num; j++) {
            if (vis[j]) { // 已经访问过，就不再访问
                continue;
            }

            // 不是无穷大，找下一个没有访问的顶点
            if (dis[j] < minn) {
                minn = dis[j];
                temp = j;
            }
        }
        // printf("temp %d, dis[temp] %d\n", temp, dis[temp]);
        // 标记temp顶点已经访问过
        vis[temp] = 1;
        // temp为顶点，计算到其他各个顶点的最小距离，贪心算法，key为顶点到temp的最小距离是dis[temp]
        // 循环结束后，得到dis[k]是以key为顶点，经过temp到k的最小距离
        for(int k = 1; k <= num; k++) {
            // printf("dis[%d] %d \n", k, dis[k]);
            if (dijkstraMap[temp][k] + dis[temp] < dis[k]) {
                dis[k] = dijkstraMap[temp][k] + dis[temp];
                // printf("dis[%d] %d \n", k, dis[k]);
            }
        }
    }

    int curMax = 0;
    for (int i = 1; i <= num; i++) {
        if (curMax < dis[i]) {
            curMax = dis[i];
        }
    }

    if (curMax == MAX_INF) {
        return -1;
    }

    return curMax;
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int N, int K)
{
    DijkstraInit();
    DijkstraCreateDirection(times, timesSize);
    return DijkstraGet(N,K);
}