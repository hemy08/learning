/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2021/6/4.
 */

#include "public.h"

// 快速排序，数组，升序排序
int CompArray(const void *p1, const void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    const int maxArrLen = 2000;
    const int oddEven = 2;
    const double getAver = 2.0;
    int mArr[maxArrLen + 1];
    int total = nums1Size + nums2Size;

    if (total == 0) {
        return 0;
    }

    (void) memset(mArr, 0,  (maxArrLen + 1) * sizeof(int));

    int iRet = memcpy(mArr, nums1, nums1Size * sizeof(int));
    if (iRet == -1) {
        printf("memcpy nums1 failed\r\n");
        return (double)0;
    }

    iRet = memcpy(&mArr[nums1Size], nums2, nums2Size * sizeof(int));
    if (iRet == -1) {
        printf("memcpy nums2 failed\r\n");
        return (double)0;
    }

    qsort(mArr, total, sizeof(int), CompArray);
    if (total == 1) {
        return (double)mArr[0];
    }

    printf("TOTAL %d\r\n", total);
    // 奇数
    int mid = total / oddEven - 1;
    int numType = total % oddEven;
    printf("total / 2 = %d, total %% 2 = %d\r\n", mid, numType);
    printf("mArr[mid] = %d, mArr[mid+1] = %d\r\n", mArr[mid], mArr[mid + 1]);
    if (numType != 0) {
        return (double)(mArr[mid + 1]);
    } else {
        return (double)((mArr[mid] + mArr[mid + 1]) / getAver);
    }
}

void TEST_4_findMedianSortedArrays_1()
{
    int A[2] = {1,3};
    int B[1] = {2};

    PRINT_CONSOLE(INFO, "=====================Begin");
    double result = findMedianSortedArrays(&A, 2, &B, 1);

    PRINT_CONSOLE(INFO, "except: 2.000000, result %f", result);
    assert(result == (double)2);
}

void TEST_4_findMedianSortedArrays_2()
{
    int A[2] = {0,0};
    int B[2] = {0,0};

    PRINT_CONSOLE(INFO, "=====================Begin");
    double result = findMedianSortedArrays(&A, 2, &B, 2);

    PRINT_CONSOLE(INFO, "except: 0.000000, result %f", result);
    assert(result == (double)0);
}

void TEST_4_findMedianSortedArrays_3()
{
    int A[] = {};
    int B[1] = {1};

    PRINT_CONSOLE(INFO, "=====================Begin");
    double result = findMedianSortedArrays(&A, 0, &B, 1);

    PRINT_CONSOLE(INFO, "except: 1.000000, result %f", result);
    assert(result == (double)1);
}

void TEST_4_findMedianSortedArrays_4()
{
    int A[2] = {1,2};
    int B[2] = {3,4};

    PRINT_CONSOLE(INFO, "=====================Begin");
    double result = findMedianSortedArrays(&A, 2, &B, 2);

    PRINT_CONSOLE(INFO, "except: 2.500000, result %f", result);
    assert(result == (double)2.5);
}

void TEST_4_findMedianSortedArrays()
{
    TEST_4_findMedianSortedArrays_1();
    TEST_4_findMedianSortedArrays_2();
    TEST_4_findMedianSortedArrays_3();
    TEST_4_findMedianSortedArrays_4();
}