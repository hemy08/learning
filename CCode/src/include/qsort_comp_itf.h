/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2030. All rights reserved.
 * Description:
 * link:
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 * Created by z00579768 on 2020/12/5.
 */
#ifndef ____HEMY_CODE_REPO__SRC__QSORT_COMP_ITF___H____
#define ____HEMY_CODE_REPO__SRC__QSORT_COMP_ITF___H____
// 快速排序，二维数组，按照第一位升序排序
static inline int QsortCmpTwoDimArrayAscOrder(const void *p1, const void *p2)
{
    return ((int **)p1)[0][0] - ((int **)p2)[0][0];
}

// 快速排序，二维数组，按照第一位降序排序
static inline int QsortCmpTwoDimArrayDescOrder(const void *p1, const void *p2)
{
    return ((int **)p2)[0][0] - ((int **)p1)[0][0];
}

// 快速排序，数组，升序排序
static inline int QsortCmpArrayAscOrder(const void *p1, const void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

// 快速排序，数组，降序排序
static inline int QsortCmpArrayDescOrder(const void *p1, const void *p2)
{
    return *(int *)p2 - *(int *)p1;
}

// 快速排序，数组，升序排序
static inline int QsortCmpCharAscOrder(const void *p1, const void *p2)
{
    return *(char *)p1 - *(char *)p2;
}

// 快速排序，数组，降序排序
static inline int QsortCmpCharDescOrder(const void *p1, const void *p2)
{
    return *(char *)p2 - *(char *)p1;
}

static inline int QsortCmpStrLengthAscOrder(const void **p1, const void **p2)
{
    char *a = *(char**)p1;
    char *b = *(char**)p2;
    return ((int)strlen(a) - (int)strlen(b));
}

static inline int QsortCmpStrLengthDescOrder(const void **p1, const void **p2)
{
    char *a = *(char**)p1;
    char *b = *(char**)p2;
    return ((int)strlen(b) - (int)strlen(a));
}

#endif // ____HEMY_CODE_REPO__SRC__QSORT_COMP_ITF___H____