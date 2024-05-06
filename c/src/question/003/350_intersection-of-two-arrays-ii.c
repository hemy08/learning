/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 350. 两个数组的交集 II
 * link: https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

#include "public.h"

int *intersectWithMinVal(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int retSize = GetMinValue(nums1Size, nums2Size);
    int *result = NULL;
    int count = 0;

    result = (int*)malloc(sizeof(int) * (retSize + 1));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // 获取值
    for (int i = 0; i < nums1Size; i++) {
        for (int j = i; j < nums2Size && j < nums1Size; j++) {
            if (nums1[i] == nums2[j]) {
                result[count] = nums1[i];
                count++;
                break;
            }
        }
    }

    *returnSize = count;

    return result;
}


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int retSize = MIN_VAL(nums1Size, nums2Size);
    int *result = NULL;
    int count = 0;

    if ((nums1 == NULL) || (nums1Size == 0) || (nums2 == NULL) || (nums2Size == 0)) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums1, nums1Size, sizeof(int), QsortCmpArrayAscOrder);
    qsort(nums2, nums2Size, sizeof(int), QsortCmpArrayAscOrder);

    result = (int*)malloc(sizeof(int) * (retSize + 1));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // 获取值
    int tmp = 0;
    for (int i = 0; i < nums1Size; i++) {
        if (tmp >= nums2Size) {
            break;
        }

        for (int j = tmp; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                tmp = j + 1;
                result[count] = nums1[i];
                count++;
                break;
            }
        }
    }

    *returnSize = count;

    return result;
}

int compForIntersect(const void *p1, const void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

int* intersectDoublePoint(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int retSize = (int)fmin(nums1Size, nums2Size);
    int *result = NULL;
    int count = 0;

    if ((nums1 == NULL) || (nums1Size == 0) || (nums2 == NULL) || (nums2Size == 0)) {
        *returnSize = 0;
        return NULL;
    }

    qsort(nums1, nums1Size, sizeof(int), compForIntersect);
    qsort(nums2, nums2Size, sizeof(int), compForIntersect);

    result = (int*)malloc(sizeof(int) * (retSize + 1));
    if (result == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // 获取值
    int index1 = 0, index2 = 0;
    while (index1 < nums1Size && index2 < nums2Size) {
        if (nums1[index1] < nums2[index2]) {
            index1++;
        } else if (nums1[index1] > nums2[index2]) {
            index2++;
        } else {
            result[count++] = nums1[index1];
            index1++;
            index2++;
        }
    }

    *returnSize = count;

    return result;
}

struct hashTable {
    int key;
    int nums;
    UT_hash_handle hh;
};

int* intersectHashMap(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    struct hashTable* set = NULL;
    for (int i = 0; i < nums1Size; i++) {
        struct hashTable* tmp;
        HASH_FIND_INT(set, nums1+i, tmp);
        if (tmp == NULL) {
            tmp = (struct hashTable*)malloc(sizeof(struct hashTable));
            tmp->key = nums1[i];
            tmp->nums  = 1;
            HASH_ADD_INT(set, key, tmp);
        }  else {
            tmp->nums += 1;
        }
    }
    *returnSize = 0;

    int len = (int)fmax(nums1Size,nums2Size);

    int* res = (int*)malloc(len*sizeof(int));
    for (int i = 0; i < nums2Size; i++) {
        struct hashTable* tmp;
        HASH_FIND_INT(set, nums2+i, tmp);
        if ((tmp != NULL) && (tmp->nums != 0)) {
            tmp->nums--;
            res[(*returnSize)++] = nums2[i];
        }
    }
    return res;
}