/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: 239. 滑动窗口最大值
 * link: https://leetcode-cn.com/problems/sliding-window-maximum/
 * 编译命令：gcc -g src/xxx.c -L /lib/libsecurec.a -I include/securec -I include/hw_cstl -o OJ.exe
 */

/*
 * 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
 * 返回滑动窗口中的最大值。
 * 进阶：你能在线性时间复杂度内解决此题吗？
*/
#include "public.h"
/*
 * 暴力解法
 * */
int* maxSlidingWindow1(int* nums, int numsSize, int k, int* returnSize)
{
    int *result = NULL;
    int max,i,j;

    if (numsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    if (k == 1) {
        *returnSize = numsSize;
        return nums;
    }

    result = (int*)malloc(sizeof(int) * numsSize);
    if (result == NULL) {
        return NULL;
    }

    (void)memset(result, 0, sizeof(int) * numsSize);

    max = 0;
    if (numsSize <= k) {
        for (i = 0; i < numsSize; i++) {
            max = GetMaxValue(max, nums[i]);
        }
        result[0] = max;
        *returnSize = 1;
        return result;
    }

    for (i = 0; i < k; i++) {
        max = GetMaxValue(max, nums[i]);
    }
    result[0] = max;
    *returnSize = numsSize - k + 1;
    for (i = 1; i < *returnSize; i++) {
        max = 0;
        for (j = 0; j < k; j++) {
            max = GetMaxValue(max, nums[j + i]);
        }
        result[i] = max;
    }

    return result;
}



/*
 * [1,3,-1,-3,5,3,6, 2, 1, 2,7]
 * 3
 * 以上面的数据为例
 * 1、numsSize <= K的情况，直接快速排序，降序，然后返回nums[0]就可以
 * 2、下标从1开始
 *
 *
 *   滑动窗口的位置                         最大值
 * ---------------                         -----
 * [1  3  -1] -3  5  3  6  2  1  2  7       3
 *  1 [3  -1  -3] 5  3  6  2  1  2  7       3
 *  1  3 [-1  -3  5] 3  6  2  1  2  7       5
 *  1  3  -1 [-3  5  3] 6  2  1  2  7       5
 *  1  3  -1  -3 [5  3  6] 2  1  2  7       6
 *  1  3  -1  -3  5 [3  6  2] 1  2  7       6
 *  1  3  -1  -3  5  3 [6  2  1] 2  7       6
 *  1  3  -1  -3  5  3  6 [2  1  2] 7       2
 *  1  3  -1  -3  5  3  6  2 [1  2  7]      7
 * 每次的滑动，都是前面少了一个值a，后面多了一个值b；
 * 我们假设以值a开始的区间，最大值为maxa；
 *
 * 那么必然有条件：
 * 1.max[a] = a，说明从a + 1到a + k - 1这 k - 1个数据，都是小于a的；
 *     - 如果b > a, 那么新的区间，b肯定是最大值
 *     - 如果b < a, 那么新的区间，我们需要重新获取最大值
 * 2.max[a] != a，那么maxa肯定是在 a + 1 到 b 这k个数字中.
 *     - 如果 b > a, 那么新的区间，最大值肯定是b
 *     - 如果 b < a, 那么新的区间，最大值肯定是a
 * 综上，我们需要做的处理是：
 * 1. 如果b > a, 新区间max[a + 1] = b;
 * 2. 否则，如果max[a] = a， 新的区间重新计算最大值
 * 3. 否则，新的区间max[a + 1] = max[a];
 */

#define MAX_NUMS_LEN 100000

int getMAX_VAL(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    int *result = NULL;
    int i;
    int tmp[MAX_NUMS_LEN] = {0};

    if (k == 1) {
        *returnSize = numsSize;
        return nums;
    }

    result = (int*)malloc(sizeof(int) * MAX_NUMS_LEN);
    (void)memset(result, 0, sizeof(int) * MAX_NUMS_LEN);
    if (numsSize <= k) {
        *returnSize = 1;
        qsort(nums, numsSize, sizeof(int), QsortCmpArrayDescOrder);
        result[0] = nums[0];
        return result;
    }

    for (i = 0; i < k; i++) {
        result[0] = getMAX_VAL(result[0], nums[i]);
    }

    *returnSize = numsSize - k + 1;
    for (i = 1; i < *returnSize; i++) {
        // printf("%d nums[%d] : %d, nums[%d] : %d, \n", i, i - 1, nums[i - 1], i, nums[i]);
        // 新加进来的值比前面的最大值还大，因为前面的排序之后最大值是result[i - 1]，所以新加进来的值就是当前区域的最大值
        if (nums[i + k - 1] >= result[i - 1]) {
            result[i] = nums[i + k - 1];
        } else if (nums[i - 1] == result[i - 1]) {
            // 上一个值就是上个区间的最大值，需要重新获取当前为起点的区间的最大值
            (void)memset(tmp, 0, sizeof(int) * MAX_NUMS_LEN);
            memcpy(tmp, &nums[i], k * sizeof(int));
            // printf("2  tmp[0] : %d, tmp[1] : %d, tmp[2] : %d\n", tmp[0], tmp[1], tmp[2]);
            qsort(tmp, k, sizeof(int), QsortCmpArrayDescOrder);
            result[i] = tmp[0];
        } else {
            // 新加进来的nums[i + k - 1]比result[i - 1]小，并且减出去的值不是上一个区间的最大值
            // 说明当前区间的最大值还在，直接赋值即可
            result[i] = result[i - 1];
        }
        // printf("3  result[%d] : %d\n", i, result[i]);
    }

    return result;
}

/*
int main()
{
    int nums[] = {7,2,4};
    int resultlen = 0;
    int *result = NULL;
    result = maxSlidingWindow(nums, 3, 2, &resultlen);

    for (int i = 0; i < resultlen; i++) {
        printf("%d ", result[i]);
    }
}*/
