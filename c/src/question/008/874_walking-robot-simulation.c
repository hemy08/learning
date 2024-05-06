/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 874. 模拟行走机器人
 * link: https://leetcode-cn.com/problems/walking-robot-simulation/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int compRobotSim(const void *a, const void *b)
{
    int **aa = (int**)a;
    int **bb = (int**)b;
    return aa[0] - bb[0];
}

// 二分法查找
bool binarySearchWalking(int x, int y, int** obstacles, int obstaclesSize, int begin, int end)
{
    if (begin > end) {
        return false;
    }

    int mid  = (begin + end) / 2;
    // 因为x相同的时候，要判断y的值，y没有排序，因此从mid往前和往后都找
    if (obstacles[mid][0] == x) {
        // 往后找
        for (size_t i = mid; i <= end; i++) {
            if (obstacles[i][0] != x) {
                break;
            }

            if (obstacles[i][1] == y) {
                return true;
            }
        }

        // 往前找
        for (size_t i = mid; i > begin; i--) {
            if (obstacles[i][0] != x) {
                break;
            }

            if (obstacles[i][1] == y) {
                return true;
            }
        }

        // begin = end的时候，前面俩都走不到
        if (obstacles[mid][1] == y) {
            return true;
        }
        
        // 没找到
        return false;
        
    } else if (obstacles[mid][0] < x) {
        // mid比x小，则说明x在后半段，从mid + 1 到 end找
        return binarySearchWalking(x, y, obstacles, obstaclesSize, mid + 1, end);
    } else {
        // mid的比x大，则说明x在前半段，从begin 到 mid - 1找
        return binarySearchWalking(x, y, obstacles, obstaclesSize, begin, mid - 1);
    } 
}

// 检索会超时，需要一个好的搜索算法
bool judegIsObstructions(int x, int y, int** obstacles, int obstaclesSize) 
{
    return binarySearchWalking(x, y, obstacles, obstaclesSize, 0, obstaclesSize - 1);
}

void robotMonves(int *x, int*y, int drct, int cmds, int** obstacles, int obstaclesSize)
{
    // 往x和y方向移动
    int nx[4] = {0,1,0,-1};
    int ny[4] = {1,0,-1,0};

    // 每次移动一步，判断下一步是否是障碍物
    for (int i = 0; i < cmds; i++) {
        int newx = *x + nx[drct];
        int newy = *y + ny[drct];
        // 如果下一个是障碍物，则不再移动
        if (judegIsObstructions(newx, newy, obstacles, obstaclesSize)) {
            return;
        }
        *x = newx;
        *y = newy;
    }

    return;
}

int robotSim(int* commands, int commandsSize, int** obstacles, int obstaclesSize, int* obstaclesColSize)
{
    int x = 0;
    int y = 0;
    int direction = 0;
    int max = 0;

    // not find commands
    if (commandsSize == 0) {
        return 0;
    }

    // 先把障碍点，按照x轴从小到大进行排序，方便后面的二分法查找
    qsort(obstacles,obstaclesSize, sizeof(int*), compRobotSim);

    for (int i = 0; i < commandsSize; i++) {
        if (commands[i] > 0) { // 移动
            robotMonves(&x, &y, direction, commands[i], obstacles, obstaclesSize);
            max = MAX_VAL(max, ((x * x) + (y * y)));
        } else if (commands[i] == -1) { // 左转 + 1
            direction = (direction + 1) % 4;
        } else if (commands[i] == -2) { // 右转90°，相当于左转270°
            direction = (direction + 3) % 4;
        } else { // 非法值
            return 0;
        }
    }

    return max;
}