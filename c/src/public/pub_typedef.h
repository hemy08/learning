/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 
 * link: 
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/3.
 */

#ifndef HEMYCODEREPO_PUB_TYPEDEF_H
#define HEMYCODEREPO_PUB_TYPEDEF_H

#include "uthash.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

typedef struct {
    struct ListNode *head;
    struct ListNode *tail;
} MyStack;

#define MAX_NUMS_SIZE 19000
typedef struct {
    int nums[MAX_NUMS_SIZE + 1];
    int numsSize;
} MedianFinder;

typedef struct {
    int sum;
} NumArray;

// 346
typedef struct {
    int size;
    int *nums;
    int numsSize;
} MovingAverage;

#define MAX_SIZE 20480
typedef struct {
    int size;
    int nums[MAX_SIZE + 1];
    int numsSize;
} MovingAverageArray;

// 362
typedef struct {
    int ts;
    long hits;
    UT_hash_handle hh;
}HashNode;

typedef struct {
    int cts;
    long hits;
    HashNode *hash;
} HitCounter;

// 562
typedef struct record {
    int maxInRow; // 横
    int maxInLine; // 竖
    int maxInX; // 对角
    int maxInY; // 反对角
}RecordMatrix;

// 635
#define MAX_LOG_ID_NUM 301
typedef struct {
    char* history[MAX_LOG_ID_NUM];
} LogSystem;

// 1472
#define MAX_HISTORY_LIST 10000

typedef struct {
    int index;
    int cur_index;
    char url[MAX_HISTORY_LIST][32];
} BrowserHistory;

// 1483
typedef struct {
    int numbers;
    int parentSize;
    int **parent;
} TreeAncestor;
#endif //HEMYCODEREPO_PUB_TYPEDEF_H
