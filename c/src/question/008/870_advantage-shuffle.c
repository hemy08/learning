/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description: 
 * link: 
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/1.
 */

#include "public.h"

/*
#define MAX_NUMS 10001

int comp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize)
{
    int sortB[MAX_NUMS][2] = {{0}};

    // 记录B中每个数字的值以及所在的位置
    for (int i = 0; i < BSize; i++) {
        sortB[i][0] = B[i];
        sortB[i][1] = i;
    }

    qsort(A, ASize, sizeof(int), comp);
    qsort(sortB, BSize, sizeof(int) * 2, comp);

    // 对B进行排序后，匹配每一个满足优势条件的值
    int *result = (int*)malloc(sizeof(int) * ASize);
    (void)memset(result, -1, sizeof(int) * ASize);
    int left = 0;
    int right = BSize - 1;
    for (int i = 0; i < ASize; i++) {
        if (A[i] > sortB[left][0]) {
            result[sortB[left][1]] = A[i];
            left++;
        } else {
            result[sortB[right][1]] = A[i];
            right--;
        }

        OutPutArrays(result, ASize);
    }

    *returnSize = ASize;
    return result;
}
*/


#define MAX_NUMS 10001

int compAdvantageCount(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize)
{
    qsort(A, ASize, sizeof(int), compAdvantageCount);
    *returnSize = ASize;

    bool flags[MAX_NUMS] = {false};
    int sortB[MAX_NUMS][2] = {{0}};

    // 记录B中每个数字的值以及所在的位置
    for (int i = 0; i < BSize; i++) {
        sortB[i][0] = B[i];
        sortB[i][1] = i;
    }
    qsort(sortB, BSize, sizeof(int) * 2, compAdvantageCount);

    // 对B进行排序后，匹配每一个满足优势条件的值
    int *result = (int*)malloc(sizeof(int) * ASize);
    (void)memset(result, -1, sizeof(int) * ASize);
    for (int i = 0; i < BSize; i++) {
        for (int j = 0; j < ASize; j++) {
            // 值已经取过了
            if (flags[j] == true) {
                continue;
            }

            // 满足优势条件，填值,然后退出，继续找下一个
            if (A[j] > sortB[i][0]) {
                flags[j] = true;
                result[sortB[i][1]] = A[j];
                break;
            }
        }
    }

    // 不满足优势条件的值填写
    for (int i = 0; i < ASize; i++) {
        if (result[i] != -1) {
            continue;
        }

        for (int j = 0; j < ASize; j++) {
            // 值已经取过了
            if (flags[j] == true) {
                continue;
            }
            flags[j] = true;
            result[i] = A[j];
            break;
        }
    }
    return result;
}

/*void main()
{
    int A[100] = {718967141,189971378,341560426,23521218,339517772};
    int B[100] = {967482459,978798455,744530040,3454610,940238504};
    int result = 0;

    OutPutArrays(advantageCount(A, 5, B, 5, &result), result);
}*/
/*

struct side
{
    int val;
    int tige;
}; // 这个结构体的目的是用来存B数组的值和索引
int cmp(const void * a, const void * b) // 这个是结构体的比较器
{
    struct side * c, * d;
    c = (struct side *) a;
    d = (struct side *) b;
    return c -> val - d -> val;
}
int cmp1(const void * a, const void * b) // A数组的比较器
{
    return *(int *) a - *(int *) b;
}

int* advantageCount(int* A, int ASize, int* B, int BSize, int* returnSize){
    int i, l = 0, r = BSize - 1; // r作用是记录排好序B数组最大的值的位置
    struct side * head;
    int *list; // 是用来还回的数组
    // 创数组
    list = (int *)malloc(sizeof(int) * (ASize + 2));
    head = (struct side *)malloc(sizeof(struct side) *(BSize + 2));

    for (i = 0; i < BSize; i++) // 把B数组的值赋给结构体
    {
        head[i].val = B[i];
        head[i].tige = i;
    }
    qsort(A, ASize, sizeof(int), cmp1); // 进行排列
    qsort(head, BSize, sizeof(struct side), cmp);
    for (i = 0; i < ASize; i++)
    {
        if(A[i] > head[l] . val) // 如果A数组的值大于B数组的值则把A[i]的值赋给list数组中的B数组的索引。
        {
            list[head[l] . tige] = A[i];
            l++;
        }
        else
        {
            list[head[r] . tige] = A[i]; // 如果是小于等于则把A[i]的值放在list数组中B数组最大的索引位置。
            r--;
        }
    }
    *returnSize = ASize;
    return list;
}*/
